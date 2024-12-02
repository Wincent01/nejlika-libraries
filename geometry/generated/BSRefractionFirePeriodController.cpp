#include "BSRefractionFirePeriodController.hpp"

using namespace nejlika::geometry;

void BSRefractionFirePeriodController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTimeController::Read(reader, version, user, arg);

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_Interpolator.Read(reader, version, user, 0);
    }

}

void BSRefractionFirePeriodController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTimeController::Write(writer, version, user, arg);

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_Interpolator.Write(writer, version, user, 0);
    }

}
