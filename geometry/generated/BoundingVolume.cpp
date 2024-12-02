#include "BoundingVolume.hpp"

using namespace nejlika::geometry;

void BoundingVolume::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_CollisionType = reader.Read<BoundVolumeType>();

    if (m_CollisionType== 0)
    {
        m_Sphere.Read(reader, version, user, 0);
    }

    if (m_CollisionType== 1)
    {
        m_Box.Read(reader, version, user, 0);
    }

    if (m_CollisionType== 2)
    {
        m_Capsule.Read(reader, version, user, 0);
    }

    if (m_CollisionType== 4)
    {
        m_Union.Read(reader, version, user, 0);
    }

    if (m_CollisionType== 5)
    {
        m_HalfSpace.Read(reader, version, user, 0);
    }

}

void BoundingVolume::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_CollisionType);

    if (m_CollisionType== 0)
    {
        m_Sphere.Write(writer, version, user, 0);
    }

    if (m_CollisionType== 1)
    {
        m_Box.Write(writer, version, user, 0);
    }

    if (m_CollisionType== 2)
    {
        m_Capsule.Write(writer, version, user, 0);
    }

    if (m_CollisionType== 4)
    {
        m_Union.Write(writer, version, user, 0);
    }

    if (m_CollisionType== 5)
    {
        m_HalfSpace.Write(writer, version, user, 0);
    }

}
