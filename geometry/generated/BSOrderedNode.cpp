#include "BSOrderedNode.hpp"

using namespace nejlika::geometry;

void BSOrderedNode::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiNode::Read(reader, version, user, arg);

    m_AlphaSortBound.Read(reader, version, user, 0);

    m_IsStaticBound = reader.Read<byte>();

}

void BSOrderedNode::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiNode::Write(writer, version, user, arg);

    m_AlphaSortBound.Write(writer, version, user, 0);

    writer.Write(m_IsStaticBound);

}
