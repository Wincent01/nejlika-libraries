#include "SkinShape.hpp"

using namespace nejlika::geometry;

void SkinShape::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Shape.Read(reader, version, user, 0);

    m_SkinInstance.Read(reader, version, user, 0);

}

void SkinShape::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    m_Shape.Write(writer, version, user, 0);

    m_SkinInstance.Write(writer, version, user, 0);

}
