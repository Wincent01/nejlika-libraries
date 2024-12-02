#include "NiRangeLODData.hpp"

using namespace nejlika::geometry;

void NiRangeLODData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiLODData::Read(reader, version, user, arg);

    m_LODCenter.Read(reader, version, user, 0);

    m_NumLODLevels = reader.Read<uint>();

    m_LODLevels.resize(m_NumLODLevels);
    for (uint32_t i = 0; i < m_LODLevels.size(); i++)
    {
        m_LODLevels[i].Read(reader, version, user, 0);
    }

}

void NiRangeLODData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiLODData::Write(writer, version, user, arg);

    m_LODCenter.Write(writer, version, user, 0);

    writer.Write(m_NumLODLevels);

    for (uint32_t i = 0; i < m_LODLevels.size(); i++)
    {
        m_LODLevels[i].Write(writer, version, user, 0);
    }

}
