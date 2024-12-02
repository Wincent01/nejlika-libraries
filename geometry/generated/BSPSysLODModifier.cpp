#include "BSPSysLODModifier.hpp"

using namespace nejlika::geometry;

void BSPSysLODModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysModifier::Read(reader, version, user, arg);

    m_UknownFloat1 = reader.Read<float>();

    m_UknownFloat2 = reader.Read<float>();

    m_UknownFloat3 = reader.Read<float>();

    m_UknownFloat4 = reader.Read<float>();

}

void BSPSysLODModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysModifier::Write(writer, version, user, arg);

    writer.Write(m_UknownFloat1);

    writer.Write(m_UknownFloat2);

    writer.Write(m_UknownFloat3);

    writer.Write(m_UknownFloat4);

}
