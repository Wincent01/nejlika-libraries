#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "PropagationMode.hpp"
#include "CollisionMode.hpp"
#include "BoundingVolume.hpp"
#include "NiCollisionObject.hpp"
namespace nejlika::geometry {

class BoundingVolume;

/**
 * 
 *         Collision box.
 *         
 */
class NiCollisionData : public NiCollisionObject
{
protected:
    /**
     * Propagation Mode
     */
    PropagationMode m_PropagationMode;
    /**
     * Collision Mode
     */
    CollisionMode m_CollisionMode;
    /**
     * Use Alternate Bounding Volume.
     */
    byte m_UseABV;
    /**
     * Collision data.
     */
    BoundingVolume m_BoundingVolume;

public:
    const PropagationMode& GetPropagationMode() const { return m_PropagationMode; }
    PropagationMode& GetPropagationMode() { return m_PropagationMode; }
    void SetPropagationMode(const PropagationMode& value) { m_PropagationMode = value; }

    const CollisionMode& GetCollisionMode() const { return m_CollisionMode; }
    CollisionMode& GetCollisionMode() { return m_CollisionMode; }
    void SetCollisionMode(const CollisionMode& value) { m_CollisionMode = value; }

    const byte& GetUseABV() const { return m_UseABV; }
    byte& GetUseABV() { return m_UseABV; }
    void SetUseABV(const byte& value) { m_UseABV = value; }

    const BoundingVolume& GetBoundingVolume() const { return m_BoundingVolume; }
    BoundingVolume& GetBoundingVolume() { return m_BoundingVolume; }
    void SetBoundingVolume(const BoundingVolume& value) { m_BoundingVolume = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
