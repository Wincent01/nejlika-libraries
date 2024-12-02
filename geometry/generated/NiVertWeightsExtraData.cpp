#include "NiVertWeightsExtraData.hpp"

using namespace nejlika::geometry;

void NiVertWeightsExtraData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiExtraData::Read(reader, version, user, arg);

    m_NumBytes = reader.Read<uint>();

    m_NumVertices = reader.Read<ushort>();

    m_Weight.resize(m_NumVertices);
    for (uint32_t i = 0; i < m_Weight.size(); i++)
    {
        m_Weight[i] = reader.Read<float>();
    }

}

void NiVertWeightsExtraData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiExtraData::Write(writer, version, user, arg);

    writer.Write(m_NumBytes);

    writer.Write(m_NumVertices);

    for (uint32_t i = 0; i < m_Weight.size(); i++)
    {
        writer.Write(m_Weight[i]);
    }

}
