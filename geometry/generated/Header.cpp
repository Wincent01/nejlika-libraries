#include "Header.hpp"

using namespace nejlika::geometry;

void Header::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_HeaderString = "";
    // Read until 0x0A
    while (true)
    {
        char c = reader.Read<char>();
        if (c == 0x0A)
        {
            break;
        }
        m_HeaderString += c;
    }

    if (false && version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_Copyright.resize(3);
        for (uint32_t i = 0; i < m_Copyright.size(); i++)
        {
            m_Copyright[i] = "";
            // Read until 0x0A
            while (true)
            {
                char c = reader.Read<char>();
                if (c == 0x0A)
                {
                    break;
                }
                m_Copyright[i] += c;
            }
        }
    }

    if (true || version >= VERSION_NUMBER(3, 3, 0, 13))
    {
        version = m_Version = reader.Read<FileVersion>();
    }
    else
    {
        m_Version = 0x04000002;
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        m_EndianType = reader.Read<EndianType>();
    }
    else
    {
        m_EndianType = static_cast<EndianType>(ENDIAN_LITTLE);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_UserVersion = reader.Read<ulittle32>();
    }

    if (version >= VERSION_NUMBER(3, 3, 0, 13))
    {
        m_NumBlocks = reader.Read<ulittle32>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && (user>= 10) || ((user== 1) && (version != VERSION_NUMBER(10, 2, 0, 0))))
    {
        m_UserVersion2 = reader.Read<ulittle32>();
    }
    else
    {
        m_UserVersion2 = 0;
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_UnknownInt3 = reader.Read<uint>();
    }
    else
    {
        m_UnknownInt3 = 0;
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 2) && version <= VERSION_NUMBER(10, 0, 1, 2))
    {
        m_ExportInfo.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && (user>= 10) || ((user== 1) && (version != VERSION_NUMBER(10, 2, 0, 0))))
    {
        m_ExportInfo.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0))
    {
        m_NumBlockTypes = reader.Read<ushort>();
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0))
    {
        m_BlockTypes.resize(m_NumBlockTypes);
        for (uint32_t i = 0; i < m_BlockTypes.size(); i++)
        {
            m_BlockTypes[i].Read(reader, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0))
    {
        m_BlockTypeIndex.resize(m_NumBlocks);
        for (uint32_t i = 0; i < m_BlockTypeIndex.size(); i++)
        {
            m_BlockTypeIndex[i] = reader.Read<BlockTypeIndex>();
        }
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_BlockSize.resize(m_NumBlocks);
        for (uint32_t i = 0; i < m_BlockSize.size(); i++)
        {
            m_BlockSize[i] = reader.Read<uint>();
        }
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        m_NumStrings = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        m_MaxStringLength = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        m_Strings.resize(m_NumStrings);
        for (uint32_t i = 0; i < m_Strings.size(); i++)
        {
            m_Strings[i].Read(reader, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0))
    {
        m_UnknownInt2 = reader.Read<uint>();
    }
    else
    {
        m_UnknownInt2 = 0;
    }

}

void Header::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    for (uint32_t i = 0; i < m_HeaderString.size(); i++)
    {
        writer.Write(m_HeaderString[i]);
    }
    writer.Write<char>(0x0A);

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        for (uint32_t i = 0; i < m_Copyright.size(); i++)
        {
            for (uint32_t j = 0; j < m_Copyright[i].size(); j++)
            {
                writer.Write(m_Copyright[i][j]);
            }
            writer.Write<char>(0x0A);
        }
    }

    version = m_Version;
    user = m_UserVersion;

    if (version >= VERSION_NUMBER(3, 3, 0, 13))
    {
        writer.Write(m_Version);
    }
    else
    {
        //writer.Write(0x04000002);
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4))
    {
        writer.Write(m_EndianType);
    }
    else
    {
        //writer.Write(ENDIAN_LITTLE);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_UserVersion);
    }

    if (version >= VERSION_NUMBER(3, 3, 0, 13))
    {
        writer.Write(m_NumBlocks);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && (user>= 10) || ((user== 1) && (version != VERSION_NUMBER(10, 2, 0, 0))))
    {
        writer.Write(m_UserVersion2);
    }
    else
    {
        //writer.Write(0);
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        writer.Write(m_UnknownInt3);
    }
    else
    {
        //writer.Write(0);
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 2) && version <= VERSION_NUMBER(10, 0, 1, 2))
    {
        m_ExportInfo.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0) && (user>= 10) || ((user== 1) && (version != VERSION_NUMBER(10, 2, 0, 0))))
    {
        m_ExportInfo.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0))
    {
        writer.Write(m_NumBlockTypes);
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0))
    {
        for (uint32_t i = 0; i < m_BlockTypes.size(); i++)
        {
            m_BlockTypes[i].Write(writer, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0))
    {
        for (uint32_t i = 0; i < m_BlockTypeIndex.size(); i++)
        {
            writer.Write(m_BlockTypeIndex[i]);
        }
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        for (uint32_t i = 0; i < m_BlockSize.size(); i++)
        {
            writer.Write(m_BlockSize[i]);
        }
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        writer.Write(m_NumStrings);
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        writer.Write(m_MaxStringLength);
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        for (uint32_t i = 0; i < m_Strings.size(); i++)
        {
            m_Strings[i].Write(writer, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0))
    {
        writer.Write(m_UnknownInt2);
    }
    else
    {
        //writer.Write(0);
    }

}
