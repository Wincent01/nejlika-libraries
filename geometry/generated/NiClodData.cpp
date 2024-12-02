#include "NiClodData.hpp"

using namespace nejlika::geometry;

void NiClodData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTriBasedGeomData::Read(reader, version, user, arg);

    m_UnknownShorts = reader.Read<ushort>();

    m_UnknownCount1 = reader.Read<ushort>();

    m_UnknownCount2 = reader.Read<ushort>();

    m_UnknownCount3 = reader.Read<ushort>();

    m_UnknownFloat = reader.Read<float>();

    m_UnknownShort = reader.Read<ushort>();

    m_UnknownClodShorts1.resize(m_UnknownCount1);
    for (uint32_t i = 0; i < m_UnknownClodShorts1.size(); i++)
    {
        m_UnknownClodShorts1[i].resize(6);
        for (uint32_t j = 0; j < m_UnknownClodShorts1[i].size(); j++)
        {
            m_UnknownClodShorts1[i][j] = reader.Read<ushort>();
        }
    }

    m_UnknownClodShorts2.resize(m_UnknownCount2);
    for (uint32_t i = 0; i < m_UnknownClodShorts2.size(); i++)
    {
        m_UnknownClodShorts2[i] = reader.Read<ushort>();
    }

    m_UnknownClodShorts3.resize(m_UnknownCount3);
    for (uint32_t i = 0; i < m_UnknownClodShorts3.size(); i++)
    {
        m_UnknownClodShorts3[i].resize(6);
        for (uint32_t j = 0; j < m_UnknownClodShorts3[i].size(); j++)
        {
            m_UnknownClodShorts3[i][j] = reader.Read<ushort>();
        }
    }

}

void NiClodData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTriBasedGeomData::Write(writer, version, user, arg);

    writer.Write(m_UnknownShorts);

    writer.Write(m_UnknownCount1);

    writer.Write(m_UnknownCount2);

    writer.Write(m_UnknownCount3);

    writer.Write(m_UnknownFloat);

    writer.Write(m_UnknownShort);

    for (uint32_t i = 0; i < m_UnknownClodShorts1.size(); i++)
    {
        for (uint32_t j = 0; j < m_UnknownClodShorts1[i].size(); j++)
        {
            writer.Write(m_UnknownClodShorts1[i][j]);
        }
    }

    for (uint32_t i = 0; i < m_UnknownClodShorts2.size(); i++)
    {
        writer.Write(m_UnknownClodShorts2[i]);
    }

    for (uint32_t i = 0; i < m_UnknownClodShorts3.size(); i++)
    {
        for (uint32_t j = 0; j < m_UnknownClodShorts3[i].size(); j++)
        {
            writer.Write(m_UnknownClodShorts3[i][j]);
        }
    }

}
