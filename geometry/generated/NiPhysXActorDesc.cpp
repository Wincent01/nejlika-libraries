#include "NiPhysXActorDesc.hpp"

using namespace nejlika::geometry;

void NiPhysXActorDesc::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_UnknownInt1 = reader.Read<int>();

    m_UnknownInt2 = reader.Read<int>();

    m_UnknownQuat1.Read(reader, version, user, 0);

    m_UnknownQuat2.Read(reader, version, user, 0);

    m_UnknownQuat3.Read(reader, version, user, 0);

    m_UnknownRef0.Read(reader, version, user, 0);

    m_UnknownInt4 = reader.Read<float>();

    m_UnknownInt5 = reader.Read<int>();

    m_UnknownByte1 = reader.Read<byte>();

    m_UnknownByte2 = reader.Read<byte>();

    m_UnknownInt6 = reader.Read<int>();

    m_ShapeDescription.Read(reader, version, user, 0);

    m_UnknownRef1.Read(reader, version, user, 0);

    m_UnknownRef2.Read(reader, version, user, 0);

    m_UnknownRefs3.resize(m_UnknownInt6);
    for (uint32_t i = 0; i < m_UnknownRefs3.size(); i++)
    {
        m_UnknownRefs3[i].Read(reader, version, user, 0);
    }

}

void NiPhysXActorDesc::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    writer.Write(m_UnknownInt1);

    writer.Write(m_UnknownInt2);

    m_UnknownQuat1.Write(writer, version, user, 0);

    m_UnknownQuat2.Write(writer, version, user, 0);

    m_UnknownQuat3.Write(writer, version, user, 0);

    m_UnknownRef0.Write(writer, version, user, 0);

    writer.Write(m_UnknownInt4);

    writer.Write(m_UnknownInt5);

    writer.Write(m_UnknownByte1);

    writer.Write(m_UnknownByte2);

    writer.Write(m_UnknownInt6);

    m_ShapeDescription.Write(writer, version, user, 0);

    m_UnknownRef1.Write(writer, version, user, 0);

    m_UnknownRef2.Write(writer, version, user, 0);

    for (uint32_t i = 0; i < m_UnknownRefs3.size(); i++)
    {
        m_UnknownRefs3[i].Write(writer, version, user, 0);
    }

}
