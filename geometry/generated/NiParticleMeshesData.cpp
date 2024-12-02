#include "NiParticleMeshesData.hpp"

using namespace nejlika::geometry;

void NiParticleMeshesData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiRotatingParticlesData::Read(reader, version, user, arg);

    m_UnknownLink2.Read(reader, version, user, 0);

}

void NiParticleMeshesData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiRotatingParticlesData::Write(writer, version, user, arg);

    m_UnknownLink2.Write(writer, version, user, 0);

}
