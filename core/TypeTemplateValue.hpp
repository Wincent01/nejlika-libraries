#pragma once

#include <boost/json.hpp>

#include "AbstractSerializable.hpp"

namespace nejlika
{

/**
 * @brief A type template value, wrapper around a json value.
 */
class TypeTemplateValue
{
public:
    TypeTemplateValue() = default;

    /**
     * @brief Construct a new TypeTemplateValue object.
     * 
     * @param value The json value.
     */
    TypeTemplateValue(const boost::json::value& value);

    /**
     * @brief Get the json value.
     * 
     * @return The json value.
     */
    const boost::json::value& GetValue() const;

    /**
     * @brief Set the json value.
     * 
     * @param value The json value.
     */
    void SetValue(const boost::json::value& value);

private:
    boost::json::value m_Value;
};

}
