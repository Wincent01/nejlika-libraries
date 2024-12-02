#include "NiTriStripsData.hpp"

using namespace nejlika::geometry;

void NiTriStripsData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTriBasedGeomData::Read(reader, version, user, arg);

    m_NumStrips = reader.Read<ushort>();

    m_StripLengths.resize(m_NumStrips);
    for (uint32_t i = 0; i < m_StripLengths.size(); i++)
    {
        m_StripLengths[i] = reader.Read<ushort>();
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 3))
    {
        m_HasPoints = reader.Read<bool>();
    }

    if (version <= VERSION_NUMBER(10, 0, 1, 2))
    {
        m_Points.resize(m_NumStrips);
        for (uint32_t i = 0; i < m_Points.size(); i++)
        {
            m_Points[i].resize(m_StripLengths[i]);
            for (uint32_t j = 0; j < m_Points[i].size(); j++)
            {
                m_Points[i][j] = reader.Read<ushort>();
            }
        }
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 3) && m_HasPoints)
    {
        m_Points.resize(m_NumStrips);
        for (uint32_t i = 0; i < m_Points.size(); i++)
        {
            m_Points[i].resize(m_StripLengths[i]);
            for (uint32_t j = 0; j < m_Points[i].size(); j++)
            {
                m_Points[i][j] = reader.Read<ushort>();
            }
        }
    }

}

void NiTriStripsData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTriBasedGeomData::Write(writer, version, user, arg);

    writer.Write(m_NumStrips);

    for (uint32_t i = 0; i < m_StripLengths.size(); i++)
    {
        writer.Write(m_StripLengths[i]);
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 3))
    {
        writer.Write(m_HasPoints);
    }

    if (version <= VERSION_NUMBER(10, 0, 1, 2))
    {
        for (uint32_t i = 0; i < m_Points.size(); i++)
        {
            for (uint32_t j = 0; j < m_Points[i].size(); j++)
            {
                writer.Write(m_Points[i][j]);
            }
        }
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 3) && m_HasPoints)
    {
        for (uint32_t i = 0; i < m_Points.size(); i++)
        {
            for (uint32_t j = 0; j < m_Points[i].size(); j++)
            {
                writer.Write(m_Points[i][j]);
            }
        }
    }

}
