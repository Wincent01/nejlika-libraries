#include "NiPoint3InterpController.hpp"

using namespace nejlika::geometry;

void NiPoint3InterpController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiSingleInterpController::Read(reader, version, user, arg);

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_TargetColor = reader.Read<TargetColor>();
    }

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_Data.Read(reader, version, user, 0);
    }

}

void NiPoint3InterpController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiSingleInterpController::Write(writer, version, user, arg);

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_TargetColor);
    }

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_Data.Write(writer, version, user, 0);
    }

}
