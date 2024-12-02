#include "bhkCapsuleShape.hpp"

using namespace nejlika::geometry;

void bhkCapsuleShape::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkConvexShape::Read(reader, version, user, arg);

    m_Unknown8Bytes.resize(8);
    for (uint32_t i = 0; i < m_Unknown8Bytes.size(); i++)
    {
        m_Unknown8Bytes[i] = reader.Read<byte>();
    }

    m_FirstPoint.Read(reader, version, user, 0);

    m_Radius1 = reader.Read<float>();

    m_SecondPoint.Read(reader, version, user, 0);

    m_Radius2 = reader.Read<float>();

}

void bhkCapsuleShape::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkConvexShape::Write(writer, version, user, arg);

    for (uint32_t i = 0; i < m_Unknown8Bytes.size(); i++)
    {
        writer.Write(m_Unknown8Bytes[i]);
    }

    m_FirstPoint.Write(writer, version, user, 0);

    writer.Write(m_Radius1);

    m_SecondPoint.Write(writer, version, user, 0);

    writer.Write(m_Radius2);

}
