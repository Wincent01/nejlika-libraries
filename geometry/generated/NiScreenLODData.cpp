#include "NiScreenLODData.hpp"

using namespace nejlika::geometry;

void NiScreenLODData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiLODData::Read(reader, version, user, arg);

    m_BoundCenter.Read(reader, version, user, 0);

    m_BoundRadius = reader.Read<float>();

    m_WorldCenter.Read(reader, version, user, 0);

    m_WorldRadius = reader.Read<float>();

    m_ProportionCount = reader.Read<uint>();

    m_ProportionLevels.resize(m_ProportionCount);
    for (uint32_t i = 0; i < m_ProportionLevels.size(); i++)
    {
        m_ProportionLevels[i] = reader.Read<float>();
    }

}

void NiScreenLODData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiLODData::Write(writer, version, user, arg);

    m_BoundCenter.Write(writer, version, user, 0);

    writer.Write(m_BoundRadius);

    m_WorldCenter.Write(writer, version, user, 0);

    writer.Write(m_WorldRadius);

    writer.Write(m_ProportionCount);

    for (uint32_t i = 0; i < m_ProportionLevels.size(); i++)
    {
        writer.Write(m_ProportionLevels[i]);
    }

}
