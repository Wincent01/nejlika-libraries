#include "bhkBlendController.hpp"

using namespace nejlika::geometry;

void bhkBlendController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTimeController::Read(reader, version, user, arg);

    m_UnknownInt = reader.Read<uint>();

}

void bhkBlendController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTimeController::Write(writer, version, user, arg);

    writer.Write(m_UnknownInt);

}
