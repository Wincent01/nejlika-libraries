#include "BSBlastNode.hpp"

using namespace nejlika::geometry;

void BSBlastNode::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiNode::Read(reader, version, user, arg);

    m_UnknownByte1 = reader.Read<byte>();

    m_UnknownShort2 = reader.Read<short>();

}

void BSBlastNode::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiNode::Write(writer, version, user, arg);

    writer.Write(m_UnknownByte1);

    writer.Write(m_UnknownShort2);

}
