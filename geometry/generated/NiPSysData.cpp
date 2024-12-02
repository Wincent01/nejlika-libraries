#include "NiPSysData.hpp"

using namespace nejlika::geometry;

void NiPSysData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiRotatingParticlesData::Read(reader, version, user, arg);

    if (!((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11)))
    {
        m_ParticleDescriptions.resize(m_NumVertices);
        for (uint32_t i = 0; i < m_ParticleDescriptions.size(); i++)
        {
            m_ParticleDescriptions[i].Read(reader, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4) && !((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11)))
    {
        m_HasUnknownFloats3 = reader.Read<bool>();
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4) && m_HasUnknownFloats3 && !((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11)))
    {
        m_UnknownFloats3.resize(m_NumVertices);
        for (uint32_t i = 0; i < m_UnknownFloats3.size(); i++)
        {
            m_UnknownFloats3[i] = reader.Read<float>();
        }
    }

    if (!((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user== 11)))
    {
        m_UnknownShort1 = reader.Read<ushort>();
    }

    if (!((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user== 11)))
    {
        m_UnknownShort2 = reader.Read<ushort>();
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        m_HasSubtextureOffsetUVs = reader.Read<bool>();
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        m_NumSubtextureOffsetUVs = reader.Read<uint>();
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        m_AspectRatio = reader.Read<float>();
    }

    if (m_HasSubtextureOffsetUVs && ((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        m_SubtextureOffsetUVs.resize(m_NumSubtextureOffsetUVs);
        for (uint32_t i = 0; i < m_SubtextureOffsetUVs.size(); i++)
        {
            m_SubtextureOffsetUVs[i].Read(reader, version, user, 0);
        }
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        m_UnknownInt4 = reader.Read<uint>();
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        m_UnknownInt5 = reader.Read<uint>();
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        m_UnknownInt6 = reader.Read<uint>();
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        m_UnknownShort3 = reader.Read<ushort>();
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        m_UnknownByte4 = reader.Read<byte>();
    }

}

void NiPSysData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiRotatingParticlesData::Write(writer, version, user, arg);

    if (!((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11)))
    {
        for (uint32_t i = 0; i < m_ParticleDescriptions.size(); i++)
        {
            m_ParticleDescriptions[i].Write(writer, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4) && !((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11)))
    {
        writer.Write(m_HasUnknownFloats3);
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4) && m_HasUnknownFloats3 && !((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11)))
    {
        for (uint32_t i = 0; i < m_UnknownFloats3.size(); i++)
        {
            writer.Write(m_UnknownFloats3[i]);
        }
    }

    if (!((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user== 11)))
    {
        writer.Write(m_UnknownShort1);
    }

    if (!((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user== 11)))
    {
        writer.Write(m_UnknownShort2);
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        writer.Write(m_HasSubtextureOffsetUVs);
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        writer.Write(m_NumSubtextureOffsetUVs);
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        writer.Write(m_AspectRatio);
    }

    if (m_HasSubtextureOffsetUVs && ((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        for (uint32_t i = 0; i < m_SubtextureOffsetUVs.size(); i++)
        {
            m_SubtextureOffsetUVs[i].Write(writer, version, user, 0);
        }
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        writer.Write(m_UnknownInt4);
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        writer.Write(m_UnknownInt5);
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        writer.Write(m_UnknownInt6);
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        writer.Write(m_UnknownShort3);
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        writer.Write(m_UnknownByte4);
    }

}
