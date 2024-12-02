#include "NiRawImageData.hpp"

using namespace nejlika::geometry;

void NiRawImageData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_Width = reader.Read<uint>();

    m_Height = reader.Read<uint>();

    m_ImageType = reader.Read<ImageType>();

    if (m_ImageType== 1)
    {
        m_RGBImageData.resize(m_Width);
        for (uint32_t i = 0; i < m_RGBImageData.size(); i++)
        {
            m_RGBImageData[i].resize(m_Height);
            for (uint32_t j = 0; j < m_RGBImageData[i].size(); j++)
            {
                m_RGBImageData[i][j].Read(reader, version, user, 0);
            }
        }
    }

    if (m_ImageType== 2)
    {
        m_RGBAImageData.resize(m_Width);
        for (uint32_t i = 0; i < m_RGBAImageData.size(); i++)
        {
            m_RGBAImageData[i].resize(m_Height);
            for (uint32_t j = 0; j < m_RGBAImageData[i].size(); j++)
            {
                m_RGBAImageData[i][j].Read(reader, version, user, 0);
            }
        }
    }

}

void NiRawImageData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    writer.Write(m_Width);

    writer.Write(m_Height);

    writer.Write(m_ImageType);

    if (m_ImageType== 1)
    {
        for (uint32_t i = 0; i < m_RGBImageData.size(); i++)
        {
            for (uint32_t j = 0; j < m_RGBImageData[i].size(); j++)
            {
                m_RGBImageData[i][j].Write(writer, version, user, 0);
            }
        }
    }

    if (m_ImageType== 2)
    {
        for (uint32_t i = 0; i < m_RGBAImageData.size(); i++)
        {
            for (uint32_t j = 0; j < m_RGBAImageData[i].size(); j++)
            {
                m_RGBAImageData[i][j].Write(writer, version, user, 0);
            }
        }
    }

}
