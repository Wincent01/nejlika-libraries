#include "NiPSysSphereEmitter.hpp"

using namespace nejlika::geometry;

void NiPSysSphereEmitter::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysVolumeEmitter::Read(reader, version, user, arg);

    m_Radius = reader.Read<float>();

}

void NiPSysSphereEmitter::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysVolumeEmitter::Write(writer, version, user, arg);

    writer.Write(m_Radius);

}
