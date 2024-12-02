#include "BSNiAlphaPropertyTestRefController.hpp"

using namespace nejlika::geometry;

void BSNiAlphaPropertyTestRefController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiAlphaController::Read(reader, version, user, arg);

}

void BSNiAlphaPropertyTestRefController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiAlphaController::Write(writer, version, user, arg);

}
