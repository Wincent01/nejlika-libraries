#include "NiIntegerExtraData.hpp"

using namespace nejlika::geometry;

void NiIntegerExtraData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiExtraData::Read(reader, version, user, arg);

    m_IntegerData = reader.Read<uint>();

}

void NiIntegerExtraData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiExtraData::Write(writer, version, user, arg);

    writer.Write(m_IntegerData);

}
