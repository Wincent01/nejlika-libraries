#include "NiBezierTriangle4.hpp"

using namespace nejlika::geometry;

void NiBezierTriangle4::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_Unknown1.resize(6);
    for (uint32_t i = 0; i < m_Unknown1.size(); i++)
    {
        m_Unknown1[i] = reader.Read<uint>();
    }

    m_Unknown2 = reader.Read<ushort>();

    m_Matrix.Read(reader, version, user, 0);

    m_Vector1.Read(reader, version, user, 0);

    m_Vector2.Read(reader, version, user, 0);

    m_Unknown3.resize(4);
    for (uint32_t i = 0; i < m_Unknown3.size(); i++)
    {
        m_Unknown3[i] = reader.Read<short>();
    }

    m_Unknown4 = reader.Read<byte>();

    m_Unknown5 = reader.Read<uint>();

    m_Unknown6.resize(24);
    for (uint32_t i = 0; i < m_Unknown6.size(); i++)
    {
        m_Unknown6[i] = reader.Read<short>();
    }

}

void NiBezierTriangle4::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    for (uint32_t i = 0; i < m_Unknown1.size(); i++)
    {
        writer.Write(m_Unknown1[i]);
    }

    writer.Write(m_Unknown2);

    m_Matrix.Write(writer, version, user, 0);

    m_Vector1.Write(writer, version, user, 0);

    m_Vector2.Write(writer, version, user, 0);

    for (uint32_t i = 0; i < m_Unknown3.size(); i++)
    {
        writer.Write(m_Unknown3[i]);
    }

    writer.Write(m_Unknown4);

    writer.Write(m_Unknown5);

    for (uint32_t i = 0; i < m_Unknown6.size(); i++)
    {
        writer.Write(m_Unknown6[i]);
    }

}
