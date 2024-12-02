#include "MaterialData.hpp"

using namespace nejlika::geometry;

void MaterialData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_MaterialName.Read(reader, version, user, 0);

    m_MaterialExtraData = reader.Read<uint>();

}

void MaterialData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    m_MaterialName.Write(writer, version, user, 0);

    writer.Write(m_MaterialExtraData);

}
