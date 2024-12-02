#include "NiInstancingMeshModifier.hpp"

using namespace nejlika::geometry;

void NiInstancingMeshModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiMeshModifier::Read(reader, version, user, arg);

}

void NiInstancingMeshModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiMeshModifier::Write(writer, version, user, arg);

}
