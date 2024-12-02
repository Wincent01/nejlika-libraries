#include "NiStringPalette.hpp"

using namespace nejlika::geometry;

void NiStringPalette::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_Palette.Read(reader, version, user, 0);

}

void NiStringPalette::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    m_Palette.Write(writer, version, user, 0);

}
