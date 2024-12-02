#include "NiMorphMeshModifier.hpp"

using namespace nejlika::geometry;

void NiMorphMeshModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiMeshModifier::Read(reader, version, user, arg);

    m_Flags = reader.Read<byte>();

    m_NumTargets = reader.Read<ushort>();

    m_NumElements = reader.Read<uint>();

    m_Elements.resize(m_NumElements);
    for (uint32_t i = 0; i < m_Elements.size(); i++)
    {
        m_Elements[i].Read(reader, version, user, 0);
    }

}

void NiMorphMeshModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiMeshModifier::Write(writer, version, user, arg);

    writer.Write(m_Flags);

    writer.Write(m_NumTargets);

    writer.Write(m_NumElements);

    for (uint32_t i = 0; i < m_Elements.size(); i++)
    {
        m_Elements[i].Write(writer, version, user, 0);
    }

}
