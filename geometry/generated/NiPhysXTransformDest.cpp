#include "NiPhysXTransformDest.hpp"

using namespace nejlika::geometry;

void NiPhysXTransformDest::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_UnknownByte1 = reader.Read<byte>();

    m_UnknownByte2 = reader.Read<byte>();

    m_Node.Read(reader, version, user, 0);

}

void NiPhysXTransformDest::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    writer.Write(m_UnknownByte1);

    writer.Write(m_UnknownByte2);

    m_Node.Write(writer, version, user, 0);

}
