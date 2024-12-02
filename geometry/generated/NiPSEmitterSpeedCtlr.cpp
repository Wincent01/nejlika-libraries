#include "NiPSEmitterSpeedCtlr.hpp"

using namespace nejlika::geometry;

void NiPSEmitterSpeedCtlr::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTimeController::Read(reader, version, user, arg);

    m_Interpolator.Read(reader, version, user, 0);

    m_Unknown3 = reader.Read<int>();

}

void NiPSEmitterSpeedCtlr::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTimeController::Write(writer, version, user, arg);

    m_Interpolator.Write(writer, version, user, 0);

    writer.Write(m_Unknown3);

}
