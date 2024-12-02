#include "BSShaderTextureSet.hpp"

using namespace nejlika::geometry;

void BSShaderTextureSet::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_NumTextures = reader.Read<int>();

    m_Textures.resize(m_NumTextures);
    for (uint32_t i = 0; i < m_Textures.size(); i++)
    {
        m_Textures[i].Read(reader, version, user, 0);
    }

}

void BSShaderTextureSet::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    writer.Write(m_NumTextures);

    for (uint32_t i = 0; i < m_Textures.size(); i++)
    {
        m_Textures[i].Write(writer, version, user, 0);
    }

}
