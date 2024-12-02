#include "NiColorData.hpp"

using namespace nejlika::geometry;

void NiColorData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_Data.Read(reader, version, user, 0);

}

void NiColorData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    m_Data.Write(writer, version, user, 0);

}
