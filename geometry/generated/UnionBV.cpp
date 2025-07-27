#include "UnionBV.hpp"

#include "BoundingVolume.hpp"

using namespace nejlika::geometry;

void UnionBV::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_NumBV = reader.Read<uint>();

    m_BoundingVolumes.resize(m_NumBV);
    for (uint32_t i = 0; i < m_BoundingVolumes.size(); i++)
    {
        m_BoundingVolumes[i]->Read(reader, version, user, 0);
    }

}

void UnionBV::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_NumBV);

    for (uint32_t i = 0; i < m_BoundingVolumes.size(); i++)
    {
        m_BoundingVolumes[i]->Write(writer, version, user, 0);
    }

}

void UnionBV::SetBoundingVolumes(const std::vector<std::shared_ptr<BoundingVolume>> &value)
{
    m_BoundingVolumes.clear();
    m_BoundingVolumes.reserve(value.size());

    for (const auto &bv : value)
    {
        m_BoundingVolumes.emplace_back(std::make_shared<BoundingVolume>(*bv));
    }

    m_NumBV = static_cast<uint>(m_BoundingVolumes.size());
}

UnionBV &UnionBV::operator=(const UnionBV &other)
{
    if (this != &other)
    {
        m_NumBV = other.m_NumBV;

        m_BoundingVolumes.clear();
        m_BoundingVolumes.reserve(other.m_BoundingVolumes.size());

        for (const auto &bv : other.m_BoundingVolumes)
        {
            m_BoundingVolumes.emplace_back(std::make_shared<BoundingVolume>(*bv));
        }
    }

    return *this;
}