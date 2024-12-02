#include "NiPhysXMaterialDesc.hpp"

using namespace nejlika::geometry;

void NiPhysXMaterialDesc::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_UnknownInt.resize(12);
    for (uint32_t i = 0; i < m_UnknownInt.size(); i++)
    {
        m_UnknownInt[i] = reader.Read<uint>();
    }

    m_UnknownByte1 = reader.Read<byte>();

    m_UnknownByte2 = reader.Read<byte>();

}

void NiPhysXMaterialDesc::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    for (uint32_t i = 0; i < m_UnknownInt.size(); i++)
    {
        writer.Write(m_UnknownInt[i]);
    }

    writer.Write(m_UnknownByte1);

    writer.Write(m_UnknownByte2);

}
