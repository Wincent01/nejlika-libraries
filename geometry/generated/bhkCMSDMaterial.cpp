#include "bhkCMSDMaterial.hpp"

using namespace nejlika::geometry;

void bhkCMSDMaterial::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_SkyrimMaterial = reader.Read<SkyrimHavokMaterial>();

    m_SkyrimLayer = static_cast<SkyrimLayer>(reader.Read<uint32_t>());

}

void bhkCMSDMaterial::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_SkyrimMaterial);

    writer.Write(static_cast<uint32_t>(m_SkyrimLayer));

}
