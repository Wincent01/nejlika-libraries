#include "NiDefaultAVObjectPalette.hpp"

using namespace nejlika::geometry;

void NiDefaultAVObjectPalette::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiAVObjectPalette::Read(reader, version, user, arg);

    m_UnknownInt = reader.Read<uint>();

    m_NumObjs = reader.Read<uint>();

    m_Objs.resize(m_NumObjs);
    for (uint32_t i = 0; i < m_Objs.size(); i++)
    {
        m_Objs[i].Read(reader, version, user, 0);
    }

}

void NiDefaultAVObjectPalette::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiAVObjectPalette::Write(writer, version, user, arg);

    writer.Write(m_UnknownInt);

    writer.Write(m_NumObjs);

    for (uint32_t i = 0; i < m_Objs.size(); i++)
    {
        m_Objs[i].Write(writer, version, user, 0);
    }

}
