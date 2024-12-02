#include "bhkBreakableConstraint.hpp"

using namespace nejlika::geometry;

void bhkBreakableConstraint::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkConstraint::Read(reader, version, user, arg);

    if (user<= 11)
    {
        m_UnknownInts1.resize(41);
        for (uint32_t i = 0; i < m_UnknownInts1.size(); i++)
        {
            m_UnknownInts1[i] = reader.Read<int>();
        }
    }

    if (user<= 11)
    {
        m_UnknownShort1 = reader.Read<short>();
    }

    if (user== 12)
    {
        m_UnknownInt1 = reader.Read<uint>();
    }

    if (user== 12)
    {
        m_NumEntities2 = reader.Read<uint>();
    }

    if (user== 12)
    {
        m_Entities2.resize(m_NumEntities2);
        for (uint32_t i = 0; i < m_Entities2.size(); i++)
        {
            m_Entities2[i].Read(reader, version, user, 0);
        }
    }

    if (user== 12)
    {
        m_Priority2 = reader.Read<uint>();
    }
    else
    {
        m_Priority2 = 1;
    }

    if (user== 12)
    {
        m_UnknownInt2 = reader.Read<uint>();
    }

    if (user== 12)
    {
        m_Position.Read(reader, version, user, 0);
    }

    if (user== 12)
    {
        m_Rotation.Read(reader, version, user, 0);
    }

    if (user== 12)
    {
        m_UnknownInt3 = reader.Read<uint>();
    }

    if (user== 12)
    {
        m_Threshold = reader.Read<float>();
    }

    if (m_UnknownInt1>= 1 && user== 12)
    {
        m_UnknownFloat1 = reader.Read<float>();
    }

    if (user== 12)
    {
        m_RemoveIfBroken = reader.Read<byte>();
    }

}

void bhkBreakableConstraint::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkConstraint::Write(writer, version, user, arg);

    if (user<= 11)
    {
        for (uint32_t i = 0; i < m_UnknownInts1.size(); i++)
        {
            writer.Write(m_UnknownInts1[i]);
        }
    }

    if (user<= 11)
    {
        writer.Write(m_UnknownShort1);
    }

    if (user== 12)
    {
        writer.Write(m_UnknownInt1);
    }

    if (user== 12)
    {
        writer.Write(m_NumEntities2);
    }

    if (user== 12)
    {
        for (uint32_t i = 0; i < m_Entities2.size(); i++)
        {
            m_Entities2[i].Write(writer, version, user, 0);
        }
    }

    if (user== 12)
    {
        writer.Write(m_Priority2);
    }
    else
    {
        //writer.Write(1);
    }

    if (user== 12)
    {
        writer.Write(m_UnknownInt2);
    }

    if (user== 12)
    {
        m_Position.Write(writer, version, user, 0);
    }

    if (user== 12)
    {
        m_Rotation.Write(writer, version, user, 0);
    }

    if (user== 12)
    {
        writer.Write(m_UnknownInt3);
    }

    if (user== 12)
    {
        writer.Write(m_Threshold);
    }

    if (m_UnknownInt1>= 1 && user== 12)
    {
        writer.Write(m_UnknownFloat1);
    }

    if (user== 12)
    {
        writer.Write(m_RemoveIfBroken);
    }

}
