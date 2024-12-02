#include "NiBSAnimationNode.hpp"

using namespace nejlika::geometry;

void NiBSAnimationNode::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiNode::Read(reader, version, user, arg);

}

void NiBSAnimationNode::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiNode::Write(writer, version, user, arg);

}
