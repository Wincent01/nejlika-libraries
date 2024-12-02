#include "BSShaderLightingProperty.hpp"

using namespace nejlika::geometry;

void BSShaderLightingProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    BSShaderProperty::Read(reader, version, user, arg);

    if (user<= 11)
    {
        m_UnknownInt3 = reader.Read<int>();
    }
    else
    {
        m_UnknownInt3 = 3;
    }

}

void BSShaderLightingProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    BSShaderProperty::Write(writer, version, user, arg);

    if (user<= 11)
    {
        writer.Write(m_UnknownInt3);
    }
    else
    {
        //writer.Write(3);
    }

}
