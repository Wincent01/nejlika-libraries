#include "BSPSysMultiTargetEmitterCtlr.hpp"

using namespace nejlika::geometry;

void BSPSysMultiTargetEmitterCtlr::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysModifierCtlr::Read(reader, version, user, arg);

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_Data.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_VisibilityInterpolator.Read(reader, version, user, 0);
    }

    m_UnknownShort1 = reader.Read<short>();

    m_UnknownInt1 = reader.Read<int>();

}

void BSPSysMultiTargetEmitterCtlr::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysModifierCtlr::Write(writer, version, user, arg);

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_Data.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_VisibilityInterpolator.Write(writer, version, user, 0);
    }

    writer.Write(m_UnknownShort1);

    writer.Write(m_UnknownInt1);

}