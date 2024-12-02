#include "NiCollisionData.hpp"

using namespace nejlika::geometry;

void NiCollisionData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiCollisionObject::Read(reader, version, user, arg);

    m_PropagationMode = reader.Read<PropagationMode>();

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_CollisionMode = reader.Read<CollisionMode>();
    }

    m_UseABV = reader.Read<byte>();

    if (m_UseABV== 1)
    {
        m_BoundingVolume.Read(reader, version, user, 0);
    }

}

void NiCollisionData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiCollisionObject::Write(writer, version, user, arg);

    writer.Write(m_PropagationMode);

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_CollisionMode);
    }

    writer.Write(m_UseABV);

    if (m_UseABV== 1)
    {
        m_BoundingVolume.Write(writer, version, user, 0);
    }

}
