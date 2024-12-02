#include "NiSingleInterpController.hpp"

using namespace nejlika::geometry;

void NiSingleInterpController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiInterpController::Read(reader, version, user, arg);

    if (version >= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_Interpolator.Read(reader, version, user, 0);
    }

}

void NiSingleInterpController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiInterpController::Write(writer, version, user, arg);

    if (version >= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_Interpolator.Write(writer, version, user, 0);
    }

}
