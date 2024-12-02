#include "NiPSCylinderEmitter.hpp"

using namespace nejlika::geometry;

void NiPSCylinderEmitter::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSSphereEmitter::Read(reader, version, user, arg);

    m_Unknown23 = reader.Read<float>();

}

void NiPSCylinderEmitter::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSSphereEmitter::Write(writer, version, user, arg);

    writer.Write(m_Unknown23);

}
