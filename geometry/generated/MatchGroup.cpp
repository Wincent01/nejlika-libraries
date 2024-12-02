#include "MatchGroup.hpp"

using namespace nejlika::geometry;

void MatchGroup::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_NumVertices = reader.Read<ushort>();

    m_VertexIndices.resize(m_NumVertices);
    for (uint32_t i = 0; i < m_VertexIndices.size(); i++)
    {
        m_VertexIndices[i] = reader.Read<ushort>();
    }

}

void MatchGroup::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_NumVertices);

    for (uint32_t i = 0; i < m_VertexIndices.size(); i++)
    {
        writer.Write(m_VertexIndices[i]);
    }

}
