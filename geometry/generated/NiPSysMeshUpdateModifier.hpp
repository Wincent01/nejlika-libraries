#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiAVObject.hpp"
#include "NiPSysModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown.
 *         
 */
class NiPSysMeshUpdateModifier : public NiPSysModifier
{
protected:
    /**
     * The number of object references that follow.
     */
    uint m_NumMeshes;
    /**
     * Group of target NiNodes or NiTriShapes?
     */
    std::vector<Pointer<class NiAVObject*>> m_Meshes;

public:
    const uint& GetNumMeshes() const { return m_NumMeshes; }
    uint& GetNumMeshes() { return m_NumMeshes; }
    void SetNumMeshes(const uint& value) { m_NumMeshes = value; }

    const std::vector<Pointer<class NiAVObject*>>& GetMeshes() const { return m_Meshes; }
    std::vector<Pointer<class NiAVObject*>>& GetMeshes() { return m_Meshes; }
    void SetMeshes(const std::vector<Pointer<class NiAVObject*>>& value) { m_Meshes = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
