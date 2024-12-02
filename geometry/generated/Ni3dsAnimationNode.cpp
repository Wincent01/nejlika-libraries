#include "Ni3dsAnimationNode.hpp"

using namespace nejlika::geometry;

void Ni3dsAnimationNode::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_Name.Read(reader, version, user, 0);

    m_HasData = reader.Read<bool>();

    if (m_HasData)
    {
        m_UnknownFloats1.resize(21);
        for (uint32_t i = 0; i < m_UnknownFloats1.size(); i++)
        {
            m_UnknownFloats1[i] = reader.Read<float>();
        }
    }

    if (m_HasData)
    {
        m_UnknownShort = reader.Read<ushort>();
    }

    if (m_HasData)
    {
        m_Child.Read(reader, version, user, 0);
    }

    if (m_HasData)
    {
        m_UnknownFloats2.resize(12);
        for (uint32_t i = 0; i < m_UnknownFloats2.size(); i++)
        {
            m_UnknownFloats2[i] = reader.Read<float>();
        }
    }

    if (m_HasData)
    {
        m_Count = reader.Read<uint>();
    }

    if (m_HasData)
    {
        m_UnknownArray.resize(m_Count);
        for (uint32_t i = 0; i < m_UnknownArray.size(); i++)
        {
            m_UnknownArray[i].resize(5);
            for (uint32_t j = 0; j < m_UnknownArray[i].size(); j++)
            {
                m_UnknownArray[i][j] = reader.Read<byte>();
            }
        }
    }

}

void Ni3dsAnimationNode::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    m_Name.Write(writer, version, user, 0);

    writer.Write(m_HasData);

    if (m_HasData)
    {
        for (uint32_t i = 0; i < m_UnknownFloats1.size(); i++)
        {
            writer.Write(m_UnknownFloats1[i]);
        }
    }

    if (m_HasData)
    {
        writer.Write(m_UnknownShort);
    }

    if (m_HasData)
    {
        m_Child.Write(writer, version, user, 0);
    }

    if (m_HasData)
    {
        for (uint32_t i = 0; i < m_UnknownFloats2.size(); i++)
        {
            writer.Write(m_UnknownFloats2[i]);
        }
    }

    if (m_HasData)
    {
        writer.Write(m_Count);
    }

    if (m_HasData)
    {
        for (uint32_t i = 0; i < m_UnknownArray.size(); i++)
        {
            for (uint32_t j = 0; j < m_UnknownArray[i].size(); j++)
            {
                writer.Write(m_UnknownArray[i][j]);
            }
        }
    }

}
