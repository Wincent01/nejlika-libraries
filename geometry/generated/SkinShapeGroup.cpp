#include "SkinShapeGroup.hpp"

using namespace nejlika::geometry;

void SkinShapeGroup::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_NumLinkPairs = reader.Read<uint>();

    m_LinkPairs.resize(m_NumLinkPairs);
    for (uint32_t i = 0; i < m_LinkPairs.size(); i++)
    {
        m_LinkPairs[i].Read(reader, version, user, 0);
    }

}

void SkinShapeGroup::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_NumLinkPairs);

    for (uint32_t i = 0; i < m_LinkPairs.size(); i++)
    {
        m_LinkPairs[i].Write(writer, version, user, 0);
    }

}
