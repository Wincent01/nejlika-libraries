#include "TypeTemplateError.hpp"

using namespace nejlika;

const TypeTemplateError TypeTemplateError::Success = TypeTemplateError("");

nejlika::TypeTemplateError::TypeTemplateError(const std::string& message)
{
    m_Message = message;
}

nejlika::TypeTemplateError::TypeTemplateError(const std::string &message, const std::vector<TypeTemplateError> &errors)
{
    m_Message = message;
    m_Chilren = errors;
}

nejlika::TypeTemplateError::TypeTemplateError(const std::string &message, const TypeTemplateError &error)
{
    m_Message = message;
    m_Chilren.push_back(error);
}

void nejlika::TypeTemplateError::AddChildError(const TypeTemplateError &error)
{
    m_Chilren.push_back(error);
}

void nejlika::TypeTemplateError::AddChildErrors(const std::vector<TypeTemplateError> &errors)
{
    for (const auto& error : errors)
    {
        m_Chilren.push_back(error);
    }
}

const std::string& nejlika::TypeTemplateError::GetMessage() const
{
    return m_Message;
}

const std::vector<TypeTemplateError>& nejlika::TypeTemplateError::GetChildErrors() const
{
    return m_Chilren;
}

void nejlika::TypeTemplateError::Print(int32_t indent, std::ostream& output) const
{
    if (m_Message.empty())
    {
        return;
    }

    for (int32_t i = 0; i < indent; i++)
    {
        output << "  ";
    }

    output << m_Message << std::endl;

    for (const auto& child : m_Chilren)
    {
        child.Print(indent + 1, output);
    }
}

bool nejlika::TypeTemplateError::IsSuccess() const
{
    return m_Message.empty();
}
