#include "NiPixelData.hpp"

using namespace nejlika::geometry;

void NiPixelData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    ATextureRenderData::Read(reader, version, user, arg);

    m_NumPixels = reader.Read<uint>();

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        m_NumFaces = reader.Read<uint>();
    }
    else
    {
        m_NumFaces = 1;
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
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

    if (version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_PixelData.resize(1);
        for (uint32_t i = 0; i < m_PixelData.size(); i++)
        {
            m_PixelData[i].resize(m_NumPixels);
            for (uint32_t j = 0; j < m_PixelData[i].size(); j++)
            {
                m_PixelData[i][j] = reader.Read<byte>();
            }
        }
    }

}

void NiPixelData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    ATextureRenderData::Write(writer, version, user, arg);

    writer.Write(m_NumPixels);

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        writer.Write(m_NumFaces);
    }
    else
    {
        //writer.Write(1);
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        for (uint32_t i = 0; i < m_PixelData.size(); i++)
        {
            for (uint32_t j = 0; j < m_PixelData[i].size(); j++)
            {
                writer.Write(m_PixelData[i][j]);
            }
        }
    }

    if (version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        for (uint32_t i = 0; i < m_PixelData.size(); i++)
        {
            for (uint32_t j = 0; j < m_PixelData[i].size(); j++)
            {
                writer.Write(m_PixelData[i][j]);
            }
        }
    }

}
