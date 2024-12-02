#include "LimitedHingeDescriptor.hpp"

using namespace nejlika::geometry;

void LimitedHingeDescriptor::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_PivotA.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_AxleA.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_Perp2AxleInA1.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_Perp2AxleInA2.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_PivotB.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_AxleB.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_Perp2AxleInB2.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_AxleA.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_Perp2AxleInA1.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_Perp2AxleInA2.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_PivotA.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_AxleB.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_Perp2AxleInB1.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_Perp2AxleInB2.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_PivotB.Read(reader, version, user, 0);
    }

    m_MinAngle = reader.Read<float>();

    m_MaxAngle = reader.Read<float>();

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

void LimitedHingeDescriptor::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_PivotA.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_AxleA.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_Perp2AxleInA1.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_Perp2AxleInA2.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_PivotB.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_AxleB.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_Perp2AxleInB2.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_AxleA.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_Perp2AxleInA1.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_Perp2AxleInA2.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_PivotA.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_AxleB.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_Perp2AxleInB1.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_Perp2AxleInB2.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_PivotB.Write(writer, version, user, 0);
    }

    writer.Write(m_MinAngle);

    writer.Write(m_MaxAngle);

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
