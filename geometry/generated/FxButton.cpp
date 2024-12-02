#include "FxButton.hpp"

using namespace nejlika::geometry;

void FxButton::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    FxWidget::Read(reader, version, user, arg);

}

void FxButton::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    FxWidget::Write(writer, version, user, arg);

}
