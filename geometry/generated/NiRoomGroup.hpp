#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiNode.hpp"
#include "NiRoom.hpp"
#include "NiNode.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Grouping node for nodes in a Portal
 *         
 */
class NiRoomGroup : public NiNode
{
protected:
    /**
     * Outer Shell Geometry Node?
     */
    Pointer<class NiNode*> m_ShellLink;
    /**
     * Number of rooms in this group
     */
    int m_NumRooms;
    /**
     * Rooms associated with this group.
     */
    std::vector<Pointer<class NiRoom*>> m_Rooms;

public:
    const Pointer<class NiNode*>& GetShellLink() const { return m_ShellLink; }
    Pointer<class NiNode*>& GetShellLink() { return m_ShellLink; }
    void SetShellLink(const Pointer<class NiNode*>& value) { m_ShellLink = value; }

    const int& GetNumRooms() const { return m_NumRooms; }
    int& GetNumRooms() { return m_NumRooms; }
    void SetNumRooms(const int& value) { m_NumRooms = value; }

    const std::vector<Pointer<class NiRoom*>>& GetRooms() const { return m_Rooms; }
    std::vector<Pointer<class NiRoom*>>& GetRooms() { return m_Rooms; }
    void SetRooms(const std::vector<Pointer<class NiRoom*>>& value) { m_Rooms = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
