#include "NiMorphData.hpp"

using namespace nejlika::geometry;

void NiMorphData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_NumMorphs = reader.Read<uint>();

    m_NumVertices = reader.Read<uint>();

    m_RelativeTargets = reader.Read<byte>();

    m_Morphs.resize(m_NumMorphs);
    for (uint32_t i = 0; i < m_Morphs.size(); i++)
    {
        m_Morphs[i].Read(reader, version, user, m_NumVertices);
    }

}

void NiMorphData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    writer.Write(m_NumMorphs);

    writer.Write(m_NumVertices);

    writer.Write(m_RelativeTargets);

    for (uint32_t i = 0; i < m_Morphs.size(); i++)
    {
        m_Morphs[i].Write(writer, version, user, m_NumVertices);
    }

}
