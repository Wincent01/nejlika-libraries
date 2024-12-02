#include "BSPSysScaleModifier.hpp"

using namespace nejlika::geometry;

void BSPSysScaleModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysModifier::Read(reader, version, user, arg);

    m_NumFloats = reader.Read<uint>();

    m_Floats.resize(m_NumFloats);
    for (uint32_t i = 0; i < m_Floats.size(); i++)
    {
        m_Floats[i] = reader.Read<float>();
    }

}

void BSPSysScaleModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysModifier::Write(writer, version, user, arg);

    writer.Write(m_NumFloats);

    for (uint32_t i = 0; i < m_Floats.size(); i++)
    {
        writer.Write(m_Floats[i]);
    }

}
