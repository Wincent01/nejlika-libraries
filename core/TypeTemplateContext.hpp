#pragma once

#include <memory>

#include <boost/json.hpp>

#include "TypeTemplateValue.hpp"
#include "nejlika.hpp"
#include "TypeTemplateQueryOptions.hpp"

namespace nejlika
{
class TypeTemplateScope;

/**
 * @brief A context for a type template.
 * 
 * Passed around when validating and applying type templates.
 * 
 * Allows retrival of variables, parameters and the nejlika context.
 */
class TypeTemplateContext : public std::enable_shared_from_this<TypeTemplateContext>
{
public:
    /**
     * @brief Construct a new TypeTemplateContext object.
     * 
     * @param parent The parent context.
     * @param ctx The nejlika context to use.
     */
    TypeTemplateContext(const std::shared_ptr<TypeTemplateContext>& parent, nejlika::Context* ctx);
    
    /**
     * @brief Get the value of a variable.
     * 
     * @param key The key of the variable.
     * @return The value of the variable.
     * @throws If the variable is not found.
     */
    const boost::json::value& GetVariable(const std::string& key) const;

    /**
     * @brief Set the value of a variable.
     * 
     * @param key The key of the variable.
     * @param value The value of the variable.
     */
    void SetVariable(const std::string& key, const boost::json::value& value);

    /**
     * @brief Check if a variable exists.
     * 
     * @param key The key of the variable.
     * @return Whether the variable exists.
     */
    bool HasVariable(const std::string& key) const;

    /**
     * @brief Get a parameter.
     * 
     * @param key The key of the parameter.
     * @return The parameter.
     * @throws If the parameter is not found.
     */
    const std::shared_ptr<TypeTemplateScope>& GetParameter(const std::string& key) const;

    /**
     * @brief Set a parameter.
     * 
     * @param key The key of the parameter.
     * @param value The value of the parameter.
     */
    void SetParameter(const std::string& key, const std::shared_ptr<TypeTemplateScope>& value);

    /**
     * @brief Get the parent context.
     * 
     * @return The parent context, or nullptr if there is no parent.
     */
    const std::shared_ptr<TypeTemplateContext>& GetParent() const;

    /**
     * @brief Find a value in the context.
     * 
     * @param value The value to find.
     * @return The found value.
     */
    boost::json::value FindValue(const TypeTemplateValue& value, TypeTemplateQueryOptions options);
    
    /**
     * @brief Find a value in the context.
     * 
     * @param path The path to the value.
     * @param cascade Whether to start the application of child type instances.
     * @return The found value.
     */
    boost::json::value FindValue(std::vector<std::string> parts, TypeTemplateQueryOptions options);

    /**
     * @brief Get the nejlika context.
     * 
     * @return The nejlika context.
     */
    nejlika::Context& GetContext() const;

private:

    std::shared_ptr<TypeTemplateContext> m_Parent;
    std::unordered_map<std::string, boost::json::value> m_Variables;
    std::unordered_map<std::string, std::shared_ptr<TypeTemplateScope>> m_Parameters;
    nejlika::Context* m_Context;

};

}