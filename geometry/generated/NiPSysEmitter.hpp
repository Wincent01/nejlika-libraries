#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Color4.hpp"
#include "NiPSysModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A particle emitter?
 *         
 */
class NiPSysEmitter : public NiPSysModifier
{
protected:
    /**
     * Speed / Inertia of particle movement.
     */
    float m_Speed;
    /**
     * Adds an amount of randomness to Speed.
     */
    float m_SpeedVariation;
    /**
     * Declination / First axis.
     */
    float m_Declination;
    /**
     * Declination randomness / First axis.
     */
    float m_DeclinationVariation;
    /**
     * Planar Angle / Second axis.
     */
    float m_PlanarAngle;
    /**
     * Planar Angle randomness / Second axis .
     */
    float m_PlanarAngleVariation;
    /**
     * Defines color of a birthed particle.
     */
    Color4 m_InitialColor;
    /**
     * Size of a birthed particle.
     */
    float m_InitialRadius;
    /**
     * Particle Radius randomness.
     */
    float m_RadiusVariation;
    /**
     * Duration until a particle dies.
     */
    float m_LifeSpan;
    /**
     * Adds randomness to Life Span.
     */
    float m_LifeSpanVariation;

public:
    const float& GetSpeed() const { return m_Speed; }
    float& GetSpeed() { return m_Speed; }
    void SetSpeed(const float& value) { m_Speed = value; }

    const float& GetSpeedVariation() const { return m_SpeedVariation; }
    float& GetSpeedVariation() { return m_SpeedVariation; }
    void SetSpeedVariation(const float& value) { m_SpeedVariation = value; }

    const float& GetDeclination() const { return m_Declination; }
    float& GetDeclination() { return m_Declination; }
    void SetDeclination(const float& value) { m_Declination = value; }

    const float& GetDeclinationVariation() const { return m_DeclinationVariation; }
    float& GetDeclinationVariation() { return m_DeclinationVariation; }
    void SetDeclinationVariation(const float& value) { m_DeclinationVariation = value; }

    const float& GetPlanarAngle() const { return m_PlanarAngle; }
    float& GetPlanarAngle() { return m_PlanarAngle; }
    void SetPlanarAngle(const float& value) { m_PlanarAngle = value; }

    const float& GetPlanarAngleVariation() const { return m_PlanarAngleVariation; }
    float& GetPlanarAngleVariation() { return m_PlanarAngleVariation; }
    void SetPlanarAngleVariation(const float& value) { m_PlanarAngleVariation = value; }

    const Color4& GetInitialColor() const { return m_InitialColor; }
    Color4& GetInitialColor() { return m_InitialColor; }
    void SetInitialColor(const Color4& value) { m_InitialColor = value; }

    const float& GetInitialRadius() const { return m_InitialRadius; }
    float& GetInitialRadius() { return m_InitialRadius; }
    void SetInitialRadius(const float& value) { m_InitialRadius = value; }

    const float& GetRadiusVariation() const { return m_RadiusVariation; }
    float& GetRadiusVariation() { return m_RadiusVariation; }
    void SetRadiusVariation(const float& value) { m_RadiusVariation = value; }

    const float& GetLifeSpan() const { return m_LifeSpan; }
    float& GetLifeSpan() { return m_LifeSpan; }
    void SetLifeSpan(const float& value) { m_LifeSpan = value; }

    const float& GetLifeSpanVariation() const { return m_LifeSpanVariation; }
    float& GetLifeSpanVariation() { return m_LifeSpanVariation; }
    void SetLifeSpanVariation(const float& value) { m_LifeSpanVariation = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
