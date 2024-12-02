#include "BSPSysSubTexModifier.hpp"

using namespace nejlika::geometry;

void BSPSysSubTexModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysModifier::Read(reader, version, user, arg);

    m_StartFrame = reader.Read<uint>();

    m_StartFrameFudge = reader.Read<float>();

    m_EndFrame = reader.Read<float>();

    m_LoopStartFrame = reader.Read<float>();

    m_LoopStartFrameFudge = reader.Read<float>();

    m_FrameCount = reader.Read<float>();

    m_FrameCountFudge = reader.Read<float>();

}

void BSPSysSubTexModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysModifier::Write(writer, version, user, arg);

    writer.Write(m_StartFrame);

    writer.Write(m_StartFrameFudge);

    writer.Write(m_EndFrame);

    writer.Write(m_LoopStartFrame);

    writer.Write(m_LoopStartFrameFudge);

    writer.Write(m_FrameCount);

    writer.Write(m_FrameCountFudge);

}
