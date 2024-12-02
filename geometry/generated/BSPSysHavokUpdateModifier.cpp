#include "BSPSysHavokUpdateModifier.hpp"

using namespace nejlika::geometry;

void BSPSysHavokUpdateModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysModifier::Read(reader, version, user, arg);

    m_NumNodes = reader.Read<uint>();

    m_Nodes.resize(m_NumNodes);
    for (uint32_t i = 0; i < m_Nodes.size(); i++)
    {
        m_Nodes[i].Read(reader, version, user, 0);
    }

    m_Modifier.Read(reader, version, user, 0);

}

void BSPSysHavokUpdateModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysModifier::Write(writer, version, user, arg);

    writer.Write(m_NumNodes);

    for (uint32_t i = 0; i < m_Nodes.size(); i++)
    {
        m_Nodes[i].Write(writer, version, user, 0);
    }

    m_Modifier.Write(writer, version, user, 0);

}
