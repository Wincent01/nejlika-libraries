#include "NiPSysDragFieldModifier.hpp"

using namespace nejlika::geometry;

void NiPSysDragFieldModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysFieldModifier::Read(reader, version, user, arg);

    m_UseDirection = reader.Read<bool>();

    m_Direction.Read(reader, version, user, 0);

}

void NiPSysDragFieldModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysFieldModifier::Write(writer, version, user, arg);

    writer.Write(m_UseDirection);

    m_Direction.Write(writer, version, user, 0);

}
