#pragma once

#include "TypeTemplate.hpp"
#include "TypeTemplateValue.hpp"
#include "TypeTemplateError.hpp"

namespace nejlika
{

class TypeTemplateParameter;
class TypeTemplateScope;
class TypeTemplateContext;
class TypeTemplateInterface;

/**
 * @brief A type template validator. Used to validate json based on a type template.
 */
class TypeTemplateValidator
{
public:
    TypeTemplateValidator();

    TypeTemplateError ValidateParameter(
        const std::shared_ptr<TypeTemplateParameter>& parameter,
        const std::string& key,
        const std::shared_ptr<TypeTemplateScope>& object
    ) const;

    TypeTemplateError ValidateType(
        const std::shared_ptr<TypeTemplateScope>& parent,
        const std::shared_ptr<TypeTemplateParameter>& parameter,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters,
        const boost::json::value& value
    ) const;

    // Type validators

    TypeTemplateError ValidateString(
        const boost::json::value& value
    ) const;

    TypeTemplateError ValidateNumber(
        const boost::json::value& value
    ) const;

    TypeTemplateError ValidateInteger(
        const boost::json::value& value
    ) const;

    TypeTemplateError ValidateBoolean(
        const boost::json::value& value
    ) const;

    TypeTemplateError ValidateObject(
        const std::shared_ptr<TypeTemplateScope>& parent,
        const std::shared_ptr<TypeTemplateParameter>& parameter,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters,
        const boost::json::value& value
    ) const;

    TypeTemplateError ValidateArray(
        const std::shared_ptr<TypeTemplateScope>& parent,
        const std::shared_ptr<TypeTemplateParameter>& parameter,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters,
        const boost::json::value& value
    ) const;

    TypeTemplateError ValidateEnum(
        const std::shared_ptr<TypeTemplateScope>& parent,
        const std::shared_ptr<TypeTemplateParameter>& parameter,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters,
        const boost::json::value& value
    ) const;

    TypeTemplateError ValidateId(
        const std::shared_ptr<TypeTemplateScope>& parent,
        const std::shared_ptr<TypeTemplateParameter>& parameter,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters,
        const boost::json::value& value,
        bool lax = false,
        bool any = false
    ) const;

    TypeTemplateError ValidateLocale(
        const boost::json::value& value
    ) const;

    TypeTemplateError ValidateResource(
        const std::shared_ptr<TypeTemplateScope>& parent,
        const std::shared_ptr<TypeTemplateParameter>& parameter,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters,
        const boost::json::value& value
    ) const;

    std::unordered_set<std::string> FindDependencies(
        const std::unique_ptr<TypeTemplateInterface>& interface,
        const std::shared_ptr<TypeTemplateParameter>& parameter,
        const boost::json::value& value,
        std::unordered_set<name>& nestedInstances
    ) const;

    void FindDependenciesRecursive(
        const std::unique_ptr<TypeTemplateInterface>& interface,
        const std::shared_ptr<TypeTemplateParameter>& parameter,
        const boost::json::value& value,
        std::unordered_set<std::string>& dependencies,
        std::unordered_set<std::string>& nestedInstances
    ) const;

    // Helper
    static const char* JsonTypeToString(
        const boost::json::value& value
    );

};

}