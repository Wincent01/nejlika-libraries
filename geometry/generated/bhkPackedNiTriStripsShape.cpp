#include "bhkPackedNiTriStripsShape.hpp"

using namespace nejlika::geometry;

void bhkPackedNiTriStripsShape::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkShapeCollection::Read(reader, version, user, arg);

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_NumSubShapes = reader.Read<ushort>();
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_SubShapes.resize(m_NumSubShapes);
        for (uint32_t i = 0; i < m_SubShapes.size(); i++)
        {
            m_SubShapes[i].Read(reader, version, user, 0);
        }
    }

    m_UnknownInt1 = reader.Read<uint>();

    m_UnknownInt2 = reader.Read<uint>();

    m_UnknownFloat1 = reader.Read<float>();

    m_UnknownInt3 = reader.Read<uint>();

    m_ScaleCopy.Read(reader, version, user, 0);

    m_UnknownFloat2 = reader.Read<float>();

    m_UnknownFloat3 = reader.Read<float>();

    m_Scale.Read(reader, version, user, 0);

    m_UnknownFloat4 = reader.Read<float>();

    m_Data.Read(reader, version, user, 0);

}

void bhkPackedNiTriStripsShape::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkShapeCollection::Write(writer, version, user, arg);

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        writer.Write(m_NumSubShapes);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        for (uint32_t i = 0; i < m_SubShapes.size(); i++)
        {
            m_SubShapes[i].Write(writer, version, user, 0);
        }
    }

    writer.Write(m_UnknownInt1);

    writer.Write(m_UnknownInt2);

    writer.Write(m_UnknownFloat1);

    writer.Write(m_UnknownInt3);

    m_ScaleCopy.Write(writer, version, user, 0);

    writer.Write(m_UnknownFloat2);

    writer.Write(m_UnknownFloat3);

    m_Scale.Write(writer, version, user, 0);

    writer.Write(m_UnknownFloat4);

    m_Data.Write(writer, version, user, 0);

}
