#include "NiPSysGrowFadeModifier.hpp"

using namespace nejlika::geometry;

void NiPSysGrowFadeModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysModifier::Read(reader, version, user, arg);

    m_GrowTime = reader.Read<float>();

    m_GrowGeneration = reader.Read<ushort>();

    m_FadeTime = reader.Read<float>();

    m_FadeGeneration = reader.Read<ushort>();

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && user == 11)
    {
        m_BaseScale = reader.Read<float>();
    }

}

void NiPSysGrowFadeModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysModifier::Write(writer, version, user, arg);

    writer.Write(m_GrowTime);

    writer.Write(m_GrowGeneration);

    writer.Write(m_FadeTime);

    writer.Write(m_FadeGeneration);

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && user == 11)
    {
        writer.Write(m_BaseScale);
    }

}
