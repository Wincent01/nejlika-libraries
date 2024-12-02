#include "NiSequence.hpp"

using namespace nejlika::geometry;

void NiSequence::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_Name.Read(reader, version, user, 0);

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_TextKeysName.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_TextKeys.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 3, 0, 9) && version <= VERSION_NUMBER(20, 3, 0, 9) && user == 131072)
    {
        m_UnknownInt4 = reader.Read<int>();
    }

    if (version >= VERSION_NUMBER(20, 3, 0, 9) && version <= VERSION_NUMBER(20, 3, 0, 9) && user == 131072)
    {
        m_UnknownInt5 = reader.Read<int>();
    }

    m_NumControlledBlocks = reader.Read<uint>();

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_UnknownInt1 = reader.Read<uint>();
    }

    m_ControlledBlocks.resize(m_NumControlledBlocks);
    for (uint32_t i = 0; i < m_ControlledBlocks.size(); i++)
    {
        m_ControlledBlocks[i].Read(reader, version, user, 0);
    }

}

void NiSequence::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    m_Name.Write(writer, version, user, 0);

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_TextKeysName.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_TextKeys.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 3, 0, 9) && version <= VERSION_NUMBER(20, 3, 0, 9) && user == 131072)
    {
        writer.Write(m_UnknownInt4);
    }

    if (version >= VERSION_NUMBER(20, 3, 0, 9) && version <= VERSION_NUMBER(20, 3, 0, 9) && user == 131072)
    {
        writer.Write(m_UnknownInt5);
    }

    writer.Write(m_NumControlledBlocks);

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        writer.Write(m_UnknownInt1);
    }

    for (uint32_t i = 0; i < m_ControlledBlocks.size(); i++)
    {
        m_ControlledBlocks[i].Write(writer, version, user, 0);
    }

}
