#include "NiBillboardNode.hpp"

using namespace nejlika::geometry;

void NiBillboardNode::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiNode::Read(reader, version, user, arg);

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_BillboardMode = reader.Read<BillboardMode>();
    }

}

void NiBillboardNode::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiNode::Write(writer, version, user, arg);

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_BillboardMode);
    }

}
