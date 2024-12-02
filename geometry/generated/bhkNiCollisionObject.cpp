#include "bhkNiCollisionObject.hpp"

using namespace nejlika::geometry;

void bhkNiCollisionObject::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiCollisionObject::Read(reader, version, user, arg);

    m_Flags = reader.Read<Flags>();

    m_Body.Read(reader, version, user, 0);

}

void bhkNiCollisionObject::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiCollisionObject::Write(writer, version, user, arg);

    writer.Write(m_Flags);

    m_Body.Write(writer, version, user, 0);

}
