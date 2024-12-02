#include "LODRange.hpp"

using namespace nejlika::geometry;

void LODRange::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_NearExtent = reader.Read<float>();

    m_FarExtent = reader.Read<float>();

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_UnknownInts.resize(3);
        for (uint32_t i = 0; i < m_UnknownInts.size(); i++)
        {
            m_UnknownInts[i] = reader.Read<uint>();
        }
    }

}

void LODRange::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_NearExtent);

    writer.Write(m_FarExtent);

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        for (uint32_t i = 0; i < m_UnknownInts.size(); i++)
        {
            writer.Write(m_UnknownInts[i]);
        }
    }

}
