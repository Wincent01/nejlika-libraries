#pragma once

#include <filesystem>
#include <map>

#include "AbstractMod.hpp"

namespace nejlika
{

/**
 * @brief A wrapper for a type template associated with a json value.
 */
class TypeTemplateWrapper : public AbstractMod
{
public:
    void Apply(nejlika::Context& ctx) override;

    boost::json::object Serialize() const override;

    void Deserialize(const boost::json::object& json) override;

private:
    boost::json::object m_Value;

};

}
