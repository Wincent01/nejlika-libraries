#pragma once

#include <boost/json.hpp>
#include <vector>
#include <string>
#include <memory>

#include "AbstractSerializable.hpp"

namespace nejlika
{

class TypeTemplateAction : public AbstractSerializable
{
public:
    TypeTemplateAction() = default;

    boost::json::object Serialize() const override;

    void Deserialize(const boost::json::object& json) override;

    /**
     * @brief Get the name of the action.
     * 
     * @return The name of the action.
     */
    const std::string& GetName() const;

    /**
     * @brief Get the description of the action.
     * 
     * @return The description of the action.
     */
    const std::string& GetDescription() const;

    /**
     * @brief Get the list of operations to be executed before applying the action.
     * 
     * @return The list of operations to be executed before applying the action.
     * @note The operations are executed in the order they are listed.
     */
    const std::vector<boost::json::object>& GetPrepareOperations() const;

    /**
     * @brief Get the list of operations to be executed during applying the action.
     * 
     * @return The list of operations to be executed during applying the action.
     * @note The operations are executed in the order they are listed.
     */
    const std::vector<boost::json::object>& GetApplyOperations() const;

    static std::vector<std::shared_ptr<TypeTemplateAction>> DeserializeActions(const boost::json::value& json);

private:
    std::string m_Name;
    std::string m_Description;
    std::vector<boost::json::object> m_PrepareOperations;
    std::vector<boost::json::object> m_ApplyOperations;

};

}
