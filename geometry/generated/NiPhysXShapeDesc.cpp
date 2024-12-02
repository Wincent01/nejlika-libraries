#include "NiPhysXShapeDesc.hpp"

using namespace nejlika::geometry;

void NiPhysXShapeDesc::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_UnknownInt1 = reader.Read<int>();

    m_UnknownQuat1.Read(reader, version, user, 0);

    m_UnknownQuat2.Read(reader, version, user, 0);

    m_UnknownQuat3.Read(reader, version, user, 0);

    m_UnknownShort1 = reader.Read<short>();

    m_UnknownInt2 = reader.Read<int>();

    m_UnknownShort2 = reader.Read<short>();

    m_UnknownFloat1 = reader.Read<float>();

    m_UnknownFloat2 = reader.Read<float>();

    m_UnknownFloat3 = reader.Read<float>();

    m_UnknownInt3 = reader.Read<int>();

    m_UnknownInt4 = reader.Read<int>();

    m_UnknownInt5 = reader.Read<int>();

    m_UnknownInt7 = reader.Read<int>();

    m_UnknownInt8 = reader.Read<int>();

    m_MeshDescription.Read(reader, version, user, 0);

}

void NiPhysXShapeDesc::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    writer.Write(m_UnknownInt1);

    m_UnknownQuat1.Write(writer, version, user, 0);

    m_UnknownQuat2.Write(writer, version, user, 0);

    m_UnknownQuat3.Write(writer, version, user, 0);

    writer.Write(m_UnknownShort1);

    writer.Write(m_UnknownInt2);

    writer.Write(m_UnknownShort2);

    writer.Write(m_UnknownFloat1);

    writer.Write(m_UnknownFloat2);

    writer.Write(m_UnknownFloat3);

    writer.Write(m_UnknownInt3);

    writer.Write(m_UnknownInt4);

    writer.Write(m_UnknownInt5);

    writer.Write(m_UnknownInt7);

    writer.Write(m_UnknownInt8);

    m_MeshDescription.Write(writer, version, user, 0);

}
