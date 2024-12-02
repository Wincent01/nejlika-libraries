#include "NiMeshPSysData.hpp"

using namespace nejlika::geometry;

void NiMeshPSysData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysData::Read(reader, version, user, arg);

    if (version >= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_UnknownInt2 = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_UnknownByte3 = reader.Read<byte>();
    }
    else
    {
        m_UnknownByte3 = 0;
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_NumUnknownInts1 = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_UnknownInts1.resize(m_NumUnknownInts1);
        for (uint32_t i = 0; i < m_UnknownInts1.size(); i++)
        {
            m_UnknownInts1[i] = reader.Read<uint>();
        }
    }

    m_UnknownNode.Read(reader, version, user, 0);

}

void NiMeshPSysData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysData::Write(writer, version, user, arg);

    if (version >= VERSION_NUMBER(10, 2, 0, 0))
    {
        writer.Write(m_UnknownInt2);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0))
    {
        writer.Write(m_UnknownByte3);
    }
    else
    {
        //writer.Write(0);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0))
    {
        writer.Write(m_NumUnknownInts1);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0))
    {
        for (uint32_t i = 0; i < m_UnknownInts1.size(); i++)
        {
            writer.Write(m_UnknownInts1[i]);
        }
    }

    m_UnknownNode.Write(writer, version, user, 0);

}
