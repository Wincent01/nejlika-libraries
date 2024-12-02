#include "bhkNiTriStripsShape.hpp"

using namespace nejlika::geometry;

void bhkNiTriStripsShape::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkShapeCollection::Read(reader, version, user, arg);

    if (user< 12)
    {
        m_Material = reader.Read<HavokMaterial>();
    }

    if (user>= 12)
    {
        m_SkyrimMaterial = reader.Read<SkyrimHavokMaterial>();
    }

    m_UnknownFloat1 = reader.Read<float>();

    m_UnknownInt1 = reader.Read<uint>();

    m_UnknownInts1.resize(4);
    for (uint32_t i = 0; i < m_UnknownInts1.size(); i++)
    {
        m_UnknownInts1[i] = reader.Read<uint>();
    }

    m_UnknownInt2 = reader.Read<uint>();

    m_Scale.Read(reader, version, user, 0);

    m_UnknownInt3 = reader.Read<uint>();

    m_NumStripsData = reader.Read<uint>();

    m_StripsData.resize(m_NumStripsData);
    for (uint32_t i = 0; i < m_StripsData.size(); i++)
    {
        m_StripsData[i].Read(reader, version, user, 0);
    }

    m_NumDataLayers = reader.Read<uint>();

    m_DataLayers.resize(m_NumDataLayers);
    for (uint32_t i = 0; i < m_DataLayers.size(); i++)
    {
        m_DataLayers[i].Read(reader, version, user, 0);
    }

}

void bhkNiTriStripsShape::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkShapeCollection::Write(writer, version, user, arg);

    if (user< 12)
    {
        writer.Write(m_Material);
    }

    if (user>= 12)
    {
        writer.Write(m_SkyrimMaterial);
    }

    writer.Write(m_UnknownFloat1);

    writer.Write(m_UnknownInt1);

    for (uint32_t i = 0; i < m_UnknownInts1.size(); i++)
    {
        writer.Write(m_UnknownInts1[i]);
    }

    writer.Write(m_UnknownInt2);

    m_Scale.Write(writer, version, user, 0);

    writer.Write(m_UnknownInt3);

    writer.Write(m_NumStripsData);

    for (uint32_t i = 0; i < m_StripsData.size(); i++)
    {
        m_StripsData[i].Write(writer, version, user, 0);
    }

    writer.Write(m_NumDataLayers);

    for (uint32_t i = 0; i < m_DataLayers.size(); i++)
    {
        m_DataLayers[i].Write(writer, version, user, 0);
    }

}
