#include "BSMultiBoundNode.hpp"

using namespace nejlika::geometry;

void BSMultiBoundNode::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiNode::Read(reader, version, user, arg);

    m_MultiBound.Read(reader, version, user, 0);

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && (user>= 12))
    {
        m_UnknownInt = reader.Read<uint>();
    }

}

void BSMultiBoundNode::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiNode::Write(writer, version, user, arg);

    m_MultiBound.Write(writer, version, user, 0);

    if (version >= VERSION_NUMBER(20, 2, 0, 7) && (user>= 12))
    {
        writer.Write(m_UnknownInt);
    }

}
