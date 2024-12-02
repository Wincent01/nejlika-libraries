#include "NiShadowGenerator.hpp"

using namespace nejlika::geometry;

void NiShadowGenerator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_Name.Read(reader, version, user, 0);

    m_UnknownFlags = reader.Read<ushort>();

    m_NumUnknownLinks1 = reader.Read<uint>();

    m_UnknownLinks1.resize(m_NumUnknownLinks1);
    for (uint32_t i = 0; i < m_UnknownLinks1.size(); i++)
    {
        m_UnknownLinks1[i].Read(reader, version, user, 0);
    }

    m_UnkownInt2 = reader.Read<int>();

    m_Target.Read(reader, version, user, 0);

    m_UnkownFloat4 = reader.Read<float>();

    m_UnkownByte5 = reader.Read<byte>();

    m_UnkownInt6 = reader.Read<int>();

    m_UnkownInt7 = reader.Read<int>();

    m_UnkownInt8 = reader.Read<int>();

    m_UnkownByte9 = reader.Read<byte>();

}

void NiShadowGenerator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    m_Name.Write(writer, version, user, 0);

    writer.Write(m_UnknownFlags);

    writer.Write(m_NumUnknownLinks1);

    for (uint32_t i = 0; i < m_UnknownLinks1.size(); i++)
    {
        m_UnknownLinks1[i].Write(writer, version, user, 0);
    }

    writer.Write(m_UnkownInt2);

    m_Target.Write(writer, version, user, 0);

    writer.Write(m_UnkownFloat4);

    writer.Write(m_UnkownByte5);

    writer.Write(m_UnkownInt6);

    writer.Write(m_UnkownInt7);

    writer.Write(m_UnkownInt8);

    writer.Write(m_UnkownByte9);

}
