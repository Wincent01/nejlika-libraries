#pragma once

#include <boost/json.hpp>
#include <unordered_map>
#include <vector>
#include <string>
#include <memory>
#include <unordered_set>

#include "TypeTemplateValue.hpp"
#include "AbstractSerializable.hpp"

namespace nejlika
{

/**
 * @brief A type template parameter.
 */
class TypeTemplateParameter : public AbstractSerializable
{
public:
    /**
     * @brief Construct a new TypeTemplateParameter object.
     */
    TypeTemplateParameter();

    /**
     * @brief Construct a new TypeTemplateParameter object, as an object type.
     * 
     * @param name The name of the parameter.
     * @param objectProperties The properties of the object.
     */
    TypeTemplateParameter(const std::string& name, const std::vector<std::shared_ptr<TypeTemplateParameter>>& objectProperties);

    /**
     * @brief Get the name of the parameter.
     * 
     * @return The name of the parameter.
     */
    const std::string& GetName() const;

    /**
     * @brief Get the description of the parameter.
     * 
     * @return The description of the parameter.
     */
    const std::string& GetDescription() const;

    /**
     * @brief Get the type name of the parameter.
     * 
     * @return The type name of the parameter.
     */
    const std::string& GetType() const;

    /**
     * @brief Get whether the parameter is required.
     * 
     * @return Whether the parameter is required.
     */
    bool IsRequired() const;

    /**
     * @brief Get whether the parameter is nullable.
     * 
     * @return Whether the parameter is nullable.
     */
    bool IsNullable() const;

    /**
     * @brief Get the default value of the parameter.
     * 
     * @return The default value of the parameter.
     */
    const boost::json::value& GetDefaultValue() const;

    /**
     * @brief Get whether the parameter has a default value.
     * 
     * @return Whether the parameter has a default value.
     * @note If this is false, the default value is null.
     */
    bool HasDefault() const;

    /**
     * @brief Get the arguments to pass to the type of the parameter.
     * 
     * @return The arguments to pass to the type of the parameter.
     */
    const std::unordered_map<std::string, TypeTemplateValue>& GetTypeArguments() const;

    /**
     * @brief Get the aliases of the parameter.
     * 
     * @return The aliases of the parameter.
     */
    const std::vector<std::string>& GetAliases() const;

    /**
     * @brief Get the type of the array elements.
     * 
     * @return The type of the array elements.
     */
    const std::shared_ptr<TypeTemplateParameter>& GetArrayType() const;

    /**
     * @brief Get the properties of the object.
     * 
     * @return The properties of the object.
     */
    const std::vector<std::shared_ptr<TypeTemplateParameter>>& GetObjectProperties() const;

    /**
     * @brief Get an object property by name.
     * 
     * @param name The name of the property.
     * @throw If the property is not found.
     */
    const std::shared_ptr<TypeTemplateParameter>& FindObjectProperty(const std::string& name) const;

    /**
     * @brief Check fi an object property exists by name.
     * 
     * @param name The name of the property.
     * @return If the property exists.
     */
    bool HasObjectProperty(const std::string& name) const;

    /**
     * @brief Get the values of the enum.
     * 
     * @return The values of the enum.
     */
    const std::unordered_map<std::string, TypeTemplateValue>& GetEnumValues() const;

    /**
     * @brief Get the valid types that the id can reference.
     * 
     * @return The valid types that the id can reference.
     * @note An empty set means that the id can reference any type.
     */
    const std::unordered_set<std::string>& GetIdTypes() const;

    /**
     * @brief Serializes the object into a JSON object.
     * 
     * @return The serialized JSON object.
     */
    boost::json::object Serialize() const override;

    /**
     * @brief Deserializes the specified JSON object into the object.
     * 
     * @param json The JSON object to deserialize.
     */
    void Deserialize(const boost::json::object& json) override;

    /**
     * @brief Deserialize a set of parameters from a JSON value (object or array).
     * 
     * @param json The JSON value to deserialize.
     * 
     * @return The deserialized parameters.
     * @throw std::runtime_error If the JSON value is not an object or array.
     */
    static std::vector<std::shared_ptr<TypeTemplateParameter>> DeserializeParameters(const boost::json::value& json);

private:
    std::string name;
    std::string description;
    std::string type;
    bool required;
    bool nullable;
    boost::json::value defaultValue;
    bool hasDefault;
    std::unordered_map<std::string, TypeTemplateValue> typeArguments;
    std::vector<std::string> aliases;

    std::shared_ptr<TypeTemplateParameter> arrayType;
    std::vector<std::shared_ptr<TypeTemplateParameter>> objectProperties;
    std::unordered_map<std::string, TypeTemplateValue> enumValues;
    std::unordered_set<std::string> idTypes;
};

}