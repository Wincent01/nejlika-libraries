#include "NiPSysModifierBoolCtlr.hpp"

using namespace nejlika::geometry;

void NiPSysModifierBoolCtlr::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysModifierCtlr::Read(reader, version, user, arg);

}

void NiPSysModifierBoolCtlr::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysModifierCtlr::Write(writer, version, user, arg);

}
