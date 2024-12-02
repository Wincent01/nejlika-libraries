#include "NiPSysResetOnLoopCtlr.hpp"

using namespace nejlika::geometry;

void NiPSysResetOnLoopCtlr::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTimeController::Read(reader, version, user, arg);

}

void NiPSysResetOnLoopCtlr::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTimeController::Write(writer, version, user, arg);

}
