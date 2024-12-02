#include "NiPersistentSrcTextureRendererData.hpp"

using namespace nejlika::geometry;

void NiPersistentSrcTextureRendererData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    ATextureRenderData::Read(reader, version, user, arg);

    m_NumPixels = reader.Read<uint>();

    m_UnknownInt6 = reader.Read<uint>();

    m_NumFaces = reader.Read<uint>();

    m_UnknownInt7 = reader.Read<uint>();

    m_PixelData.resize(m_NumFaces);
    for (uint32_t i = 0; i < m_PixelData.size(); i++)
    {
        m_PixelData[i].resize(m_NumPixels);
        for (uint32_t j = 0; j < m_PixelData[i].size(); j++)
        {
            m_PixelData[i][j] = reader.Read<byte>();
        }
    }

}

void NiPersistentSrcTextureRendererData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    ATextureRenderData::Write(writer, version, user, arg);

    writer.Write(m_NumPixels);

    writer.Write(m_UnknownInt6);

    writer.Write(m_NumFaces);

    writer.Write(m_UnknownInt7);

    for (uint32_t i = 0; i < m_PixelData.size(); i++)
    {
        for (uint32_t j = 0; j < m_PixelData[i].size(); j++)
        {
            writer.Write(m_PixelData[i][j]);
        }
    }

}
