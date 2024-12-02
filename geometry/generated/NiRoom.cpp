#include "NiRoom.hpp"

using namespace nejlika::geometry;

void NiRoom::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiNode::Read(reader, version, user, arg);

    m_NumWalls = reader.Read<int>();

    m_WallPlane.resize(m_NumWalls);
    for (uint32_t i = 0; i < m_WallPlane.size(); i++)
    {
        m_WallPlane[i].Read(reader, version, user, 0);
    }

    m_NumInPortals = reader.Read<int>();

    m_InPortals.resize(m_NumInPortals);
    for (uint32_t i = 0; i < m_InPortals.size(); i++)
    {
        m_InPortals[i].Read(reader, version, user, 0);
    }

    m_NumPortals2 = reader.Read<int>();

    m_Portals2.resize(m_NumPortals2);
    for (uint32_t i = 0; i < m_Portals2.size(); i++)
    {
        m_Portals2[i].Read(reader, version, user, 0);
    }

    m_NumItems = reader.Read<int>();

    m_Items.resize(m_NumItems);
    for (uint32_t i = 0; i < m_Items.size(); i++)
    {
        m_Items[i].Read(reader, version, user, 0);
    }

}

void NiRoom::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiNode::Write(writer, version, user, arg);

    writer.Write(m_NumWalls);

    for (uint32_t i = 0; i < m_WallPlane.size(); i++)
    {
        m_WallPlane[i].Write(writer, version, user, 0);
    }

    writer.Write(m_NumInPortals);

    for (uint32_t i = 0; i < m_InPortals.size(); i++)
    {
        m_InPortals[i].Write(writer, version, user, 0);
    }

    writer.Write(m_NumPortals2);

    for (uint32_t i = 0; i < m_Portals2.size(); i++)
    {
        m_Portals2[i].Write(writer, version, user, 0);
    }

    writer.Write(m_NumItems);

    for (uint32_t i = 0; i < m_Items.size(); i++)
    {
        m_Items[i].Write(writer, version, user, 0);
    }

}
