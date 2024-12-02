#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "Color4.hpp"
#include "Vector3.hpp"
#include "NiObject.hpp"
#include "Vector3.hpp"
#include "Vector3.hpp"
#include "NiObject.hpp"
#include "Particle.hpp"
#include "NiObject.hpp"
#include "NiParticleModifier.hpp"
#include "NiObject.hpp"
#include "NiColorData.hpp"
#include "NiTimeController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A generic particle system time controller object.
 *         
 */
class NiParticleSystemController : public NiTimeController
{
protected:
    /**
     * Particle speed in old files
     */
    uint m_OldSpeed;
    /**
     * Particle speed
     */
    float m_Speed;
    /**
     * Particle random speed modifier
     */
    float m_SpeedRandom;
    /**
     * 
     *             vertical emit direction [radians]
     *             0.0 : up
     *             1.6 : horizontal
     *             3.1416 : down
     *         
     */
    float m_VerticalDirection;
    /**
     * emitter's vertical opening angle [radians]
     */
    float m_VerticalAngle;
    /**
     * horizontal emit direction
     */
    float m_HorizontalDirection;
    /**
     * emitter's horizontal opening angle
     */
    float m_HorizontalAngle;
    /**
     * Unknown.
     */
    Vector3 m_UnknownNormal;
    /**
     * Unknown.
     */
    Color4 m_UnknownColor;
    /**
     * Particle size
     */
    float m_Size;
    /**
     * Particle emit start time
     */
    float m_EmitStartTime;
    /**
     * Particle emit stop time
     */
    float m_EmitStopTime;
    /**
     * Unknown byte, (=0)
     */
    byte m_UnknownByte;
    /**
     * Particle emission rate in old files
     */
    uint m_OldEmitRate;
    /**
     * Particle emission rate (particles per second)
     */
    float m_EmitRate;
    /**
     * Particle lifetime
     */
    float m_Lifetime;
    /**
     * Particle lifetime random modifier
     */
    float m_LifetimeRandom;
    /**
     * Bit 0: Emit Rate toggle bit (0 = auto adjust, 1 = use Emit Rate value)
     */
    ushort m_EmitFlags;
    /**
     * Particle random start translation vector
     */
    Vector3 m_StartRandom;
    /**
     * This index targets the particle emitter object (TODO: find out what type of object this refers to).
     */
    Pointer<class NiObject*> m_Emitter;
    /**
     * ? short=0 ?
     */
    ushort m_UnknownShort2;
    /**
     * ? float=1.0 ?
     */
    float m_UnknownFloat13;
    /**
     * ? int=1 ?
     */
    uint m_UnknownInt1;
    /**
     * ? int=0 ?
     */
    uint m_UnknownInt2;
    /**
     * ? short=0 ?
     */
    ushort m_UnknownShort3;
    /**
     * Particle velocity
     */
    Vector3 m_ParticleVelocity;
    /**
     * Unknown
     */
    Vector3 m_ParticleUnknownVector;
    /**
     * The particle's age.
     */
    float m_ParticleLifetime;
    Pointer<class NiObject*> m_ParticleLink;
    /**
     * Timestamp of the last update.
     */
    uint m_ParticleTimestamp;
    /**
     * Unknown short
     */
    ushort m_ParticleUnknownShort;
    /**
     * Particle/vertex index matches array index
     */
    ushort m_ParticleVertexId;
    /**
     * Size of the following array. (Maximum number of simultaneous active particles)
     */
    ushort m_NumParticles;
    /**
     * Number of valid entries in the following array. (Number of active particles at the time the system was saved)
     */
    ushort m_NumValid;
    /**
     * Individual particle modifiers?
     */
    std::vector<Particle> m_Particles;
    /**
     * unknown int (=0xffffffff)
     */
    Pointer<class NiObject*> m_UnknownLink;
    /**
     * Link to some optional particle modifiers (NiGravity, NiParticleGrowFade, NiParticleBomb, ...)
     */
    Pointer<class NiParticleModifier*> m_ParticleExtra;
    /**
     * Unknown int (=0xffffffff)
     */
    Pointer<class NiObject*> m_UnknownLink2;
    /**
     * Trailing null byte
     */
    byte m_Trailer;
    Pointer<class NiColorData*> m_ColorData;
    float m_UnknownFloat1;
    std::vector<float> m_UnknownFloats2;

public:
    const uint& GetOldSpeed() const { return m_OldSpeed; }
    uint& GetOldSpeed() { return m_OldSpeed; }
    void SetOldSpeed(const uint& value) { m_OldSpeed = value; }

    const float& GetSpeed() const { return m_Speed; }
    float& GetSpeed() { return m_Speed; }
    void SetSpeed(const float& value) { m_Speed = value; }

    const float& GetSpeedRandom() const { return m_SpeedRandom; }
    float& GetSpeedRandom() { return m_SpeedRandom; }
    void SetSpeedRandom(const float& value) { m_SpeedRandom = value; }

    const float& GetVerticalDirection() const { return m_VerticalDirection; }
    float& GetVerticalDirection() { return m_VerticalDirection; }
    void SetVerticalDirection(const float& value) { m_VerticalDirection = value; }

    const float& GetVerticalAngle() const { return m_VerticalAngle; }
    float& GetVerticalAngle() { return m_VerticalAngle; }
    void SetVerticalAngle(const float& value) { m_VerticalAngle = value; }

    const float& GetHorizontalDirection() const { return m_HorizontalDirection; }
    float& GetHorizontalDirection() { return m_HorizontalDirection; }
    void SetHorizontalDirection(const float& value) { m_HorizontalDirection = value; }

    const float& GetHorizontalAngle() const { return m_HorizontalAngle; }
    float& GetHorizontalAngle() { return m_HorizontalAngle; }
    void SetHorizontalAngle(const float& value) { m_HorizontalAngle = value; }

    const Vector3& GetUnknownNormal() const { return m_UnknownNormal; }
    Vector3& GetUnknownNormal() { return m_UnknownNormal; }
    void SetUnknownNormal(const Vector3& value) { m_UnknownNormal = value; }

    const Color4& GetUnknownColor() const { return m_UnknownColor; }
    Color4& GetUnknownColor() { return m_UnknownColor; }
    void SetUnknownColor(const Color4& value) { m_UnknownColor = value; }

    const float& GetSize() const { return m_Size; }
    float& GetSize() { return m_Size; }
    void SetSize(const float& value) { m_Size = value; }

    const float& GetEmitStartTime() const { return m_EmitStartTime; }
    float& GetEmitStartTime() { return m_EmitStartTime; }
    void SetEmitStartTime(const float& value) { m_EmitStartTime = value; }

    const float& GetEmitStopTime() const { return m_EmitStopTime; }
    float& GetEmitStopTime() { return m_EmitStopTime; }
    void SetEmitStopTime(const float& value) { m_EmitStopTime = value; }

    const byte& GetUnknownByte() const { return m_UnknownByte; }
    byte& GetUnknownByte() { return m_UnknownByte; }
    void SetUnknownByte(const byte& value) { m_UnknownByte = value; }

    const uint& GetOldEmitRate() const { return m_OldEmitRate; }
    uint& GetOldEmitRate() { return m_OldEmitRate; }
    void SetOldEmitRate(const uint& value) { m_OldEmitRate = value; }

    const float& GetEmitRate() const { return m_EmitRate; }
    float& GetEmitRate() { return m_EmitRate; }
    void SetEmitRate(const float& value) { m_EmitRate = value; }

    const float& GetLifetime() const { return m_Lifetime; }
    float& GetLifetime() { return m_Lifetime; }
    void SetLifetime(const float& value) { m_Lifetime = value; }

    const float& GetLifetimeRandom() const { return m_LifetimeRandom; }
    float& GetLifetimeRandom() { return m_LifetimeRandom; }
    void SetLifetimeRandom(const float& value) { m_LifetimeRandom = value; }

    const ushort& GetEmitFlags() const { return m_EmitFlags; }
    ushort& GetEmitFlags() { return m_EmitFlags; }
    void SetEmitFlags(const ushort& value) { m_EmitFlags = value; }

    const Vector3& GetStartRandom() const { return m_StartRandom; }
    Vector3& GetStartRandom() { return m_StartRandom; }
    void SetStartRandom(const Vector3& value) { m_StartRandom = value; }

    const Pointer<class NiObject*>& GetEmitter() const { return m_Emitter; }
    Pointer<class NiObject*>& GetEmitter() { return m_Emitter; }
    void SetEmitter(const Pointer<class NiObject*>& value) { m_Emitter = value; }

    const ushort& GetUnknownShort2() const { return m_UnknownShort2; }
    ushort& GetUnknownShort2() { return m_UnknownShort2; }
    void SetUnknownShort2(const ushort& value) { m_UnknownShort2 = value; }

    const float& GetUnknownFloat13() const { return m_UnknownFloat13; }
    float& GetUnknownFloat13() { return m_UnknownFloat13; }
    void SetUnknownFloat13(const float& value) { m_UnknownFloat13 = value; }

    const uint& GetUnknownInt1() const { return m_UnknownInt1; }
    uint& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const uint& value) { m_UnknownInt1 = value; }

    const uint& GetUnknownInt2() const { return m_UnknownInt2; }
    uint& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const uint& value) { m_UnknownInt2 = value; }

    const ushort& GetUnknownShort3() const { return m_UnknownShort3; }
    ushort& GetUnknownShort3() { return m_UnknownShort3; }
    void SetUnknownShort3(const ushort& value) { m_UnknownShort3 = value; }

    const Vector3& GetParticleVelocity() const { return m_ParticleVelocity; }
    Vector3& GetParticleVelocity() { return m_ParticleVelocity; }
    void SetParticleVelocity(const Vector3& value) { m_ParticleVelocity = value; }

    const Vector3& GetParticleUnknownVector() const { return m_ParticleUnknownVector; }
    Vector3& GetParticleUnknownVector() { return m_ParticleUnknownVector; }
    void SetParticleUnknownVector(const Vector3& value) { m_ParticleUnknownVector = value; }

    const float& GetParticleLifetime() const { return m_ParticleLifetime; }
    float& GetParticleLifetime() { return m_ParticleLifetime; }
    void SetParticleLifetime(const float& value) { m_ParticleLifetime = value; }

    const Pointer<class NiObject*>& GetParticleLink() const { return m_ParticleLink; }
    Pointer<class NiObject*>& GetParticleLink() { return m_ParticleLink; }
    void SetParticleLink(const Pointer<class NiObject*>& value) { m_ParticleLink = value; }

    const uint& GetParticleTimestamp() const { return m_ParticleTimestamp; }
    uint& GetParticleTimestamp() { return m_ParticleTimestamp; }
    void SetParticleTimestamp(const uint& value) { m_ParticleTimestamp = value; }

    const ushort& GetParticleUnknownShort() const { return m_ParticleUnknownShort; }
    ushort& GetParticleUnknownShort() { return m_ParticleUnknownShort; }
    void SetParticleUnknownShort(const ushort& value) { m_ParticleUnknownShort = value; }

    const ushort& GetParticleVertexId() const { return m_ParticleVertexId; }
    ushort& GetParticleVertexId() { return m_ParticleVertexId; }
    void SetParticleVertexId(const ushort& value) { m_ParticleVertexId = value; }

    const ushort& GetNumParticles() const { return m_NumParticles; }
    ushort& GetNumParticles() { return m_NumParticles; }
    void SetNumParticles(const ushort& value) { m_NumParticles = value; }

    const ushort& GetNumValid() const { return m_NumValid; }
    ushort& GetNumValid() { return m_NumValid; }
    void SetNumValid(const ushort& value) { m_NumValid = value; }

    const std::vector<Particle>& GetParticles() const { return m_Particles; }
    std::vector<Particle>& GetParticles() { return m_Particles; }
    void SetParticles(const std::vector<Particle>& value) { m_Particles = value; }

    const Pointer<class NiObject*>& GetUnknownLink() const { return m_UnknownLink; }
    Pointer<class NiObject*>& GetUnknownLink() { return m_UnknownLink; }
    void SetUnknownLink(const Pointer<class NiObject*>& value) { m_UnknownLink = value; }

    const Pointer<class NiParticleModifier*>& GetParticleExtra() const { return m_ParticleExtra; }
    Pointer<class NiParticleModifier*>& GetParticleExtra() { return m_ParticleExtra; }
    void SetParticleExtra(const Pointer<class NiParticleModifier*>& value) { m_ParticleExtra = value; }

    const Pointer<class NiObject*>& GetUnknownLink2() const { return m_UnknownLink2; }
    Pointer<class NiObject*>& GetUnknownLink2() { return m_UnknownLink2; }
    void SetUnknownLink2(const Pointer<class NiObject*>& value) { m_UnknownLink2 = value; }

    const byte& GetTrailer() const { return m_Trailer; }
    byte& GetTrailer() { return m_Trailer; }
    void SetTrailer(const byte& value) { m_Trailer = value; }

    const Pointer<class NiColorData*>& GetColorData() const { return m_ColorData; }
    Pointer<class NiColorData*>& GetColorData() { return m_ColorData; }
    void SetColorData(const Pointer<class NiColorData*>& value) { m_ColorData = value; }

    const float& GetUnknownFloat1() const { return m_UnknownFloat1; }
    float& GetUnknownFloat1() { return m_UnknownFloat1; }
    void SetUnknownFloat1(const float& value) { m_UnknownFloat1 = value; }

    const std::vector<float>& GetUnknownFloats2() const { return m_UnknownFloats2; }
    std::vector<float>& GetUnknownFloats2() { return m_UnknownFloats2; }
    void SetUnknownFloats2(const std::vector<float>& value) { m_UnknownFloats2 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
