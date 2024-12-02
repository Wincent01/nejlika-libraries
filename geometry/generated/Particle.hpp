#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "Vector3.hpp"
namespace nejlika::geometry {


/**
 * 
 *         particle array entry
 *         
 */
class Particle : public Construct
{
protected:
    /**
     * Particle velocity
     */
    Vector3 m_Velocity;
    /**
     * Unknown
     */
    Vector3 m_UnknownVector;
    /**
     * The particle's age.
     */
    float m_Lifetime;
    /**
     * Maximum age of the particle.
     */
    float m_Lifespan;
    /**
     * Timestamp of the last update.
     */
    float m_Timestamp;
    /**
     * Unknown short
     */
    ushort m_UnknownShort;
    /**
     * Particle/vertex index matches array index
     */
    ushort m_VertexID;

public:
    const Vector3& GetVelocity() const { return m_Velocity; }
    Vector3& GetVelocity() { return m_Velocity; }
    void SetVelocity(const Vector3& value) { m_Velocity = value; }

    const Vector3& GetUnknownVector() const { return m_UnknownVector; }
    Vector3& GetUnknownVector() { return m_UnknownVector; }
    void SetUnknownVector(const Vector3& value) { m_UnknownVector = value; }

    const float& GetLifetime() const { return m_Lifetime; }
    float& GetLifetime() { return m_Lifetime; }
    void SetLifetime(const float& value) { m_Lifetime = value; }

    const float& GetLifespan() const { return m_Lifespan; }
    float& GetLifespan() { return m_Lifespan; }
    void SetLifespan(const float& value) { m_Lifespan = value; }

    const float& GetTimestamp() const { return m_Timestamp; }
    float& GetTimestamp() { return m_Timestamp; }
    void SetTimestamp(const float& value) { m_Timestamp = value; }

    const ushort& GetUnknownShort() const { return m_UnknownShort; }
    ushort& GetUnknownShort() { return m_UnknownShort; }
    void SetUnknownShort(const ushort& value) { m_UnknownShort = value; }

    const ushort& GetVertexID() const { return m_VertexID; }
    ushort& GetVertexID() { return m_VertexID; }
    void SetVertexID(const ushort& value) { m_VertexID = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
