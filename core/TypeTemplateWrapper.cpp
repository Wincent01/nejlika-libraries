#include "TypeTemplateWrapper.hpp"

#include "TypeTemplate.hpp"
#include "TypeTemplateError.hpp"
#include "TypeTemplateValidator.hpp"
#include "TypeTemplateInterface.hpp"

using namespace nejlika;

void nejlika::TypeTemplateWrapper::Apply(nejlika::Context &ctx)
{
    if (!ctx.templates->HasTemplate(m_Type))
    {
        throw std::runtime_error("Unknown type template: " + m_Type);
    }

    const auto& typeTemplate = ctx.templates->GetTemplate(m_Type);

    /*const auto validateError = typeTemplate->Validate(ctx, m_Value, {}, nullptr);

    if (!validateError.IsSuccess())
    {
        std::stringstream ss;

        validateError.Print(0, ss);

        throw std::runtime_error(ss.str());
    }*/

    const auto error = typeTemplate->Apply(ctx, m_Value, {}, nullptr, [] (const auto &error) {
        error.Print(0, std::cerr);
    });

    if (!error.IsSuccess())
    {
        std::stringstream ss;

        error.Print(0, ss);

        throw std::runtime_error(ss.str());
    }
}

boost::json::object nejlika::TypeTemplateWrapper::Serialize() const
{
    return m_Value;
}

void nejlika::TypeTemplateWrapper::Deserialize(const boost::json::object &json)
{
    AbstractMod::Deserialize(json);

    m_Value = json;
}
