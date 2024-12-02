#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiTimeController.hpp"
namespace nejlika::geometry {


/**
 * 
 *     A controller that trails a bone behind an actor.
 * 		
 */
class BSLagBoneController : public NiTimeController
{
protected:
    /**
     * How long it takes to rotate about an actor back to rest position.
     */
    float m_LinearVelocity;
    /**
     * How the bone lags rotation
     */
    float m_LinearRotation;
    /**
     * How far bone will tail an actor.
     */
    float m_MaximumDistance;

public:
    const float& GetLinearVelocity() const { return m_LinearVelocity; }
    float& GetLinearVelocity() { return m_LinearVelocity; }
    void SetLinearVelocity(const float& value) { m_LinearVelocity = value; }

    const float& GetLinearRotation() const { return m_LinearRotation; }
    float& GetLinearRotation() { return m_LinearRotation; }
    void SetLinearRotation(const float& value) { m_LinearRotation = value; }

    const float& GetMaximumDistance() const { return m_MaximumDistance; }
    float& GetMaximumDistance() { return m_MaximumDistance; }
    void SetMaximumDistance(const float& value) { m_MaximumDistance = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
