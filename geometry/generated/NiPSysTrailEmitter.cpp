#include "NiPSysTrailEmitter.hpp"

using namespace nejlika::geometry;

void NiPSysTrailEmitter::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysEmitter::Read(reader, version, user, arg);

    m_UnknownInt1 = reader.Read<int>();

    m_UnknownFloat1 = reader.Read<float>();

    m_UnknownFloat2 = reader.Read<float>();

    m_UnknownFloat3 = reader.Read<float>();

    m_UnknownInt2 = reader.Read<int>();

    m_UnknownFloat4 = reader.Read<float>();

    m_UnknownInt3 = reader.Read<int>();

    m_UnknownFloat5 = reader.Read<float>();

    m_UnknownInt4 = reader.Read<int>();

    m_UnknownFloat6 = reader.Read<float>();

    m_UnknownFloat7 = reader.Read<float>();

}

void NiPSysTrailEmitter::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysEmitter::Write(writer, version, user, arg);

    writer.Write(m_UnknownInt1);

    writer.Write(m_UnknownFloat1);

    writer.Write(m_UnknownFloat2);

    writer.Write(m_UnknownFloat3);

    writer.Write(m_UnknownInt2);

    writer.Write(m_UnknownFloat4);

    writer.Write(m_UnknownInt3);

    writer.Write(m_UnknownFloat5);

    writer.Write(m_UnknownInt4);

    writer.Write(m_UnknownFloat6);

    writer.Write(m_UnknownFloat7);

}
