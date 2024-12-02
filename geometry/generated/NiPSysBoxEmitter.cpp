#include "NiPSysBoxEmitter.hpp"

using namespace nejlika::geometry;

void NiPSysBoxEmitter::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysVolumeEmitter::Read(reader, version, user, arg);

    m_Width = reader.Read<float>();

    m_Height = reader.Read<float>();

    m_Depth = reader.Read<float>();

}

void NiPSysBoxEmitter::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysVolumeEmitter::Write(writer, version, user, arg);

    writer.Write(m_Width);

    writer.Write(m_Height);

    writer.Write(m_Depth);

}
