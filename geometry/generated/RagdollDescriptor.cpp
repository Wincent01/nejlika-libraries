#include "RagdollDescriptor.hpp"

using namespace nejlika::geometry;

void RagdollDescriptor::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_PivotA.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_PlaneA.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_TwistA.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_PivotB.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_PlaneB.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_TwistB.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_TwistA.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_PlaneA.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_MotorA.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_PivotA.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_TwistB.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_PlaneB.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_MotorB.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_PivotB.Read(reader, version, user, 0);
    }

    m_ConeMaxAngle = reader.Read<float>();

    m_PlaneMinAngle = reader.Read<float>();

    m_PlaneMaxAngle = reader.Read<float>();

    m_TwistMinAngle = reader.Read<float>();

    m_TwistMaxAngle = reader.Read<float>();

    m_MaxFriction = reader.Read<float>();

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_EnableMotor = reader.Read<bool>();
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && m_EnableMotor)
    {
        m_Motor.Read(reader, version, user, 0);
    }

}

void RagdollDescriptor::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_PivotA.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_PlaneA.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_TwistA.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_PivotB.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_PlaneB.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_TwistB.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_TwistA.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_PlaneA.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_MotorA.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_PivotA.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_TwistB.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_PlaneB.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_MotorB.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_PivotB.Write(writer, version, user, 0);
    }

    writer.Write(m_ConeMaxAngle);

    writer.Write(m_PlaneMinAngle);

    writer.Write(m_PlaneMaxAngle);

    writer.Write(m_TwistMinAngle);

    writer.Write(m_TwistMaxAngle);

    writer.Write(m_MaxFriction);

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        writer.Write(m_EnableMotor);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && m_EnableMotor)
    {
        m_Motor.Write(writer, version, user, 0);
    }

}
