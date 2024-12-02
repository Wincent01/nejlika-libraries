#include "DecalVectorArray.hpp"

using namespace nejlika::geometry;

void DecalVectorArray::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_NumVectors = reader.Read<short>();

    m_Points.resize(m_NumVectors);
    for (uint32_t i = 0; i < m_Points.size(); i++)
    {
        m_Points[i].Read(reader, version, user, 0);
    }

    m_Normals.resize(m_NumVectors);
    for (uint32_t i = 0; i < m_Normals.size(); i++)
    {
        m_Normals[i].Read(reader, version, user, 0);
    }

}

void DecalVectorArray::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_NumVectors);

    for (uint32_t i = 0; i < m_Points.size(); i++)
    {
        m_Points[i].Write(writer, version, user, 0);
    }

    for (uint32_t i = 0; i < m_Normals.size(); i++)
    {
        m_Normals[i].Write(writer, version, user, 0);
    }

}
