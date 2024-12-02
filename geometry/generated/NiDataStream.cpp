#include "NiDataStream.hpp"

using namespace nejlika::geometry;

void NiDataStream::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_Usage = reader.Read<DataStreamUsage>();

    m_Access = reader.Read<DataStreamAccess>();

    m_NumBytes = reader.Read<uint>();

    m_CloningBehavior = reader.Read<CloningBehavior>();

    m_NumRegions = reader.Read<uint>();

    m_Regions.resize(m_NumRegions);
    for (uint32_t i = 0; i < m_Regions.size(); i++)
    {
        m_Regions[i].Read(reader, version, user, 0);
    }

    m_NumComponents = reader.Read<uint>();

    m_ComponentFormats.resize(m_NumComponents);
    for (uint32_t i = 0; i < m_ComponentFormats.size(); i++)
    {
        m_ComponentFormats[i] = reader.Read<ComponentFormat>();
    }

    m_Data.resize(m_NumBytes);
    for (uint32_t i = 0; i < m_Data.size(); i++)
    {
        m_Data[i] = reader.Read<byte>();
    }

    m_Streamable = reader.Read<bool>();

}

void NiDataStream::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    writer.Write(m_Usage);

    writer.Write(m_Access);

    writer.Write(m_NumBytes);

    writer.Write(m_CloningBehavior);

    writer.Write(m_NumRegions);

    for (uint32_t i = 0; i < m_Regions.size(); i++)
    {
        m_Regions[i].Write(writer, version, user, 0);
    }

    writer.Write(m_NumComponents);

    for (uint32_t i = 0; i < m_ComponentFormats.size(); i++)
    {
        writer.Write(m_ComponentFormats[i]);
    }

    for (uint32_t i = 0; i < m_Data.size(); i++)
    {
        writer.Write(m_Data[i]);
    }

    writer.Write(m_Streamable);

}
