#include "NiAVObject.hpp"

using namespace nejlika::geometry;

void NiAVObject::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObjectNET::Read(reader, version, user, arg);

    if (version >= VERSION_NUMBER(0, 0, 3, 0))
    {
        m_Flags = reader.Read<Flags>();
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && (user>= 11) && (0> 26))
    {
        m_UnknownShort1 = reader.Read<ushort>();
    }
    else
    {
        m_UnknownShort1 = 8;
    }

    m_Translation.Read(reader, version, user, 0);

    m_Rotation.Read(reader, version, user, 0);

    m_Scale = reader.Read<float>();

    if (version <= VERSION_NUMBER(4, 2, 2, 0))
    {
        m_Velocity.Read(reader, version, user, 0);
    }

    if (((version < VERSION_NUMBER(20, 2, 0, 7)) || (user<= 11)))
    {
        m_NumProperties = reader.Read<uint>();
    }

    if (((version < VERSION_NUMBER(20, 2, 0, 7)) || (user<= 11)))
    {
        m_Properties.resize(m_NumProperties);
        for (uint32_t i = 0; i < m_Properties.size(); i++)
        {
            m_Properties[i].Read(reader, version, user, 0);
        }
    }

    if (version <= VERSION_NUMBER(0, 0, 2, 3))
    {
        m_Unknown1.resize(4);
        for (uint32_t i = 0; i < m_Unknown1.size(); i++)
        {
            m_Unknown1[i] = reader.Read<uint>();
        }
    }

    if (version <= VERSION_NUMBER(0, 0, 2, 3))
    {
        m_Unknown2 = reader.Read<byte>();
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 0) && version <= VERSION_NUMBER(4, 2, 2, 0))
    {
        m_HasBoundingBox = reader.Read<bool>();
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 0) && version <= VERSION_NUMBER(4, 2, 2, 0) && m_HasBoundingBox)
    {
        m_BoundingBox.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0))
    {
        m_CollisionObject.Read(reader, version, user, 0);
    }

}

void NiAVObject::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObjectNET::Write(writer, version, user, arg);

    if (version >= VERSION_NUMBER(0, 0, 3, 0))
    {
        writer.Write(m_Flags);
    }

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && (user>= 11) && (0> 26))
    {
        writer.Write(m_UnknownShort1);
    }
    else
    {
        //writer.Write(8);
    }

    m_Translation.Write(writer, version, user, 0);

    m_Rotation.Write(writer, version, user, 0);

    writer.Write(m_Scale);

    if (version <= VERSION_NUMBER(4, 2, 2, 0))
    {
        m_Velocity.Write(writer, version, user, 0);
    }

    if (((version < VERSION_NUMBER(20, 2, 0, 7)) || (user<= 11)))
    {
        writer.Write(m_NumProperties);
    }

    if (((version < VERSION_NUMBER(20, 2, 0, 7)) || (user<= 11)))
    {
        for (uint32_t i = 0; i < m_Properties.size(); i++)
        {
            m_Properties[i].Write(writer, version, user, 0);
        }
    }

    if (version <= VERSION_NUMBER(0, 0, 2, 3))
    {
        for (uint32_t i = 0; i < m_Unknown1.size(); i++)
        {
            writer.Write(m_Unknown1[i]);
        }
    }

    if (version <= VERSION_NUMBER(0, 0, 2, 3))
    {
        writer.Write(m_Unknown2);
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 0) && version <= VERSION_NUMBER(4, 2, 2, 0))
    {
        writer.Write(m_HasBoundingBox);
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 0) && version <= VERSION_NUMBER(4, 2, 2, 0) && m_HasBoundingBox)
    {
        m_BoundingBox.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(10, 0, 1, 0))
    {
        m_CollisionObject.Write(writer, version, user, 0);
    }

}
