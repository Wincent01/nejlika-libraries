#include "NiTextureModeProperty.hpp"

using namespace nejlika::geometry;

void NiTextureModeProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiProperty::Read(reader, version, user, arg);

    if (version <= VERSION_NUMBER(0, 0, 2, 3))
    {
        m_UnknownInts.resize(3);
        for (uint32_t i = 0; i < m_UnknownInts.size(); i++)
        {
            m_UnknownInts[i] = reader.Read<uint>();
        }
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 0))
    {
        m_UnknownShort = reader.Read<short>();
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 1) && version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_PS2L = reader.Read<short>();
    }
    else
    {
        m_PS2L = 0;
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 1) && version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_PS2K = reader.Read<short>();
    }
    else
    {
        m_PS2K = -75;
    }

}

void NiTextureModeProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiProperty::Write(writer, version, user, arg);

    if (version <= VERSION_NUMBER(0, 0, 2, 3))
    {
        for (uint32_t i = 0; i < m_UnknownInts.size(); i++)
        {
            writer.Write(m_UnknownInts[i]);
        }
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 0))
    {
        writer.Write(m_UnknownShort);
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 1) && version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        writer.Write(m_PS2L);
    }
    else
    {
        //writer.Write(0);
    }

    if (version >= VERSION_NUMBER(0, 0, 3, 1) && version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        writer.Write(m_PS2K);
    }
    else
    {
        //writer.Write(-75);
    }

}
