#include "NiCollisionObject.hpp"

using namespace nejlika::geometry;

void NiCollisionObject::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_Target.Read(reader, version, user, 0);

}

void NiCollisionObject::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    m_Target.Write(writer, version, user, 0);

}
