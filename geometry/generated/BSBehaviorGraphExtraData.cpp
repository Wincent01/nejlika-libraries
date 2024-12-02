#include "BSBehaviorGraphExtraData.hpp"

using namespace nejlika::geometry;

void BSBehaviorGraphExtraData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiExtraData::Read(reader, version, user, arg);

    m_BehaviourGraphFile.Read(reader, version, user, 0);

    m_ControlsBaseSkeleton = reader.Read<byte>();

}

void BSBehaviorGraphExtraData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiExtraData::Write(writer, version, user, arg);

    m_BehaviourGraphFile.Write(writer, version, user, 0);

    writer.Write(m_ControlsBaseSkeleton);

}
