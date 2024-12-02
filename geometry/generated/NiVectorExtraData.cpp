#include "NiVectorExtraData.hpp"

using namespace nejlika::geometry;

void NiVectorExtraData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiExtraData::Read(reader, version, user, arg);

    m_VectorData.Read(reader, version, user, 0);

    m_UnknownFloat = reader.Read<float>();

}

void NiVectorExtraData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiExtraData::Write(writer, version, user, arg);

    m_VectorData.Write(writer, version, user, 0);

    writer.Write(m_UnknownFloat);

}
