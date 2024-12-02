#include "NiPSPlanarCollider.hpp"

using namespace nejlika::geometry;

void NiPSPlanarCollider::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_Name.Read(reader, version, user, 0);

    m_UnknownInt1 = reader.Read<int>();

    m_UnknownInt2 = reader.Read<int>();

    m_UnknownShort3 = reader.Read<short>();

    m_UnknownByte4 = reader.Read<byte>();

    m_UnknownFloats5.resize(8);
    for (uint32_t i = 0; i < m_UnknownFloats5.size(); i++)
    {
        m_UnknownFloats5[i] = reader.Read<float>();
    }

    m_UnknownLink6.Read(reader, version, user, 0);

}

void NiPSPlanarCollider::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    m_Name.Write(writer, version, user, 0);

    writer.Write(m_UnknownInt1);

    writer.Write(m_UnknownInt2);

    writer.Write(m_UnknownShort3);

    writer.Write(m_UnknownByte4);

    for (uint32_t i = 0; i < m_UnknownFloats5.size(); i++)
    {
        writer.Write(m_UnknownFloats5[i]);
    }

    m_UnknownLink6.Write(writer, version, user, 0);

}
