#include "NiPSysModifierFloatCtlr.hpp"

using namespace nejlika::geometry;

void NiPSysModifierFloatCtlr::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysModifierCtlr::Read(reader, version, user, arg);

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_Data.Read(reader, version, user, 0);
    }

}

void NiPSysModifierFloatCtlr::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysModifierCtlr::Write(writer, version, user, arg);

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_Data.Write(writer, version, user, 0);
    }

}
