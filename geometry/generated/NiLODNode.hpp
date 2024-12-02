#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "LODRange.hpp"
#include "NiLODData.hpp"
#include "NiSwitchNode.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Level of detail selector. Links to different levels of detail of the same model, used to switch a geometry at a specified distance.
 *         
 */
class NiLODNode : public NiSwitchNode
{
protected:
    /**
     * Point to calculate distance from for switching?
     */
    Vector3 m_LODCenter;
    /**
     * Number of levels of detail.
     */
    uint m_NumLODLevels;
    /**
     * The ranges of distance that each level of detail applies in.
     */
    std::vector<LODRange> m_LODLevels;
    /**
     * Refers to LOD level information, either distance or screen size based.
     */
    Pointer<class NiLODData*> m_LODLevelData;

public:
    const Vector3& GetLODCenter() const { return m_LODCenter; }
    Vector3& GetLODCenter() { return m_LODCenter; }
    void SetLODCenter(const Vector3& value) { m_LODCenter = value; }

    const uint& GetNumLODLevels() const { return m_NumLODLevels; }
    uint& GetNumLODLevels() { return m_NumLODLevels; }
    void SetNumLODLevels(const uint& value) { m_NumLODLevels = value; }

    const std::vector<LODRange>& GetLODLevels() const { return m_LODLevels; }
    std::vector<LODRange>& GetLODLevels() { return m_LODLevels; }
    void SetLODLevels(const std::vector<LODRange>& value) { m_LODLevels = value; }

    const Pointer<class NiLODData*>& GetLODLevelData() const { return m_LODLevelData; }
    Pointer<class NiLODData*>& GetLODLevelData() { return m_LODLevelData; }
    void SetLODLevelData(const Pointer<class NiLODData*>& value) { m_LODLevelData = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
