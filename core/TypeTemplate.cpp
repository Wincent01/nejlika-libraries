#include "TypeTemplate.hpp"

#include "TypeTemplateValidator.hpp"
#include "TypeTemplateScope.hpp"
#include "TypeTemplateContext.hpp"
#include "Mods.hpp"
#include "Lookup.hpp"
#include "TypeTemplateApplier.hpp"
#include "TypeTemplateInterface.hpp"

#include <memory>
#include <fstream>

using namespace nejlika;

boost::json::object nejlika::TypeTemplate::Serialize() const
{
    return m_Serialized;
}

void nejlika::TypeTemplate::Deserialize(const boost::json::object &json)
{
    m_Serialized = json;

    if (!json.contains("name"))
    {
        throw std::runtime_error("TypeTemplate::Deserialize: Missing 'name' field.");
    }
    
    const auto& name = json.at("name");

    if (!name.is_string())
    {
        throw std::runtime_error("TypeTemplate::Deserialize: 'name' field is not a string.");
    }

    m_Name = name.as_string().c_str();

    if (!json.contains("parameters"))
    {
        throw std::runtime_error("TypeTemplate::Deserialize: Missing 'parameters' field.");
    }

    const auto& parameters = json.at("parameters");

    m_Parameters = TypeTemplateParameter::DeserializeParameters(parameters);

    if (!json.contains("variables"))
    {
        throw std::runtime_error("TypeTemplate::Deserialize: Missing 'variables' field.");
    }

    const auto& variables = json.at("variables");

    m_Variables = TypeTemplateParameter::DeserializeParameters(variables);

    if (json.contains("actions"))
    {
        const auto& actions = TypeTemplateAction::DeserializeActions(json.at("actions"));

        for (const auto& action : actions)
        {
            m_Actions.emplace(action->GetName(), action);
        }
    }
}

const name& nejlika::TypeTemplate::GetName() const
{
    return m_Name;
}

TypeTemplateError nejlika::TypeTemplate::Apply(
    nejlika::Context &ctx,
    const boost::json::object &json,
    const std::unordered_map<std::string, TypeTemplateValue> &parameters,
    const std::shared_ptr<TypeTemplateContext>& parent,
    const std::function<void(const TypeTemplateError&)>& onFinished) const
{
    std::shared_ptr<TypeTemplateContext> context;
    std::shared_ptr<TypeTemplateScope> parameterScope;
    std::shared_ptr<TypeTemplateScope> variableScope;

    const auto error = CreateContext(
        ctx,
        json,
        parameters,
        parent,
        context,
        parameterScope,
        variableScope
    );

    if (!error.IsSuccess())
    {
        return error;
    }

    if (!error.IsSuccess())
    {
        std::stringstream ss;

        ss << "Failed to apply template '" << m_Name << "': ";

        error.Print(0, ss);

        throw std::runtime_error(ss.str());
    }

    return ctx.templates->GetApplier().Apply(
        context,
        json,
        *this,
        parameters,
        onFinished
    );
}

TypeTemplateError nejlika::TypeTemplate::Prepare(
    nejlika::Context &ctx,
    const boost::json::object &json,
    const std::unordered_map<std::string,
    TypeTemplateValue> &parameters,
    const std::shared_ptr<TypeTemplateContext> &parent) const
{
    std::shared_ptr<TypeTemplateContext> context;
    std::shared_ptr<TypeTemplateScope> parameterScope;
    std::shared_ptr<TypeTemplateScope> variableScope;

    const auto error = CreateContext(
        ctx,
        json,
        parameters,
        parent,
        context,
        parameterScope,
        variableScope
    );

    if (!error.IsSuccess())
    {
        return error;
    }
    
    const auto& actions = GetActions();

    if (actions.empty())
    {
        return TypeTemplateError::Success;
    }
    
    std::string actionName = actions.begin()->first;

    if (json.contains("action"))
    {
        actionName = json.at("action").as_string().c_str();
    }
    
    const auto& prepareOperations = GetActions().at(actionName)->GetPrepareOperations();

    for (const auto& prepareAction : prepareOperations)
    {
        const auto error = ctx.templates->GetApplier().ApplyOperation(
            context,
            prepareAction,
            json,
            *this,
            parameters
        );

        if (!error.IsSuccess())
        {
            return error;
        }
    }

    return TypeTemplateError::Success;
}

std::unordered_set<name> nejlika::TypeTemplate::GetDependencies(
    const std::unique_ptr<TypeTemplateInterface>& interface,
    const boost::json::object &json,
    std::unordered_set<name>& nestedInstances
) const
{
    std::unordered_set<name> dependencies;

    for (const auto& parameter : m_Variables)
    {
        if (!json.contains(parameter->GetName()))
        {
            continue;
        }

        const auto& jsonValue = json.at(parameter->GetName());

        const auto& variableDependencies = interface->GetValidator().FindDependencies(
            interface,
            parameter,
            jsonValue,
            nestedInstances
        );

        dependencies.insert(variableDependencies.begin(), variableDependencies.end());
    }

    // Erase nested instances from dependencies
    for (const auto& nestedInstance : nestedInstances)
    {
        dependencies.erase(nestedInstance);
    }

    return dependencies;
}

std::unordered_set<name> nejlika::TypeTemplate::GetDependencies(const std::unique_ptr<TypeTemplateInterface>& interface, const boost::json::object &json) const
{
    std::unordered_set<name> nestedInstances;

    return GetDependencies(interface, json, nestedInstances);
}

const std::unordered_map<std::string, std::shared_ptr<TypeTemplateAction>> &nejlika::TypeTemplate::GetActions() const
{
    return m_Actions;
}

std::shared_ptr<TypeTemplateContext> nejlika::TypeTemplate::CreateContext(nejlika::Context &ctx, const boost::json::object &json) const
{
    std::shared_ptr<TypeTemplateContext> context;
    std::shared_ptr<TypeTemplateScope> parameterScope;
    std::shared_ptr<TypeTemplateScope> variableScope;

    const auto error = CreateContext(
        ctx,
        json,
        {},
        nullptr,
        context,
        parameterScope,
        variableScope
    );

    if (!error.IsSuccess())
    {
        std::stringstream ss;

        ss << "Failed to create context for template '" << m_Name << "': ";

        error.Print(0, ss);

        throw std::runtime_error(ss.str());
    }

    return context;
}

TypeTemplateError nejlika::TypeTemplate::CreateContext(
    nejlika::Context &ctx,
    const boost::json::object &json,
    const std::unordered_map<std::string, TypeTemplateValue> &parameters,
    const std::shared_ptr<TypeTemplateContext> &parent,
    std::shared_ptr<TypeTemplateContext> &context,
    std::shared_ptr<TypeTemplateScope> &parameterScope,
    std::shared_ptr<TypeTemplateScope> &variableScope) const
{
    if (!json.contains("name"))
    {
        return TypeTemplateError("Missing 'name' field.");
    }

    if (!json.at("name").is_string())
    {
        return TypeTemplateError("'name' field is not a string.");
    }

    const std::string name = json.at("name").as_string().c_str();

    if (name.find(':') == std::string::npos)
    {
        return TypeTemplateError("Name does not contain a namespace delimiter ':'.");
    }

    const std::string namespaceName = name.substr(0, name.find(':'));

    if (!ctx.mods->HasModPack(namespaceName) && namespaceName != Lookup::core_prefix)
    {
        std::stringstream ss;

        ss << "Namespace '" << namespaceName << "' does not exist.";

        return TypeTemplateError(ss.str());
    }

    context = std::make_shared<TypeTemplateContext>(
        parent,
        &ctx
    );

    context->SetVariable("namespace", boost::json::value(namespaceName));

    boost::json::object parameterObject;

    for (const auto& [key, value] : parameters)
    {
        parameterObject.emplace(key, value.GetValue());
    }

    parameterScope = std::make_shared<TypeTemplateScope>(TypeTemplateScope(
        context,
        std::make_shared<TypeTemplateParameter>(TypeTemplateParameter("parameters", m_Parameters)),
        nullptr,
        {},
        parameterObject
    ));

    variableScope = std::make_shared<TypeTemplateScope>(TypeTemplateScope(
        context,
        std::make_shared<TypeTemplateParameter>(TypeTemplateParameter("variables", m_Variables)),
        nullptr,
        {},
        json
    ));

    context->SetParameter("parameters", parameterScope);
    context->SetParameter("variables", variableScope);

    return TypeTemplateError::Success;
}

TypeTemplateError nejlika::TypeTemplate::Validate(
    nejlika::Context& ctx,
    const boost::json::object &json,
    const std::unordered_map<std::string, TypeTemplateValue>& parameters,
    const std::shared_ptr<TypeTemplateContext>& parent
) const
{
    std::shared_ptr<TypeTemplateContext> context;
    std::shared_ptr<TypeTemplateScope> parameterScope;
    std::shared_ptr<TypeTemplateScope> variableScope;

    const auto error = CreateContext(
        ctx,
        json,
        parameters,
        parent,
        context,
        parameterScope,
        variableScope
    );

    if (!error.IsSuccess())
    {
        return error;
    }

    std::vector<TypeTemplateError> errors;

    for (const auto& parameter : m_Parameters)
    {
        const auto& error = ctx.templates->GetValidator().ValidateParameter(
            parameter,
            parameter->GetName(),
            parameterScope
        );

        if (!error.IsSuccess())
        {
            errors.push_back(error);
        }
    }

    for (const auto& variable : m_Variables)
    {
        const auto& error = ctx.templates->GetValidator().ValidateParameter(
            variable,
            variable->GetName(),
            variableScope
        );

        if (!error.IsSuccess())
        {
            errors.push_back(error);
        }
    }
    
    if (!errors.empty())
    {
        return TypeTemplateError("Errors validating:", errors);
    }

    return TypeTemplateError::Success;
}
