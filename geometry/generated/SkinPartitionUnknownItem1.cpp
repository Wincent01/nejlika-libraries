#include "SkinPartitionUnknownItem1.hpp"

using namespace nejlika::geometry;

void SkinPartitionUnknownItem1::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_UnknownFlags = reader.Read<uint>();

    m_f1 = reader.Read<float>();

    m_f2 = reader.Read<float>();

    m_f3 = reader.Read<float>();

    m_f4 = reader.Read<float>();

    m_f5 = reader.Read<float>();

}

void SkinPartitionUnknownItem1::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_UnknownFlags);

    writer.Write(m_f1);

    writer.Write(m_f2);

    writer.Write(m_f3);

    writer.Write(m_f4);

    writer.Write(m_f5);

}
