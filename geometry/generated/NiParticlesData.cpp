#include "NiParticlesData.hpp"

using namespace nejlika::geometry;

void NiParticlesData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiGeometryData::Read(reader, version, user, arg);

    if (version <= VERSION_NUMBER(4, 0, 0, 2))
    {
        m_NumParticles = reader.Read<ushort>();
    }

    if (version <= VERSION_NUMBER(10, 0, 1, 0))
    {
        m_ParticleRadius = reader.Read<float>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_HasRadii = reader.Read<bool>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && m_HasRadii && !((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11)))
    {
        m_Radii.resize(m_NumVertices);
        for (uint32_t i = 0; i < m_Radii.size(); i++)
        {
            m_Radii[i] = reader.Read<float>();
        }
    }

    m_NumActive = reader.Read<ushort>();

    m_HasSizes = reader.Read<bool>();

    if (m_HasSizes && !((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11)))
    {
        m_Sizes.resize(m_NumVertices);
        for (uint32_t i = 0; i < m_Sizes.size(); i++)
        {
            m_Sizes[i] = reader.Read<float>();
        }
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0))
    {
        m_HasRotations = reader.Read<bool>();
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0) && m_HasRotations && !((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11)))
    {
        m_Rotations.resize(m_NumVertices);
        for (uint32_t i = 0; i < m_Rotations.size(); i++)
        {
            m_Rotations[i].Read(reader, version, user, 0);
        }
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        m_UnknownByte1 = reader.Read<byte>();
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        m_UnknownLink.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        m_HasRotationAngles = reader.Read<bool>();
    }

    if (m_HasRotationAngles && !((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11)))
    {
        m_RotationAngles.resize(m_NumVertices);
        for (uint32_t i = 0; i < m_RotationAngles.size(); i++)
        {
            m_RotationAngles[i] = reader.Read<float>();
        }
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        m_HasRotationAxes = reader.Read<bool>();
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4) && m_HasRotationAxes && !((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11)))
    {
        m_RotationAxes.resize(m_NumVertices);
        for (uint32_t i = 0; i < m_RotationAxes.size(); i++)
        {
            m_RotationAxes[i].Read(reader, version, user, 0);
        }
    }

    if ((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user== 11))
    {
        m_HasUVQuadrants = reader.Read<bool>();
    }

    if ((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user== 11))
    {
        m_NumUVQuadrants = reader.Read<byte>();
    }

    if (m_HasUVQuadrants && (version >= VERSION_NUMBER(20, 2, 0, 7)) && (user== 11))
    {
        m_UVQuadrants.resize(m_NumUVQuadrants);
        for (uint32_t i = 0; i < m_UVQuadrants.size(); i++)
        {
            m_UVQuadrants[i].Read(reader, version, user, 0);
        }
    }

    if ((version == VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11))
    {
        m_UnknownByte2 = reader.Read<byte>();
    }

}

void NiParticlesData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiGeometryData::Write(writer, version, user, arg);

    if (version <= VERSION_NUMBER(4, 0, 0, 2))
    {
        writer.Write(m_NumParticles);
    }

    if (version <= VERSION_NUMBER(10, 0, 1, 0))
    {
        writer.Write(m_ParticleRadius);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_HasRadii);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && m_HasRadii && !((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11)))
    {
        for (uint32_t i = 0; i < m_Radii.size(); i++)
        {
            writer.Write(m_Radii[i]);
        }
    }

    writer.Write(m_NumActive);

    writer.Write(m_HasSizes);

    if (m_HasSizes && !((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11)))
    {
        for (uint32_t i = 0; i < m_Sizes.size(); i++)
        {
            writer.Write(m_Sizes[i]);
        }
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0))
    {
        writer.Write(m_HasRotations);
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0) && m_HasRotations && !((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11)))
    {
        for (uint32_t i = 0; i < m_Rotations.size(); i++)
        {
            m_Rotations[i].Write(writer, version, user, 0);
        }
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        writer.Write(m_UnknownByte1);
    }

    if (((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 12)))
    {
        m_UnknownLink.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        writer.Write(m_HasRotationAngles);
    }

    if (m_HasRotationAngles && !((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11)))
    {
        for (uint32_t i = 0; i < m_RotationAngles.size(); i++)
        {
            writer.Write(m_RotationAngles[i]);
        }
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        writer.Write(m_HasRotationAxes);
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4) && m_HasRotationAxes && !((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11)))
    {
        for (uint32_t i = 0; i < m_RotationAxes.size(); i++)
        {
            m_RotationAxes[i].Write(writer, version, user, 0);
        }
    }

    if ((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user== 11))
    {
        writer.Write(m_HasUVQuadrants);
    }

    if ((version >= VERSION_NUMBER(20, 2, 0, 7)) && (user== 11))
    {
        writer.Write(m_NumUVQuadrants);
    }

    if (m_HasUVQuadrants && (version >= VERSION_NUMBER(20, 2, 0, 7)) && (user== 11))
    {
        for (uint32_t i = 0; i < m_UVQuadrants.size(); i++)
        {
            m_UVQuadrants[i].Write(writer, version, user, 0);
        }
    }

    if ((version == VERSION_NUMBER(20, 2, 0, 7)) && (user>= 11))
    {
        writer.Write(m_UnknownByte2);
    }

}
