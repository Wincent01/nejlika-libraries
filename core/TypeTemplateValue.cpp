#include "TypeTemplateValue.hpp"

using namespace nejlika;

nejlika::TypeTemplateValue::TypeTemplateValue(const boost::json::value & value)
{
    m_Value = value;   
}

const boost::json::value& nejlika::TypeTemplateValue::GetValue() const
{
    return m_Value;
}

void nejlika::TypeTemplateValue::SetValue(const boost::json::value & value)
{
    m_Value = value;
}