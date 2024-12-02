#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "LODRange.hpp"
#include "NiLODData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Describes levels of detail based on distance of object from camera.
 *         
 */
class NiRangeLODData : public NiLODData
{
protected:
    /**
     * ?
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


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
