#include "NiRollController.hpp"

using namespace nejlika::geometry;

void NiRollController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiSingleInterpController::Read(reader, version, user, arg);

    m_Data.Read(reader, version, user, 0);

}

void NiRollController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiSingleInterpController::Write(writer, version, user, arg);

    m_Data.Write(writer, version, user, 0);

}
