#include "NiEnvMappedTriShapeData.hpp"

using namespace nejlika::geometry;

void NiEnvMappedTriShapeData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTriShapeData::Read(reader, version, user, arg);

}

void NiEnvMappedTriShapeData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTriShapeData::Write(writer, version, user, arg);

}
