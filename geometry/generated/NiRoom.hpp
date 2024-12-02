#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector4.hpp"
#include "NiPortal.hpp"
#include "NiPortal.hpp"
#include "NiAVObject.hpp"
#include "NiNode.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Grouping node for nodes in a Portal
 *         
 */
class NiRoom : public NiNode
{
protected:
    /**
     * Number of walls in a room?
     */
    int m_NumWalls;
    /**
     * Face normal and unknown value.
     */
    std::vector<Vector4> m_WallPlane;
    /**
     * Number of doors into room
     */
    int m_NumInPortals;
    /**
     * Number of portals into room
     */
    std::vector<Pointer<class NiPortal*>> m_InPortals;
    /**
     * Number of doors out of room
     */
    int m_NumPortals2;
    /**
     * Number of portals out of room
     */
    std::vector<Pointer<class NiPortal*>> m_Portals2;
    /**
     * Number of unknowns
     */
    int m_NumItems;
    /**
     * All geometry associated with room.
     */
    std::vector<Pointer<class NiAVObject*>> m_Items;

public:
    const int& GetNumWalls() const { return m_NumWalls; }
    int& GetNumWalls() { return m_NumWalls; }
    void SetNumWalls(const int& value) { m_NumWalls = value; }

    const std::vector<Vector4>& GetWallPlane() const { return m_WallPlane; }
    std::vector<Vector4>& GetWallPlane() { return m_WallPlane; }
    void SetWallPlane(const std::vector<Vector4>& value) { m_WallPlane = value; }

    const int& GetNumInPortals() const { return m_NumInPortals; }
    int& GetNumInPortals() { return m_NumInPortals; }
    void SetNumInPortals(const int& value) { m_NumInPortals = value; }

    const std::vector<Pointer<class NiPortal*>>& GetInPortals() const { return m_InPortals; }
    std::vector<Pointer<class NiPortal*>>& GetInPortals() { return m_InPortals; }
    void SetInPortals(const std::vector<Pointer<class NiPortal*>>& value) { m_InPortals = value; }

    const int& GetNumPortals2() const { return m_NumPortals2; }
    int& GetNumPortals2() { return m_NumPortals2; }
    void SetNumPortals2(const int& value) { m_NumPortals2 = value; }

    const std::vector<Pointer<class NiPortal*>>& GetPortals2() const { return m_Portals2; }
    std::vector<Pointer<class NiPortal*>>& GetPortals2() { return m_Portals2; }
    void SetPortals2(const std::vector<Pointer<class NiPortal*>>& value) { m_Portals2 = value; }

    const int& GetNumItems() const { return m_NumItems; }
    int& GetNumItems() { return m_NumItems; }
    void SetNumItems(const int& value) { m_NumItems = value; }

    const std::vector<Pointer<class NiAVObject*>>& GetItems() const { return m_Items; }
    std::vector<Pointer<class NiAVObject*>>& GetItems() { return m_Items; }
    void SetItems(const std::vector<Pointer<class NiAVObject*>>& value) { m_Items = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
