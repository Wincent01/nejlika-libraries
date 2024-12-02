#include "NiLODNode.hpp"

using namespace nejlika::geometry;

void NiLODNode::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiSwitchNode::Read(reader, version, user, arg);

    if (version >= VERSION_NUMBER(4, 0, 0, 2) && version <= VERSION_NUMBER(10, 0, 1, 0))
    {
        m_LODCenter.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(10, 0, 1, 0))
    {
        m_NumLODLevels = reader.Read<uint>();
    }

    if (version <= VERSION_NUMBER(10, 0, 1, 0))
    {
        m_LODLevels.resize(m_NumLODLevels);
        for (uint32_t i = 0; i < m_LODLevels.size(); i++)
        {
            m_LODLevels[i].Read(reader, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_LODLevelData.Read(reader, version, user, 0);
    }

}

void NiLODNode::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiSwitchNode::Write(writer, version, user, arg);

    if (version >= VERSION_NUMBER(4, 0, 0, 2) && version <= VERSION_NUMBER(10, 0, 1, 0))
    {
        m_LODCenter.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(10, 0, 1, 0))
    {
        writer.Write(m_NumLODLevels);
    }

    if (version <= VERSION_NUMBER(10, 0, 1, 0))
    {
        for (uint32_t i = 0; i < m_LODLevels.size(); i++)
        {
            m_LODLevels[i].Write(writer, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_LODLevelData.Write(writer, version, user, 0);
    }

}
