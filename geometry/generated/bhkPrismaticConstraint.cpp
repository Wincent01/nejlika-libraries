#include "bhkPrismaticConstraint.hpp"

using namespace nejlika::geometry;

void bhkPrismaticConstraint::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkConstraint::Read(reader, version, user, arg);

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_PivotA.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_RotationMatrixA.resize(4);
        for (uint32_t i = 0; i < m_RotationMatrixA.size(); i++)
        {
            m_RotationMatrixA[i].Read(reader, version, user, 0);
        }
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_PivotB.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_SlidingB.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_PlaneB.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_SlidingA.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_RotationA.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_PlaneA.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_PivotA.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_SlidingB.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_RotationB.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_PlaneB.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_PivotB.Read(reader, version, user, 0);
    }

    m_MinDistance = reader.Read<float>();

    m_MaxDistance = reader.Read<float>();

    m_Friction = reader.Read<float>();

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_UnknownByte1 = reader.Read<byte>();
    }
    else
    {
        m_UnknownByte1 = 0;
    }

}

void bhkPrismaticConstraint::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkConstraint::Write(writer, version, user, arg);

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_PivotA.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        for (uint32_t i = 0; i < m_RotationMatrixA.size(); i++)
        {
            m_RotationMatrixA[i].Write(writer, version, user, 0);
        }
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_PivotB.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_SlidingB.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_PlaneB.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_SlidingA.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_RotationA.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_PlaneA.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_PivotA.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_SlidingB.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_RotationB.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_PlaneB.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_PivotB.Write(writer, version, user, 0);
    }

    writer.Write(m_MinDistance);

    writer.Write(m_MaxDistance);

    writer.Write(m_Friction);

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        writer.Write(m_UnknownByte1);
    }
    else
    {
        //writer.Write(0);
    }

}
