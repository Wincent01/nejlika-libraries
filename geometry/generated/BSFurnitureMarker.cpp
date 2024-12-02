#include "BSFurnitureMarker.hpp"

using namespace nejlika::geometry;

void BSFurnitureMarker::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiExtraData::Read(reader, version, user, arg);

    m_NumPositions = reader.Read<uint>();

    m_Positions.resize(m_NumPositions);
    for (uint32_t i = 0; i < m_Positions.size(); i++)
    {
        m_Positions[i].Read(reader, version, user, 0);
    }

}

void BSFurnitureMarker::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiExtraData::Write(writer, version, user, arg);

    writer.Write(m_NumPositions);

    for (uint32_t i = 0; i < m_Positions.size(); i++)
    {
        m_Positions[i].Write(writer, version, user, 0);
    }

}
