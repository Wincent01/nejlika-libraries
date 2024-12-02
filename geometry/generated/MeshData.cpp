#include "MeshData.hpp"

using namespace nejlika::geometry;

void MeshData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Stream.Read(reader, version, user, 0);

    m_IsPerInstance = reader.Read<bool>();

    m_NumSubmeshes = reader.Read<ushort>();

    m_SubmeshToRegionMap.resize(m_NumSubmeshes);
    for (uint32_t i = 0; i < m_SubmeshToRegionMap.size(); i++)
    {
        m_SubmeshToRegionMap[i] = reader.Read<ushort>();
    }

    m_NumComponents = reader.Read<int>();

    m_ComponentSemantics.resize(m_NumComponents);
    for (uint32_t i = 0; i < m_ComponentSemantics.size(); i++)
    {
        m_ComponentSemantics[i].Read(reader, version, user, 0);
    }

}

void MeshData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    m_Stream.Write(writer, version, user, 0);

    writer.Write(m_IsPerInstance);

    writer.Write(m_NumSubmeshes);

    for (uint32_t i = 0; i < m_SubmeshToRegionMap.size(); i++)
    {
        writer.Write(m_SubmeshToRegionMap[i]);
    }

    writer.Write(m_NumComponents);

    for (uint32_t i = 0; i < m_ComponentSemantics.size(); i++)
    {
        m_ComponentSemantics[i].Write(writer, version, user, 0);
    }

}
