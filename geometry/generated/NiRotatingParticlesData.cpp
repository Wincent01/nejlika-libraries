#include "NiRotatingParticlesData.hpp"

using namespace nejlika::geometry;

void NiRotatingParticlesData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiParticlesData::Read(reader, version, user, arg);

    if (version <= VERSION_NUMBER(4, 2, 2, 0))
    {
        m_HasRotations2 = reader.Read<bool>();
    }

    if (version <= VERSION_NUMBER(4, 2, 2, 0) && m_HasRotations2)
    {
        m_Rotations2.resize(m_NumVertices);
        for (uint32_t i = 0; i < m_Rotations2.size(); i++)
        {
            m_Rotations2[i].Read(reader, version, user, 0);
        }
    }

}

void NiRotatingParticlesData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiParticlesData::Write(writer, version, user, arg);

    if (version <= VERSION_NUMBER(4, 2, 2, 0))
    {
        writer.Write(m_HasRotations2);
    }

    if (version <= VERSION_NUMBER(4, 2, 2, 0) && m_HasRotations2)
    {
        for (uint32_t i = 0; i < m_Rotations2.size(); i++)
        {
            m_Rotations2[i].Write(writer, version, user, 0);
        }
    }

}
