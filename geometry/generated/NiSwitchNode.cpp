#include "NiSwitchNode.hpp"

using namespace nejlika::geometry;

void NiSwitchNode::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiNode::Read(reader, version, user, arg);

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_UnknownFlags1 = reader.Read<ushort>();
    }

    m_UnknownInt1 = reader.Read<int>();

}

void NiSwitchNode::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiNode::Write(writer, version, user, arg);

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_UnknownFlags1);
    }

    writer.Write(m_UnknownInt1);

}
