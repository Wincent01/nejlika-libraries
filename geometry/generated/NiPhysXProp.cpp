#include "NiPhysXProp.hpp"

using namespace nejlika::geometry;

void NiPhysXProp::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObjectNET::Read(reader, version, user, arg);

    m_UnknownFloat1 = reader.Read<float>();

    m_UnknownInt1 = reader.Read<uint>();

    m_UnknownRefs1.resize(m_UnknownInt1);
    for (uint32_t i = 0; i < m_UnknownRefs1.size(); i++)
    {
        m_UnknownRefs1[i].Read(reader, version, user, 0);
    }

    m_NumDests = reader.Read<int>();

    m_TransformDests.resize(m_NumDests);
    for (uint32_t i = 0; i < m_TransformDests.size(); i++)
    {
        m_TransformDests[i].Read(reader, version, user, 0);
    }

    m_UnknownByte = reader.Read<byte>();

    if (version >= VERSION_NUMBER(20, 5, 0, 0))
    {
        m_UnknownInt = reader.Read<int>();
    }

    m_PropDescription.Read(reader, version, user, 0);

}

void NiPhysXProp::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObjectNET::Write(writer, version, user, arg);

    writer.Write(m_UnknownFloat1);

    writer.Write(m_UnknownInt1);

    for (uint32_t i = 0; i < m_UnknownRefs1.size(); i++)
    {
        m_UnknownRefs1[i].Write(writer, version, user, 0);
    }

    writer.Write(m_NumDests);

    for (uint32_t i = 0; i < m_TransformDests.size(); i++)
    {
        m_TransformDests[i].Write(writer, version, user, 0);
    }

    writer.Write(m_UnknownByte);

    if (version >= VERSION_NUMBER(20, 5, 0, 0))
    {
        writer.Write(m_UnknownInt);
    }

    m_PropDescription.Write(writer, version, user, 0);

}
