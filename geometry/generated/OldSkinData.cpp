#include "OldSkinData.hpp"

using namespace nejlika::geometry;

void OldSkinData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_VertexWeight = reader.Read<float>();

    m_VertexIndex = reader.Read<ushort>();

    m_UnknownVector.Read(reader, version, user, 0);

}

void OldSkinData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_VertexWeight);

    writer.Write(m_VertexIndex);

    m_UnknownVector.Write(writer, version, user, 0);

}
