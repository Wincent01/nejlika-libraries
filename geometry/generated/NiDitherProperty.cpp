#include "NiDitherProperty.hpp"

using namespace nejlika::geometry;

void NiDitherProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiProperty::Read(reader, version, user, arg);

    m_Flags = reader.Read<Flags>();

}

void NiDitherProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiProperty::Write(writer, version, user, arg);

    writer.Write(m_Flags);

}
