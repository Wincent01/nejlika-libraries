#include "NiRenderObject.hpp"

using namespace nejlika::geometry;

void NiRenderObject::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiAVObject::Read(reader, version, user, arg);

    m_NumMaterials = reader.Read<uint>();

    m_MaterialData.resize(m_NumMaterials);
    for (uint32_t i = 0; i < m_MaterialData.size(); i++)
    {
        m_MaterialData[i].Read(reader, version, user, 0);
    }

    m_ActiveMaterial = reader.Read<int>();

    m_MaterialNeedsUpdateDefault = reader.Read<bool>();

}

void NiRenderObject::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiAVObject::Write(writer, version, user, arg);

    writer.Write(m_NumMaterials);

    for (uint32_t i = 0; i < m_MaterialData.size(); i++)
    {
        m_MaterialData[i].Write(writer, version, user, 0);
    }

    writer.Write(m_ActiveMaterial);

    writer.Write(m_MaterialNeedsUpdateDefault);

}
