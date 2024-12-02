#include "NiFloatExtraData.hpp"

using namespace nejlika::geometry;

void NiFloatExtraData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiExtraData::Read(reader, version, user, arg);

    m_FloatData = reader.Read<float>();

}

void NiFloatExtraData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiExtraData::Write(writer, version, user, arg);

    writer.Write(m_FloatData);

}
