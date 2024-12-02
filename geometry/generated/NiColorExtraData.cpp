#include "NiColorExtraData.hpp"

using namespace nejlika::geometry;

void NiColorExtraData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiExtraData::Read(reader, version, user, arg);

    m_Data.Read(reader, version, user, 0);

}

void NiColorExtraData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiExtraData::Write(writer, version, user, arg);

    m_Data.Write(writer, version, user, 0);

}
