#include "BoundingBox.hpp"

using namespace nejlika::geometry;

void BoundingBox::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_UnknownInt = reader.Read<uint>();

    m_Translation.Read(reader, version, user, 0);

    m_Rotation.Read(reader, version, user, 0);

    m_Radius.Read(reader, version, user, 0);

}

void BoundingBox::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_UnknownInt);

    m_Translation.Write(writer, version, user, 0);

    m_Rotation.Write(writer, version, user, 0);

    m_Radius.Write(writer, version, user, 0);

}
