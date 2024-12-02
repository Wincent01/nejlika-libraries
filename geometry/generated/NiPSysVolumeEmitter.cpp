#include "NiPSysVolumeEmitter.hpp"

using namespace nejlika::geometry;

void NiPSysVolumeEmitter::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysEmitter::Read(reader, version, user, arg);

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_EmitterObject.Read(reader, version, user, 0);
    }

}

void NiPSysVolumeEmitter::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysEmitter::Write(writer, version, user, arg);

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_EmitterObject.Write(writer, version, user, 0);
    }

}
