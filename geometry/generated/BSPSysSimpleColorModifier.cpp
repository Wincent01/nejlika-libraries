#include "BSPSysSimpleColorModifier.hpp"

using namespace nejlika::geometry;

void BSPSysSimpleColorModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysModifier::Read(reader, version, user, arg);

    m_FadeInPercent = reader.Read<float>();

    m_FadeOutPercent = reader.Read<float>();

    m_Color1EndPercent = reader.Read<float>();

    m_Color1StartPercent = reader.Read<float>();

    m_Color2EndPercent = reader.Read<float>();

    m_Color2StartPercent = reader.Read<float>();

    m_Colors.resize(3);
    for (uint32_t i = 0; i < m_Colors.size(); i++)
    {
        m_Colors[i].Read(reader, version, user, 0);
    }

}

void BSPSysSimpleColorModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysModifier::Write(writer, version, user, arg);

    writer.Write(m_FadeInPercent);

    writer.Write(m_FadeOutPercent);

    writer.Write(m_Color1EndPercent);

    writer.Write(m_Color1StartPercent);

    writer.Write(m_Color2EndPercent);

    writer.Write(m_Color2StartPercent);

    for (uint32_t i = 0; i < m_Colors.size(); i++)
    {
        m_Colors[i].Write(writer, version, user, 0);
    }

}
