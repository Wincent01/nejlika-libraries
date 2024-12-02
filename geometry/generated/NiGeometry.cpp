#include "NiGeometry.hpp"

using namespace nejlika::geometry;

void NiGeometry::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiAVObject::Read(reader, version, user, arg);

    m_Data.Read(reader, version, user, 0);

    if (version >= VERSION_NUMBER(3, 3, 0, 13))
    {
        m_SkinInstance.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_NumMaterials = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_MaterialName.resize(m_NumMaterials);
        for (uint32_t i = 0; i < m_MaterialName.size(); i++)
        {
            m_MaterialName[i].Read(reader, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_MaterialExtraData.resize(m_NumMaterials);
        for (uint32_t i = 0; i < m_MaterialExtraData.size(); i++)
        {
            m_MaterialExtraData[i] = reader.Read<int>();
        }
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_ActiveMaterial = reader.Read<int>();
    }
    else
    {
        m_ActiveMaterial = 0;
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0) && version <= VERSION_NUMBER(20, 1, 0, 3))
    {
        m_HasShader = reader.Read<bool>();
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0) && version <= VERSION_NUMBER(20, 1, 0, 3) && m_HasShader)
    {
        m_ShaderName.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0) && version <= VERSION_NUMBER(20, 1, 0, 3) && m_HasShader)
    {
        m_UnknownInteger = reader.Read<int>();
    }

    if (user == 1)
    {
        m_UnknownByte = reader.Read<byte>();
    }
    else
    {
        m_UnknownByte = 255;
    }

    if (version >= VERSION_NUMBER(10, 4, 0, 1) && version <= VERSION_NUMBER(10, 4, 0, 1))
    {
        m_UnknownInteger2 = reader.Read<int>();
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        m_DirtyFlag = reader.Read<bool>();
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && user == 12)
    {
        m_BSProperties.resize(2);
        for (uint32_t i = 0; i < m_BSProperties.size(); i++)
        {
            m_BSProperties[i].Read(reader, version, user, 0);
        }
    }

}

void NiGeometry::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiAVObject::Write(writer, version, user, arg);

    m_Data.Write(writer, version, user, 0);

    if (version >= VERSION_NUMBER(3, 3, 0, 13))
    {
        m_SkinInstance.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        writer.Write(m_NumMaterials);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        for (uint32_t i = 0; i < m_MaterialName.size(); i++)
        {
            m_MaterialName[i].Write(writer, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        for (uint32_t i = 0; i < m_MaterialExtraData.size(); i++)
        {
            writer.Write(m_MaterialExtraData[i]);
        }
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        writer.Write(m_ActiveMaterial);
    }
    else
    {
        //writer.Write(0);
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0) && version <= VERSION_NUMBER(20, 1, 0, 3))
    {
        writer.Write(m_HasShader);
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0) && version <= VERSION_NUMBER(20, 1, 0, 3) && m_HasShader)
    {
        m_ShaderName.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0) && version <= VERSION_NUMBER(20, 1, 0, 3) && m_HasShader)
    {
        writer.Write(m_UnknownInteger);
    }

    if (user == 1)
    {
        writer.Write(m_UnknownByte);
    }
    else
    {
        //writer.Write(255);
    }

    if (version >= VERSION_NUMBER(10, 4, 0, 1) && version <= VERSION_NUMBER(10, 4, 0, 1))
    {
        writer.Write(m_UnknownInteger2);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7))
    {
        writer.Write(m_DirtyFlag);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && user == 12)
    {
        for (uint32_t i = 0; i < m_BSProperties.size(); i++)
        {
            m_BSProperties[i].Write(writer, version, user, 0);
        }
    }

}
