#include "bhkConvexListShape.hpp"

using namespace nejlika::geometry;

void bhkConvexListShape::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkShape::Read(reader, version, user, arg);

    m_NumSubShapes = reader.Read<uint>();

    m_SubShapes.resize(m_NumSubShapes);
    for (uint32_t i = 0; i < m_SubShapes.size(); i++)
    {
        m_SubShapes[i].Read(reader, version, user, 0);
    }

    if (user< 12)
    {
        m_Material = reader.Read<HavokMaterial>();
    }

    if (user>= 12)
    {
        m_SkyrimMaterial = reader.Read<SkyrimHavokMaterial>();
    }

    m_UnknownFloats.resize(6);
    for (uint32_t i = 0; i < m_UnknownFloats.size(); i++)
    {
        m_UnknownFloats[i] = reader.Read<float>();
    }

    m_UnknownByte1 = reader.Read<byte>();

    m_UnknownFloat1 = reader.Read<float>();

}

void bhkConvexListShape::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkShape::Write(writer, version, user, arg);

    writer.Write(m_NumSubShapes);

    for (uint32_t i = 0; i < m_SubShapes.size(); i++)
    {
        m_SubShapes[i].Write(writer, version, user, 0);
    }

    if (user< 12)
    {
        writer.Write(m_Material);
    }

    if (user>= 12)
    {
        writer.Write(m_SkyrimMaterial);
    }

    for (uint32_t i = 0; i < m_UnknownFloats.size(); i++)
    {
        writer.Write(m_UnknownFloats[i]);
    }

    writer.Write(m_UnknownByte1);

    writer.Write(m_UnknownFloat1);

}
