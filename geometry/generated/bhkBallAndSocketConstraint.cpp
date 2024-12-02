#include "bhkBallAndSocketConstraint.hpp"

using namespace nejlika::geometry;

void bhkBallAndSocketConstraint::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkConstraint::Read(reader, version, user, arg);

    m_Unknown4Bytes.resize(4);
    for (uint32_t i = 0; i < m_Unknown4Bytes.size(); i++)
    {
        m_Unknown4Bytes[i] = reader.Read<byte>();
    }

    m_UnknownFloats1.Read(reader, version, user, 0);

    m_UnknownFloats2.Read(reader, version, user, 0);

    m_UnknownInt1 = reader.Read<uint>();

}

void bhkBallAndSocketConstraint::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkConstraint::Write(writer, version, user, arg);

    for (uint32_t i = 0; i < m_Unknown4Bytes.size(); i++)
    {
        writer.Write(m_Unknown4Bytes[i]);
    }

    m_UnknownFloats1.Write(writer, version, user, 0);

    m_UnknownFloats2.Write(writer, version, user, 0);

    writer.Write(m_UnknownInt1);

}
