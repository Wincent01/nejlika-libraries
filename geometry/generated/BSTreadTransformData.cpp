#include "BSTreadTransformData.hpp"

using namespace nejlika::geometry;

void BSTreadTransformData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Translation.Read(reader, version, user, 0);

    m_Rotation.Read(reader, version, user, 0);

    m_Scale = reader.Read<float>();

}

void BSTreadTransformData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    m_Translation.Write(writer, version, user, 0);

    m_Rotation.Write(writer, version, user, 0);

    writer.Write(m_Scale);

}
