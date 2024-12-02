#include "ExtraMeshDataEpicMickey.hpp"

using namespace nejlika::geometry;

void ExtraMeshDataEpicMickey::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_UnknownInt1 = reader.Read<int>();

    m_UnknownInt2 = reader.Read<int>();

    m_UnknownInt3 = reader.Read<int>();

    m_UnknownInt4 = reader.Read<float>();

    m_UnknownInt5 = reader.Read<float>();

    m_UnknownInt6 = reader.Read<float>();

}

void ExtraMeshDataEpicMickey::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_UnknownInt1);

    writer.Write(m_UnknownInt2);

    writer.Write(m_UnknownInt3);

    writer.Write(m_UnknownInt4);

    writer.Write(m_UnknownInt5);

    writer.Write(m_UnknownInt6);

}
