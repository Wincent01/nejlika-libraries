#include "NiPSysAirFieldSpreadCtlr.hpp"

using namespace nejlika::geometry;

void NiPSysAirFieldSpreadCtlr::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysModifierFloatCtlr::Read(reader, version, user, arg);

}

void NiPSysAirFieldSpreadCtlr::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysModifierFloatCtlr::Write(writer, version, user, arg);

}
