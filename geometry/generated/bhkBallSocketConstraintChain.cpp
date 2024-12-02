#include "bhkBallSocketConstraintChain.hpp"

using namespace nejlika::geometry;

void bhkBallSocketConstraintChain::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkSerializable::Read(reader, version, user, arg);

    m_NumFloats = reader.Read<uint>();

    m_Floats1.resize(m_NumFloats);
    for (uint32_t i = 0; i < m_Floats1.size(); i++)
    {
        m_Floats1[i].Read(reader, version, user, 0);
    }

    m_UnknownFloat1 = reader.Read<float>();

    m_UnknownFloat2 = reader.Read<float>();

    m_UnknownInt1 = reader.Read<uint>();

    m_UnknownInt2 = reader.Read<uint>();

    m_NumLinks = reader.Read<uint>();

    m_Links.resize(m_NumLinks);
    for (uint32_t i = 0; i < m_Links.size(); i++)
    {
        m_Links[i].Read(reader, version, user, 0);
    }

    m_NumLinks2 = reader.Read<uint>();

    m_Links2.resize(m_NumLinks2);
    for (uint32_t i = 0; i < m_Links2.size(); i++)
    {
        m_Links2[i].Read(reader, version, user, 0);
    }

    m_UnknownInt3 = reader.Read<uint>();

}

void bhkBallSocketConstraintChain::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkSerializable::Write(writer, version, user, arg);

    writer.Write(m_NumFloats);

    for (uint32_t i = 0; i < m_Floats1.size(); i++)
    {
        m_Floats1[i].Write(writer, version, user, 0);
    }

    writer.Write(m_UnknownFloat1);

    writer.Write(m_UnknownFloat2);

    writer.Write(m_UnknownInt1);

    writer.Write(m_UnknownInt2);

    writer.Write(m_NumLinks);

    for (uint32_t i = 0; i < m_Links.size(); i++)
    {
        m_Links[i].Write(writer, version, user, 0);
    }

    writer.Write(m_NumLinks2);

    for (uint32_t i = 0; i < m_Links2.size(); i++)
    {
        m_Links2[i].Write(writer, version, user, 0);
    }

    writer.Write(m_UnknownInt3);

}
