#include "TallGrassShaderProperty.hpp"

using namespace nejlika::geometry;

void TallGrassShaderProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    BSShaderProperty::Read(reader, version, user, arg);

    m_FileName.Read(reader, version, user, 0);

}

void TallGrassShaderProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    BSShaderProperty::Write(writer, version, user, arg);

    m_FileName.Write(writer, version, user, 0);

}