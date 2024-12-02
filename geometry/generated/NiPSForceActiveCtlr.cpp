#include "NiPSForceActiveCtlr.hpp"

using namespace nejlika::geometry;

void NiPSForceActiveCtlr::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTimeController::Read(reader, version, user, arg);

    m_Interpolator.Read(reader, version, user, 0);

    m_Unknown2 = reader.Read<int>();

}

void NiPSForceActiveCtlr::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTimeController::Write(writer, version, user, arg);

    m_Interpolator.Write(writer, version, user, 0);

    writer.Write(m_Unknown2);

}
