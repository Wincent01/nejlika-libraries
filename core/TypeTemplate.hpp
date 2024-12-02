#pragma once

#include "nejlika.hpp"
#include "AbstractMod.hpp"
#include "TypeTemplateError.hpp"
#include "TypeTemplateParameter.hpp"
#include "TypeTemplateAction.hpp"

#include <unordered_set>
#include <filesystem>

namespace nejlika
{

class TypeTemplateContext;
class TypeTemplateScope;
class ModPack;

/**
 * @brief A type template.
 * 
 * This is a dynamic way to define a mod type; how to input data and apply it to the game.
 */
class TypeTemplate : public AbstractSerializable, public std::enable_shared_from_this<TypeTemplate>
{
public:
    boost::json::object Serialize() const override;

    void Deserialize(const boost::json::object& json) override;

    /**
     * @brief Get the name of this type template.
     * 
     * @return The name of this type template.
     */
    const name& GetName() const;

    /**
     * @brief Attempt to parse a json object into this type template.
     * 
     * @param json The json object to parse.
     * @return Error details if the json object contains any error.
     * @note Check TypeTemplateError::IsSuccess to see if the parsing was successful.
     */
    TypeTemplateError Validate(
        nejlika::Context& ctx,
        const boost::json::object& json,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters,
        const std::shared_ptr<TypeTemplateContext>& parent
    ) const;

    /**
     * @brief Apply a json object by the rules of this type template.
     * 
     * @param ctx The context to apply the json object to.
     * @param json The json object to apply.
     * @param parameters The parameters to pass to this instance.
     * @param parent The parent context. (nullable)
     * @param onFinished The callback to call when the application is finished. May not be called if an error is returned immediately.
     * 
     * @return Error details if the json object contains any error.
     * @throw If any errors occur during the application. If the object has been validated before applying, this should not happen.
     * 
     * @note Use TypeTemplate::Validate to check for errors before applying.
     */
    TypeTemplateError Apply(
        nejlika::Context& ctx,
        const boost::json::object& json,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters,
        const std::shared_ptr<TypeTemplateContext>& parent,
        const std::function<void(const TypeTemplateError&)>& onFinished
    ) const;

    /**
     * @brief Apply the prepare operations of this type template to a json object.
     * 
     * @param ctx The context to apply the json object to.
     * @param json The json object to apply.
     * @param parameters The parameters to pass to this instance.
     * @param parent The parent context. (nullable)
     * 
     * @return Error details if the json object contains any error.
     * @throw If any errors occur during the application. If the object has been validated before applying, this should not happen.
     * 
     * @note Use TypeTemplate::Validate to check for errors before applying.
     */
    TypeTemplateError Prepare(
        nejlika::Context& ctx,
        const boost::json::object& json,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters,
        const std::shared_ptr<TypeTemplateContext>& parent
    ) const;

    /**
     * @brief Get all dependencies of an object by the rules of this type template.
     * 
     * @param json The json object to get the dependencies of.
     * @param nestedInstances The set of nested instances found.
     * @return A vector of dependencies.
     * 
     * @throw If the json object contains any error.
     * 
     * @note Dependencies are symbols that are referenced by the given object.
     */
    std::unordered_set<name> GetDependencies(
        const std::unique_ptr<TypeTemplateInterface>& interface,
        const boost::json::object& json,
        std::unordered_set<name>& nestedInstances
    ) const;

    /**
     * @brief Get all dependencies of an object by the rules of this type template.
     * 
     * @param json The json object to get the dependencies of.
     * @return A vector of dependencies.
     * 
     * @throw If the json object contains any error.
     * 
     * @note Dependencies are symbols that are referenced by the given object.
     */
    std::unordered_set<name> GetDependencies(const std::unique_ptr<TypeTemplateInterface>& interface, const boost::json::object& json) const;

    /**
     * @brief Get the actions of this type template.
     * 
     * @return The actions of this type template.
     */
    const std::unordered_map<std::string, std::shared_ptr<TypeTemplateAction>>& GetActions() const;

    /**
     * @brief Create a context which can be used to query the variables of an instance of this type template.
     * 
     * @param ctx The context to create the context in.
     * @param json The json object to create the context for.
     * 
     * @return The created context.
     */
    std::shared_ptr<TypeTemplateContext> CreateContext(
        nejlika::Context& ctx,
        const boost::json::object &json
    ) const;

private:
    TypeTemplateError CreateContext(
        nejlika::Context& ctx,
        const boost::json::object &json,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters,
        const std::shared_ptr<TypeTemplateContext>& parent,
        std::shared_ptr<TypeTemplateContext>& out,
        std::shared_ptr<TypeTemplateScope>& parameterScope,
        std::shared_ptr<TypeTemplateScope>& variableScope
    ) const;

    boost::json::object m_Serialized;

    name m_Name;

    std::vector<std::shared_ptr<TypeTemplateParameter>> m_Parameters;
    std::vector<std::shared_ptr<TypeTemplateParameter>> m_Variables;
    std::unordered_map<std::string, std::shared_ptr<TypeTemplateAction>> m_Actions;
};

}
