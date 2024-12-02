#pragma once

#include <boost/json.hpp>

namespace nejlika
{

/**
 * @brief Represents an object which can be serialized and deserialized to and from JSON.
 */
class AbstractSerializable
{
public:
    /**
     * @brief Serializes the object into a JSON object.
     * 
     * @return The serialized JSON object.
     */
    virtual boost::json::object Serialize() const = 0;

    /**
     * @brief Deserializes the specified JSON object into the object.
     * 
     * @param json The JSON object to deserialize.
     */
    virtual void Deserialize(const boost::json::object& json) = 0;
};

}
