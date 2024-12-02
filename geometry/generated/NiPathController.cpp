#include "NiPathController.hpp"

using namespace nejlika::geometry;

void NiPathController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTimeController::Read(reader, version, user, arg);

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_UnknownShort2 = reader.Read<ushort>();
    }

    m_UnknownInt1 = reader.Read<uint>();

    m_UnknownFloat2 = reader.Read<float>();

    m_UnknownFloat3 = reader.Read<float>();

    m_UnknownShort = reader.Read<ushort>();

    m_PosData.Read(reader, version, user, 0);

    m_FloatData.Read(reader, version, user, 0);

}

void NiPathController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTimeController::Write(writer, version, user, arg);

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_UnknownShort2);
    }

    writer.Write(m_UnknownInt1);

    writer.Write(m_UnknownFloat2);

    writer.Write(m_UnknownFloat3);

    writer.Write(m_UnknownShort);

    m_PosData.Write(writer, version, user, 0);

    m_FloatData.Write(writer, version, user, 0);

}
