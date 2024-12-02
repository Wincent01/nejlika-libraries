#include "bhkMalleableConstraint.hpp"

using namespace nejlika::geometry;

void bhkMalleableConstraint::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkConstraint::Read(reader, version, user, arg);

    m_Type = reader.Read<uint>();

    m_UnknownInt2 = reader.Read<uint>();

    m_UnknownLink1.Read(reader, version, user, 0);

    m_UnknownLink2.Read(reader, version, user, 0);

    m_UnknownInt3 = reader.Read<uint>();

    if (m_Type== 1)
    {
        m_Hinge.Read(reader, version, user, 0);
    }

    if (m_Type== 7)
    {
        m_Ragdoll.Read(reader, version, user, 0);
    }

    if (m_Type== 2)
    {
        m_LimitedHinge.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_Tau = reader.Read<float>();
    }

    m_Damping = reader.Read<float>();

}

void bhkMalleableConstraint::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkConstraint::Write(writer, version, user, arg);

    writer.Write(m_Type);

    writer.Write(m_UnknownInt2);

    m_UnknownLink1.Write(writer, version, user, 0);

    m_UnknownLink2.Write(writer, version, user, 0);

    writer.Write(m_UnknownInt3);

    if (m_Type== 1)
    {
        m_Hinge.Write(writer, version, user, 0);
    }

    if (m_Type== 7)
    {
        m_Ragdoll.Write(writer, version, user, 0);
    }

    if (m_Type== 2)
    {
        m_LimitedHinge.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        writer.Write(m_Tau);
    }

    writer.Write(m_Damping);

}
