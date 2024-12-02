#include "bhkCompressedMeshShape.hpp"

using namespace nejlika::geometry;

void bhkCompressedMeshShape::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkShape::Read(reader, version, user, arg);

    m_Target.Read(reader, version, user, 0);

    m_SkyrimMaterial = reader.Read<SkyrimHavokMaterial>();

    m_UnknownFloat1 = reader.Read<float>();

    m_Unknown4Bytes.resize(4);
    for (uint32_t i = 0; i < m_Unknown4Bytes.size(); i++)
    {
        m_Unknown4Bytes[i] = reader.Read<byte>();
    }

    m_UnknownFloats1.Read(reader, version, user, 0);

    m_Radius = reader.Read<float>();

    m_Scale = reader.Read<float>();

    m_UnknownFloat3 = reader.Read<float>();

    m_UnknownFloat4 = reader.Read<float>();

    m_UnknownFloat5 = reader.Read<float>();

    m_Data.Read(reader, version, user, 0);

}

void bhkCompressedMeshShape::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkShape::Write(writer, version, user, arg);

    m_Target.Write(writer, version, user, 0);

    writer.Write(m_SkyrimMaterial);

    writer.Write(m_UnknownFloat1);

    for (uint32_t i = 0; i < m_Unknown4Bytes.size(); i++)
    {
        writer.Write(m_Unknown4Bytes[i]);
    }

    m_UnknownFloats1.Write(writer, version, user, 0);

    writer.Write(m_Radius);

    writer.Write(m_Scale);

    writer.Write(m_UnknownFloat3);

    writer.Write(m_UnknownFloat4);

    writer.Write(m_UnknownFloat5);

    m_Data.Write(writer, version, user, 0);

}
