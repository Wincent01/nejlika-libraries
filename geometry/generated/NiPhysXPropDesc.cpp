#include "NiPhysXPropDesc.hpp"

using namespace nejlika::geometry;

void NiPhysXPropDesc::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_NumDests = reader.Read<int>();

    m_ActorDescs.resize(m_NumDests);
    for (uint32_t i = 0; i < m_ActorDescs.size(); i++)
    {
        m_ActorDescs[i].Read(reader, version, user, 0);
    }

    m_NumJoints = reader.Read<uint>();

    m_JointDescs.resize(m_NumJoints);
    for (uint32_t i = 0; i < m_JointDescs.size(); i++)
    {
        m_JointDescs[i].Read(reader, version, user, 0);
    }

    m_UnknownInt1 = reader.Read<int>();

    m_NumMaterials = reader.Read<uint>();

    m_MaterialDescs.resize(m_NumMaterials);
    for (uint32_t i = 0; i < m_MaterialDescs.size(); i++)
    {
        m_MaterialDescs[i].Read(reader, version, user, 0);
    }

    m_UnknownInt2 = reader.Read<uint>();

    if (version >= VERSION_NUMBER(20, 5, 0, 0))
    {
        m_UnknownInt3 = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(20, 5, 0, 0))
    {
        m_UnknownString4.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 5, 0, 0))
    {
        m_UnknownInt5 = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(20, 5, 0, 0))
    {
        m_UnknownByte6 = reader.Read<byte>();
    }

}

void NiPhysXPropDesc::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    writer.Write(m_NumDests);

    for (uint32_t i = 0; i < m_ActorDescs.size(); i++)
    {
        m_ActorDescs[i].Write(writer, version, user, 0);
    }

    writer.Write(m_NumJoints);

    for (uint32_t i = 0; i < m_JointDescs.size(); i++)
    {
        m_JointDescs[i].Write(writer, version, user, 0);
    }

    writer.Write(m_UnknownInt1);

    writer.Write(m_NumMaterials);

    for (uint32_t i = 0; i < m_MaterialDescs.size(); i++)
    {
        m_MaterialDescs[i].Write(writer, version, user, 0);
    }

    writer.Write(m_UnknownInt2);

    if (version >= VERSION_NUMBER(20, 5, 0, 0))
    {
        writer.Write(m_UnknownInt3);
    }

    if (version >= VERSION_NUMBER(20, 5, 0, 0))
    {
        m_UnknownString4.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 5, 0, 0))
    {
        writer.Write(m_UnknownInt5);
    }

    if (version >= VERSION_NUMBER(20, 5, 0, 0))
    {
        writer.Write(m_UnknownByte6);
    }

}
