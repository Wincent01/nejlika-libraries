#include "ParticleDesc.hpp"

using namespace nejlika::geometry;

void ParticleDesc::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Translation.Read(reader, version, user, 0);

    if (version <= VERSION_NUMBER(10, 4, 0, 1))
    {
        m_UnknownFloats1.resize(3);
        for (uint32_t i = 0; i < m_UnknownFloats1.size(); i++)
        {
            m_UnknownFloats1[i] = reader.Read<float>();
        }
    }

    m_UnknownFloat1 = reader.Read<float>();

    m_UnknownFloat2 = reader.Read<float>();

    m_UnknownFloat3 = reader.Read<float>();

    m_UnknownInt1 = reader.Read<int>();

}

void ParticleDesc::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    m_Translation.Write(writer, version, user, 0);

    if (version <= VERSION_NUMBER(10, 4, 0, 1))
    {
        for (uint32_t i = 0; i < m_UnknownFloats1.size(); i++)
        {
            writer.Write(m_UnknownFloats1[i]);
        }
    }

    writer.Write(m_UnknownFloat1);

    writer.Write(m_UnknownFloat2);

    writer.Write(m_UnknownFloat3);

    writer.Write(m_UnknownInt1);

}
