#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NodeGroup.hpp"
#include "SkinShapeGroup.hpp"
#include "SkinShapeGroup.hpp"
#include "NiTriBasedGeom.hpp"
#include "NiTriBasedGeom.hpp"
#include "NiTimeController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Level of detail controller for bones.  Priority is arranged from low to high.
 *         
 */
class NiBoneLODController : public NiTimeController
{
protected:
    /**
     * Unknown.
     */
    uint m_UnknownInt1;
    /**
     * Number of node groups.
     */
    uint m_NumNodeGroups;
    /**
     * Number of node groups.
     */
    uint m_NumNodeGroups2;
    /**
     * A list of node groups (each group a sequence of bones).
     */
    std::vector<NodeGroup> m_NodeGroups;
    /**
     * Number of shape groups.
     */
    uint m_NumShapeGroups;
    /**
     * List of shape groups.
     */
    std::vector<SkinShapeGroup> m_ShapeGroups1;
    /**
     * The size of the second list of shape groups.
     */
    uint m_NumShapeGroups2;
    /**
     * Group of NiTriShape indices.
     */
    std::vector<Pointer<class NiTriBasedGeom*>> m_ShapeGroups2;
    /**
     * Unknown.
     */
    int m_UnknownInt2;
    /**
     * Unknown.
     */
    int m_UnknownInt3;

public:
    const uint& GetUnknownInt1() const { return m_UnknownInt1; }
    uint& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const uint& value) { m_UnknownInt1 = value; }

    const uint& GetNumNodeGroups() const { return m_NumNodeGroups; }
    uint& GetNumNodeGroups() { return m_NumNodeGroups; }
    void SetNumNodeGroups(const uint& value) { m_NumNodeGroups = value; }

    const uint& GetNumNodeGroups2() const { return m_NumNodeGroups2; }
    uint& GetNumNodeGroups2() { return m_NumNodeGroups2; }
    void SetNumNodeGroups2(const uint& value) { m_NumNodeGroups2 = value; }

    const std::vector<NodeGroup>& GetNodeGroups() const { return m_NodeGroups; }
    std::vector<NodeGroup>& GetNodeGroups() { return m_NodeGroups; }
    void SetNodeGroups(const std::vector<NodeGroup>& value) { m_NodeGroups = value; }

    const uint& GetNumShapeGroups() const { return m_NumShapeGroups; }
    uint& GetNumShapeGroups() { return m_NumShapeGroups; }
    void SetNumShapeGroups(const uint& value) { m_NumShapeGroups = value; }

    const std::vector<SkinShapeGroup>& GetShapeGroups1() const { return m_ShapeGroups1; }
    std::vector<SkinShapeGroup>& GetShapeGroups1() { return m_ShapeGroups1; }
    void SetShapeGroups1(const std::vector<SkinShapeGroup>& value) { m_ShapeGroups1 = value; }

    const uint& GetNumShapeGroups2() const { return m_NumShapeGroups2; }
    uint& GetNumShapeGroups2() { return m_NumShapeGroups2; }
    void SetNumShapeGroups2(const uint& value) { m_NumShapeGroups2 = value; }

    const std::vector<Pointer<class NiTriBasedGeom*>>& GetShapeGroups2() const { return m_ShapeGroups2; }
    std::vector<Pointer<class NiTriBasedGeom*>>& GetShapeGroups2() { return m_ShapeGroups2; }
    void SetShapeGroups2(const std::vector<Pointer<class NiTriBasedGeom*>>& value) { m_ShapeGroups2 = value; }

    const int& GetUnknownInt2() const { return m_UnknownInt2; }
    int& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const int& value) { m_UnknownInt2 = value; }

    const int& GetUnknownInt3() const { return m_UnknownInt3; }
    int& GetUnknownInt3() { return m_UnknownInt3; }
    void SetUnknownInt3(const int& value) { m_UnknownInt3 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
