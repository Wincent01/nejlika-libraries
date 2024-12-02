#pragma once

#include "TypeTemplate.hpp"
#include "TypeTemplateValue.hpp"
#include "TypeTemplateError.hpp"

class CppSQLite3Statement;

namespace nejlika
{

class TypeTemplateParameter;
class TypeTemplateScope;
class TypeTemplateContext;

typedef std::function<TypeTemplateError(
    const std::shared_ptr<TypeTemplateContext>& context,
    const boost::json::object& operation,
    const boost::json::object& json,
    const TypeTemplate& typeTemplate,
    const std::unordered_map<std::string, TypeTemplateValue>& parameters
)> ApplyExtentionFunction;

class TypeTemplateApplier
{
public:
    TypeTemplateApplier();

    TypeTemplateError Apply(
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters,
        const std::function<void(const TypeTemplateError&)>& onFinished
    ) const;

    TypeTemplateError ApplyOperation(
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) const;

    TypeTemplateError ApplyGenerateOperation(
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) const;

    TypeTemplateError ApplyInsertOperation(
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) const;

    TypeTemplateError ApplyUpdateOperation(
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) const;

    TypeTemplateError ApplyDeleteOperation(
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) const;

    TypeTemplateError ApplySelectOperation(
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) const;

    TypeTemplateError ApplyForEachOperation(
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) const;

    TypeTemplateError ApplyLocaleOperation(
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) const;
    
    TypeTemplateError ApplyCascadeOperation(
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) const;

    TypeTemplateError ApplyAssignOperation(
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) const;

    TypeTemplateError ApplyConcatOperation(
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) const;

    TypeTemplateError ApplyPopOperation(
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) const;

    TypeTemplateError ApplySQLOperation(
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) const;

    TypeTemplateError ApplyFileCopyOperation(
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) const;
    
    TypeTemplateError ApplyDirectoryCopyOperation(
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) const;

    void RegisterExtentionFunction(
        const std::string& name,
        const ApplyExtentionFunction& function
    );

    void BindValue(
        CppSQLite3Statement& statement,
        int32_t index,
        const boost::json::value& value,
        const boost::json::object& extra = boost::json::object()
    ) const;

    std::string ValueToString(
        const boost::json::value& value
    ) const;

    bool TryResolveName(
        nejlika::Context& ctx,
        const boost::json::object& json,
        nejlika::id& result
    ) const;

    bool GenerateIdsRecursive(
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& json
    ) const;

private:
    std::unordered_map<std::string, ApplyExtentionFunction> m_ExtentionFunctions;

};

}
