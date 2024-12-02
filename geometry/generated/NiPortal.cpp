#include "NiPortal.hpp"

using namespace nejlika::geometry;

void NiPortal::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiAVObject::Read(reader, version, user, arg);

    m_UnknownFlags = reader.Read<Flags>();

    m_UnknownShort2 = reader.Read<short>();

    m_NumVertices = reader.Read<ushort>();

    m_Vertices.resize(m_NumVertices);
    for (uint32_t i = 0; i < m_Vertices.size(); i++)
    {
        m_Vertices[i].Read(reader, version, user, 0);
    }

    m_Target.Read(reader, version, user, 0);

}

void NiPortal::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiAVObject::Write(writer, version, user, arg);

    writer.Write(m_UnknownFlags);

    writer.Write(m_UnknownShort2);

    writer.Write(m_NumVertices);

    for (uint32_t i = 0; i < m_Vertices.size(); i++)
    {
        m_Vertices[i].Write(writer, version, user, 0);
    }

    m_Target.Write(writer, version, user, 0);

}
