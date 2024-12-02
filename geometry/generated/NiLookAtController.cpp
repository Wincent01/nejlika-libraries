#include "NiLookAtController.hpp"

using namespace nejlika::geometry;

void NiLookAtController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTimeController::Read(reader, version, user, arg);

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_Unknown1 = reader.Read<ushort>();
    }

    m_LookAtNode.Read(reader, version, user, 0);

}

void NiLookAtController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTimeController::Write(writer, version, user, arg);

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_Unknown1);
    }

    m_LookAtNode.Write(writer, version, user, 0);

}
