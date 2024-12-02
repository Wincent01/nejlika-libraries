#include "AVObject.hpp"

using namespace nejlika::geometry;

void AVObject::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Name.Read(reader, version, user, 0);

    m_AVObject.Read(reader, version, user, 0);

}

void AVObject::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    m_Name.Write(writer, version, user, 0);

    m_AVObject.Write(writer, version, user, 0);

}
