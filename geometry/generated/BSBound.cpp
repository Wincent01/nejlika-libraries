#include "BSBound.hpp"

using namespace nejlika::geometry;

void BSBound::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiExtraData::Read(reader, version, user, arg);

    m_Center.Read(reader, version, user, 0);

    m_Dimensions.Read(reader, version, user, 0);

}

void BSBound::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiExtraData::Write(writer, version, user, arg);

    m_Center.Write(writer, version, user, 0);

    m_Dimensions.Write(writer, version, user, 0);

}
