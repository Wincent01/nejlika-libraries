#include "NiPSysDragModifier.hpp"

using namespace nejlika::geometry;

void NiPSysDragModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysModifier::Read(reader, version, user, arg);

    m_Parent.Read(reader, version, user, 0);

    m_DragAxis.Read(reader, version, user, 0);

    m_Percentage = reader.Read<float>();

    m_Range = reader.Read<float>();

    m_RangeFalloff = reader.Read<float>();

}

void NiPSysDragModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysModifier::Write(writer, version, user, arg);

    m_Parent.Write(writer, version, user, 0);

    m_DragAxis.Write(writer, version, user, 0);

    writer.Write(m_Percentage);

    writer.Write(m_Range);

    writer.Write(m_RangeFalloff);

}
