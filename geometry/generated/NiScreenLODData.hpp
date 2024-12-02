#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "Vector3.hpp"
#include "NiLODData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Describes levels of detail based on size of object on screen?
 *         
 */
class NiScreenLODData : public NiLODData
{
protected:
    /**
     * The center of the bounding sphere?
     */
    Vector3 m_BoundCenter;
    /**
     * The radius of the bounding sphere?
     */
    float m_BoundRadius;
    /**
     * The center of the bounding sphere in world space?
     */
    Vector3 m_WorldCenter;
    /**
     * The radius of the bounding sphere in world space?
     */
    float m_WorldRadius;
    /**
     * The number of screen size based LOD levels.
     */
    uint m_ProportionCount;
    /**
     * The LOD levels based on proportion of screen size?
     */
    std::vector<float> m_ProportionLevels;

public:
    const Vector3& GetBoundCenter() const { return m_BoundCenter; }
    Vector3& GetBoundCenter() { return m_BoundCenter; }
    void SetBoundCenter(const Vector3& value) { m_BoundCenter = value; }

    const float& GetBoundRadius() const { return m_BoundRadius; }
    float& GetBoundRadius() { return m_BoundRadius; }
    void SetBoundRadius(const float& value) { m_BoundRadius = value; }

    const Vector3& GetWorldCenter() const { return m_WorldCenter; }
    Vector3& GetWorldCenter() { return m_WorldCenter; }
    void SetWorldCenter(const Vector3& value) { m_WorldCenter = value; }

    const float& GetWorldRadius() const { return m_WorldRadius; }
    float& GetWorldRadius() { return m_WorldRadius; }
    void SetWorldRadius(const float& value) { m_WorldRadius = value; }

    const uint& GetProportionCount() const { return m_ProportionCount; }
    uint& GetProportionCount() { return m_ProportionCount; }
    void SetProportionCount(const uint& value) { m_ProportionCount = value; }

    const std::vector<float>& GetProportionLevels() const { return m_ProportionLevels; }
    std::vector<float>& GetProportionLevels() { return m_ProportionLevels; }
    void SetProportionLevels(const std::vector<float>& value) { m_ProportionLevels = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
