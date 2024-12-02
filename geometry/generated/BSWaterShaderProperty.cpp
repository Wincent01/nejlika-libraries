#include "BSWaterShaderProperty.hpp"

using namespace nejlika::geometry;

void BSWaterShaderProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiProperty::Read(reader, version, user, arg);

    m_ShaderFlags1 = reader.Read<SkyrimShaderPropertyFlags1>();

    m_ShaderFlags2 = reader.Read<SkyrimShaderPropertyFlags2>();

    m_UVOffset.Read(reader, version, user, 0);

    m_UVScale.Read(reader, version, user, 0);

    m_WaterShaderFlags = reader.Read<SkyrimWaterShaderFlags>();

    m_WaterDirection = reader.Read<byte>();

    m_UnknownShort3 = reader.Read<ushort>();

}

void BSWaterShaderProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiProperty::Write(writer, version, user, arg);

    writer.Write(m_ShaderFlags1);

    writer.Write(m_ShaderFlags2);

    m_UVOffset.Write(writer, version, user, 0);

    m_UVScale.Write(writer, version, user, 0);

    writer.Write(m_WaterShaderFlags);

    writer.Write(m_WaterDirection);

    writer.Write(m_UnknownShort3);

}
