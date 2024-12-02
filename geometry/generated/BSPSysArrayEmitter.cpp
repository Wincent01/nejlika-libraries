#include "BSPSysArrayEmitter.hpp"

using namespace nejlika::geometry;

void BSPSysArrayEmitter::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysVolumeEmitter::Read(reader, version, user, arg);

}

void BSPSysArrayEmitter::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysVolumeEmitter::Write(writer, version, user, arg);

}
