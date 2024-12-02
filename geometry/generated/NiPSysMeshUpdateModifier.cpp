#include "NiPSysMeshUpdateModifier.hpp"

using namespace nejlika::geometry;

void NiPSysMeshUpdateModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysModifier::Read(reader, version, user, arg);

    m_NumMeshes = reader.Read<uint>();

    m_Meshes.resize(m_NumMeshes);
    for (uint32_t i = 0; i < m_Meshes.size(); i++)
    {
        m_Meshes[i].Read(reader, version, user, 0);
    }

}

void NiPSysMeshUpdateModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysModifier::Write(writer, version, user, arg);

    writer.Write(m_NumMeshes);

    for (uint32_t i = 0; i < m_Meshes.size(); i++)
    {
        m_Meshes[i].Write(writer, version, user, 0);
    }

}
