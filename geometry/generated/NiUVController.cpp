#include "NiUVController.hpp"

using namespace nejlika::geometry;

void NiUVController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTimeController::Read(reader, version, user, arg);

    m_UnknownShort = reader.Read<ushort>();

    m_Data.Read(reader, version, user, 0);

}

void NiUVController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTimeController::Write(writer, version, user, arg);

    writer.Write(m_UnknownShort);

    m_Data.Write(writer, version, user, 0);

}
