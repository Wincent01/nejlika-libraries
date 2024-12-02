#include "NiObjectNET.hpp"

using namespace nejlika::geometry;

void NiObjectNET::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    if (false && user>= 12)
    {
        m_SkyrimShaderType = reader.Read<BSLightingShaderPropertyShaderType>();
    }

    m_Name.Read(reader, version, user, 0);

    if (version <= VERSION_NUMBER(0, 0, 2, 3))
    {
        m_HasOldExtraData = reader.Read<bool>();
    }

    if (version <= VERSION_NUMBER(0, 0, 2, 3) && m_HasOldExtraData)
    {
        m_OldExtraPropName.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(0, 0, 2, 3) && m_HasOldExtraData)
    {
        m_OldExtraInternalId = reader.Read<uint>();
    }

    if (version <= VERSION_NUMBER(0, 0, 2, 3) && m_HasOldExtraData)
    {
        m_OldExtraString.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(0, 0, 2, 3))
    {
        m_UnknownByte = reader.Read<byte>();
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 0) && version <= VERSION_NUMBER(4, 2, 2, 0))
    {
        m_ExtraData.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0))
    {
        m_NumExtraDataList = reader.Read<uint>();

        // Something very likely went wrong here
        if (m_NumExtraDataList > 100) {
            m_NumExtraDataList = 0;
        }
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0))
    {
        m_ExtraDataList.resize(m_NumExtraDataList);
        for (uint32_t i = 0; i < m_ExtraDataList.size(); i++)
        {
            m_ExtraDataList[i].Read(reader, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 0))
    {
        m_Controller.Read(reader, version, user, 0);
    }

}

void NiObjectNET::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    if (false && user>= 12)
    {
        writer.Write(m_SkyrimShaderType);
    }

    m_Name.Write(writer, version, user, 0);

    if (version <= VERSION_NUMBER(0, 0, 2, 3))
    {
        writer.Write(m_HasOldExtraData);
    }

    if (version <= VERSION_NUMBER(0, 0, 2, 3) && m_HasOldExtraData)
    {
        m_OldExtraPropName.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(0, 0, 2, 3) && m_HasOldExtraData)
    {
        writer.Write(m_OldExtraInternalId);
    }

    if (version <= VERSION_NUMBER(0, 0, 2, 3) && m_HasOldExtraData)
    {
        m_OldExtraString.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(0, 0, 2, 3))
    {
        writer.Write(m_UnknownByte);
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 0) && version <= VERSION_NUMBER(4, 2, 2, 0))
    {
        m_ExtraData.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0))
    {
        writer.Write(m_NumExtraDataList);
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0))
    {
        for (uint32_t i = 0; i < m_ExtraDataList.size(); i++)
        {
            m_ExtraDataList[i].Write(writer, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 0))
    {
        m_Controller.Write(writer, version, user, 0);
    }

}
