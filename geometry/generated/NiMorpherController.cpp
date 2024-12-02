#include "NiMorpherController.hpp"

using namespace nejlika::geometry;

void NiMorpherController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiInterpController::Read(reader, version, user, arg);

    m_Data.Read(reader, version, user, 0);

}

void NiMorpherController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiInterpController::Write(writer, version, user, arg);

    m_Data.Write(writer, version, user, 0);

}
