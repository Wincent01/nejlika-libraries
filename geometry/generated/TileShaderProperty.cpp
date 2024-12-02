#include "TileShaderProperty.hpp"

using namespace nejlika::geometry;

void TileShaderProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    BSShaderLightingProperty::Read(reader, version, user, arg);

    m_FileName.Read(reader, version, user, 0);

}

void TileShaderProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    BSShaderLightingProperty::Write(writer, version, user, arg);

    m_FileName.Write(writer, version, user, 0);

}
