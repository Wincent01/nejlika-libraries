#include "Morph.hpp"

using namespace nejlika::geometry;

void Morph::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_FrameName.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_NumKeys = reader.Read<uint>();
    }

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_Interpolation = reader.Read<KeyType>();
    }

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_Keys.resize(m_NumKeys);
        for (uint32_t i = 0; i < m_Keys.size(); i++)
        {
            m_Keys[i].Read(reader, version, user, m_Interpolation);
        }
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_UnknownInt = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4) && version <= VERSION_NUMBER(20, 0, 0, 5) && user == 0)
    {
        m_UnknownInt = reader.Read<uint>();
    }

    m_Vectors.resize(arg);
    for (uint32_t i = 0; i < m_Vectors.size(); i++)
    {
        m_Vectors[i].Read(reader, version, user, 0);
    }

}

void Morph::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_FrameName.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_NumKeys);
    }

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_Interpolation);
    }

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        for (uint32_t i = 0; i < m_Keys.size(); i++)
        {
            m_Keys[i].Write(writer, version, user, m_Interpolation);
        }
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        writer.Write(m_UnknownInt);
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4) && version <= VERSION_NUMBER(20, 0, 0, 5) && user == 0)
    {
        writer.Write(m_UnknownInt);
    }

    for (uint32_t i = 0; i < m_Vectors.size(); i++)
    {
        m_Vectors[i].Write(writer, version, user, 0);
    }

}
