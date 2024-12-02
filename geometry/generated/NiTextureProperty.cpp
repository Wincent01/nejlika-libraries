#include "NiTextureProperty.hpp"

using namespace nejlika::geometry;

void NiTextureProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiProperty::Read(reader, version, user, arg);

    if (version <= VERSION_NUMBER(0, 0, 2, 3))
    {
        m_UnknownInts1.resize(2);
        for (uint32_t i = 0; i < m_UnknownInts1.size(); i++)
        {
            m_UnknownInts1[i] = reader.Read<uint>();
        }
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 0))
    {
        m_Flags = reader.Read<Flags>();
    }

    m_Image.Read(reader, version, user, 0);

    if (version >= VERSION_NUMBER(0, 0, 3, 0) && version <= VERSION_NUMBER(0, 0, 3, 3))
    {
        m_UnknownInts2.resize(2);
        for (uint32_t i = 0; i < m_UnknownInts2.size(); i++)
        {
            m_UnknownInts2[i] = reader.Read<uint>();
        }
    }

}

void NiTextureProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiProperty::Write(writer, version, user, arg);

    if (version <= VERSION_NUMBER(0, 0, 2, 3))
    {
        for (uint32_t i = 0; i < m_UnknownInts1.size(); i++)
        {
            writer.Write(m_UnknownInts1[i]);
        }
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 0))
    {
        writer.Write(m_Flags);
    }

    m_Image.Write(writer, version, user, 0);

    if (version >= VERSION_NUMBER(0, 0, 3, 0) && version <= VERSION_NUMBER(0, 0, 3, 3))
    {
        for (uint32_t i = 0; i < m_UnknownInts2.size(); i++)
        {
            writer.Write(m_UnknownInts2[i]);
        }
    }

}
