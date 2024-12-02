#include "BSValueNode.hpp"

using namespace nejlika::geometry;

void BSValueNode::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiNode::Read(reader, version, user, arg);

    m_Value = reader.Read<int>();

    m_UnknownByte = reader.Read<byte>();

}

void BSValueNode::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiNode::Write(writer, version, user, arg);

    writer.Write(m_Value);

    writer.Write(m_UnknownByte);

}
