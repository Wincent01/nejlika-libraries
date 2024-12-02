#include "UnionBV.hpp"

#include "BoundingVolume.hpp"

using namespace nejlika::geometry;

void UnionBV::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_NumBV = reader.Read<uint>();

    m_BoundingVolumes.resize(m_NumBV);
    for (uint32_t i = 0; i < m_BoundingVolumes.size(); i++)
    {
        m_BoundingVolumes[i].Read(reader, version, user, 0);
    }

}

void UnionBV::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_NumBV);

    for (uint32_t i = 0; i < m_BoundingVolumes.size(); i++)
    {
        m_BoundingVolumes[i].Write(writer, version, user, 0);
    }

}
