#include "NiEnvMappedTriShape.hpp"

using namespace nejlika::geometry;

void NiEnvMappedTriShape::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObjectNET::Read(reader, version, user, arg);

    m_Unknown1 = reader.Read<ushort>();

    m_UnknownMatrix.Read(reader, version, user, 0);

    m_NumChildren = reader.Read<uint>();

    m_Children.resize(m_NumChildren);
    for (uint32_t i = 0; i < m_Children.size(); i++)
    {
        m_Children[i].Read(reader, version, user, 0);
    }

    m_Child2.Read(reader, version, user, 0);

    m_Child3.Read(reader, version, user, 0);

}

void NiEnvMappedTriShape::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObjectNET::Write(writer, version, user, arg);

    writer.Write(m_Unknown1);

    m_UnknownMatrix.Write(writer, version, user, 0);

    writer.Write(m_NumChildren);

    for (uint32_t i = 0; i < m_Children.size(); i++)
    {
        m_Children[i].Write(writer, version, user, 0);
    }

    m_Child2.Write(writer, version, user, 0);

    m_Child3.Write(writer, version, user, 0);

}
