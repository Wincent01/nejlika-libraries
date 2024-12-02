#include "bhkBlendCollisionObject.hpp"

using namespace nejlika::geometry;

void bhkBlendCollisionObject::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkCollisionObject::Read(reader, version, user, arg);

    m_UnknownFloat1 = reader.Read<float>();

    m_UnknownFloat2 = reader.Read<float>();

}

void bhkBlendCollisionObject::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkCollisionObject::Write(writer, version, user, arg);

    writer.Write(m_UnknownFloat1);

    writer.Write(m_UnknownFloat2);

}
