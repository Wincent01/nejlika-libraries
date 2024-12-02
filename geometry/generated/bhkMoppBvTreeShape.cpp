#include "bhkMoppBvTreeShape.hpp"

using namespace nejlika::geometry;

void bhkMoppBvTreeShape::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkBvTreeShape::Read(reader, version, user, arg);

    m_Shape.Read(reader, version, user, 0);

    if (user< 12)
    {
        m_Material = reader.Read<HavokMaterial>();
    }

    if (user>= 12)
    {
        m_SkyrimMaterial = reader.Read<SkyrimHavokMaterial>();
    }

    m_Unknown8Bytes.resize(8);
    for (uint32_t i = 0; i < m_Unknown8Bytes.size(); i++)
    {
        m_Unknown8Bytes[i] = reader.Read<byte>();
    }

    m_UnknownFloat = reader.Read<float>();

    m_MOPPDataSize = reader.Read<uint>();

    m_Origin.Read(reader, version, user, 0);

    m_Scale = reader.Read<float>();

    if (version <= VERSION_NUMBER(10, 0, 1, 0))
    {
        m_OldMOPPData.resize(m_MOPPDataSize- 1);
        for (uint32_t i = 0; i < m_OldMOPPData.size(); i++)
        {
            m_OldMOPPData[i] = reader.Read<byte>();
        }
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && user>= 12)
    {
        m_BuildType = reader.Read<MoppDataBuildType>();
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 2))
    {
        m_MOPPData.resize(m_MOPPDataSize);
        for (uint32_t i = 0; i < m_MOPPData.size(); i++)
        {
            m_MOPPData[i] = reader.Read<byte>();
        }
    }

}

void bhkMoppBvTreeShape::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkBvTreeShape::Write(writer, version, user, arg);

    m_Shape.Write(writer, version, user, 0);

    if (user< 12)
    {
        writer.Write(m_Material);
    }

    if (user>= 12)
    {
        writer.Write(m_SkyrimMaterial);
    }

    for (uint32_t i = 0; i < m_Unknown8Bytes.size(); i++)
    {
        writer.Write(m_Unknown8Bytes[i]);
    }

    writer.Write(m_UnknownFloat);

    writer.Write(m_MOPPDataSize);

    m_Origin.Write(writer, version, user, 0);

    writer.Write(m_Scale);

    if (version <= VERSION_NUMBER(10, 0, 1, 0))
    {
        for (uint32_t i = 0; i < m_OldMOPPData.size(); i++)
        {
            writer.Write(m_OldMOPPData[i]);
        }
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && user>= 12)
    {
        writer.Write(m_BuildType);
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 2))
    {
        for (uint32_t i = 0; i < m_MOPPData.size(); i++)
        {
            writer.Write(m_MOPPData[i]);
        }
    }

}
