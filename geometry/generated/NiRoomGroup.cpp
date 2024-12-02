#include "NiRoomGroup.hpp"

using namespace nejlika::geometry;

void NiRoomGroup::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiNode::Read(reader, version, user, arg);

    m_ShellLink.Read(reader, version, user, 0);

    m_NumRooms = reader.Read<int>();

    m_Rooms.resize(m_NumRooms);
    for (uint32_t i = 0; i < m_Rooms.size(); i++)
    {
        m_Rooms[i].Read(reader, version, user, 0);
    }

}

void NiRoomGroup::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiNode::Write(writer, version, user, arg);

    m_ShellLink.Write(writer, version, user, 0);

    writer.Write(m_NumRooms);

    for (uint32_t i = 0; i < m_Rooms.size(); i++)
    {
        m_Rooms[i].Write(writer, version, user, 0);
    }

}
