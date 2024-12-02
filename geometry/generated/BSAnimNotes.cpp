#include "BSAnimNotes.hpp"

using namespace nejlika::geometry;

void BSAnimNotes::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_UnknownShort1 = reader.Read<short>();

}

void BSAnimNotes::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    writer.Write(m_UnknownShort1);

}
