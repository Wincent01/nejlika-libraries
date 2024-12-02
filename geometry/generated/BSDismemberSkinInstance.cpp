#include "BSDismemberSkinInstance.hpp"

using namespace nejlika::geometry;

void BSDismemberSkinInstance::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiSkinInstance::Read(reader, version, user, arg);

    m_NumPartitions = reader.Read<int>();

    m_Partitions.resize(m_NumPartitions);
    for (uint32_t i = 0; i < m_Partitions.size(); i++)
    {
        m_Partitions[i].Read(reader, version, user, 0);
    }

}

void BSDismemberSkinInstance::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiSkinInstance::Write(writer, version, user, arg);

    writer.Write(m_NumPartitions);

    for (uint32_t i = 0; i < m_Partitions.size(); i++)
    {
        m_Partitions[i].Write(writer, version, user, 0);
    }

}
