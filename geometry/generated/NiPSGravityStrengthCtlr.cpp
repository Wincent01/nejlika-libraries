#include "NiPSGravityStrengthCtlr.hpp"

using namespace nejlika::geometry;

void NiPSGravityStrengthCtlr::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTimeController::Read(reader, version, user, arg);

    m_Unknown2 = reader.Read<int>();

    m_Unknown3 = reader.Read<int>();

}

void NiPSGravityStrengthCtlr::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTimeController::Write(writer, version, user, arg);

    writer.Write(m_Unknown2);

    writer.Write(m_Unknown3);

}
