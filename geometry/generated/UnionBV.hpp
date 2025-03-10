#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {

class BoundingVolume;

class UnionBV : public Construct
{
protected:
    /**
     * Number of Bounding Volumes.
     */
    uint m_NumBV;
    /**
     * Bounding Volume.
     */
    std::vector<BoundingVolume> m_BoundingVolumes;

public:
    const uint& GetNumBV() const { return m_NumBV; }
    uint& GetNumBV() { return m_NumBV; }
    void SetNumBV(const uint& value) { m_NumBV = value; }

    const std::vector<BoundingVolume>& GetBoundingVolumes() const { return m_BoundingVolumes; }
    std::vector<BoundingVolume>& GetBoundingVolumes() { return m_BoundingVolumes; }
    void SetBoundingVolumes(const std::vector<BoundingVolume>& value) { m_BoundingVolumes = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
