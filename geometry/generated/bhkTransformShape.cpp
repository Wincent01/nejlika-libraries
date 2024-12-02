#include "bhkTransformShape.hpp"

using namespace nejlika::geometry;

void bhkTransformShape::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkShape::Read(reader, version, user, arg);

    m_Shape.Read(reader, version, user, 0);

    if (user< 12)
    {
        m_Material = reader.Read<HavokMaterial>();
    }

    if (user>= 12)
    {
        m_SkyrimMaterial = reader.Read<SkyrimHavokMaterial>();
    }

    m_UnknownFloat1 = reader.Read<float>();

    m_Unknown8Bytes.resize(8);
    for (uint32_t i = 0; i < m_Unknown8Bytes.size(); i++)
    {
        m_Unknown8Bytes[i] = reader.Read<byte>();
    }

    m_Transform.Read(reader, version, user, 0);

}

void bhkTransformShape::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkShape::Write(writer, version, user, arg);

    m_Shape.Write(writer, version, user, 0);

    if (user< 12)
    {
        writer.Write(m_Material);
    }

    if (user>= 12)
    {
        writer.Write(m_SkyrimMaterial);
    }

    writer.Write(m_UnknownFloat1);

    for (uint32_t i = 0; i < m_Unknown8Bytes.size(); i++)
    {
        writer.Write(m_Unknown8Bytes[i]);
    }

    m_Transform.Write(writer, version, user, 0);

}
