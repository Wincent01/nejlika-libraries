#include "NiPSysModifierCtlr.hpp"

using namespace nejlika::geometry;

void NiPSysModifierCtlr::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiSingleInterpController::Read(reader, version, user, arg);

    m_ModifierName.Read(reader, version, user, 0);

}

void NiPSysModifierCtlr::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiSingleInterpController::Write(writer, version, user, arg);

    m_ModifierName.Write(writer, version, user, 0);

}
