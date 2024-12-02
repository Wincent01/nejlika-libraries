#include "physXMaterialRef.hpp"

using namespace nejlika::geometry;

void physXMaterialRef::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Number = reader.Read<byte>();

    m_UnknownByte1 = reader.Read<byte>();

    m_MaterialDesc.Read(reader, version, user, 0);

}

void physXMaterialRef::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_Number);

    writer.Write(m_UnknownByte1);

    m_MaterialDesc.Write(writer, version, user, 0);

}
