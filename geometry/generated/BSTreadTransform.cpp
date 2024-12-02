#include "BSTreadTransform.hpp"

using namespace nejlika::geometry;

void BSTreadTransform::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Name.Read(reader, version, user, 0);

    m_Transform1.Read(reader, version, user, 0);

    m_Transform2.Read(reader, version, user, 0);

}

void BSTreadTransform::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    m_Name.Write(writer, version, user, 0);

    m_Transform1.Write(writer, version, user, 0);

    m_Transform2.Write(writer, version, user, 0);

}
