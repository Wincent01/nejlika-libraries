#include "NiNode.hpp"

using namespace nejlika::geometry;

void NiNode::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiAVObject::Read(reader, version, user, arg);

    m_NumChildren = reader.Read<uint>();

    m_Children.resize(m_NumChildren);
    for (uint32_t i = 0; i < m_Children.size(); i++)
    {
        m_Children[i].Read(reader, version, user, 0);
    }

    m_NumEffects = reader.Read<uint>();

    m_Effects.resize(m_NumEffects);
    for (uint32_t i = 0; i < m_Effects.size(); i++)
    {
        m_Effects[i].Read(reader, version, user, 0);
    }

}

void NiNode::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiAVObject::Write(writer, version, user, arg);

    writer.Write(m_NumChildren);

    for (uint32_t i = 0; i < m_Children.size(); i++)
    {
        m_Children[i].Write(writer, version, user, 0);
    }

    writer.Write(m_NumEffects);

    for (uint32_t i = 0; i < m_Effects.size(); i++)
    {
        m_Effects[i].Write(writer, version, user, 0);
    }

}
