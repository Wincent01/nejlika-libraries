#include "ShaderTexDesc.hpp"

using namespace nejlika::geometry;

void ShaderTexDesc::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_IsUsed = reader.Read<bool>();

    if (m_IsUsed)
    {
        m_TextureData.Read(reader, version, user, 0);
    }

    if (m_IsUsed)
    {
        m_MapIndex = reader.Read<uint>();
    }

}

void ShaderTexDesc::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_IsUsed);

    if (m_IsUsed)
    {
        m_TextureData.Write(writer, version, user, 0);
    }

    if (m_IsUsed)
    {
        writer.Write(m_MapIndex);
    }

}
