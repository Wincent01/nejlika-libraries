#include "NiArkShaderExtraData.hpp"

using namespace nejlika::geometry;

void NiArkShaderExtraData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiExtraData::Read(reader, version, user, arg);

    m_UnknownInt = reader.Read<int>();

    m_UnknownString.Read(reader, version, user, 0);

}

void NiArkShaderExtraData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiExtraData::Write(writer, version, user, arg);

    writer.Write(m_UnknownInt);

    m_UnknownString.Write(writer, version, user, 0);

}
