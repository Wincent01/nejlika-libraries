#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Quaternion.hpp"
#include "NiObject.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"
#include "NiGeometryData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Generic rotating particles data object.
 *         
 */
class NiParticlesData : public NiGeometryData
{
protected:
    /**
     * The maximum number of particles (matches the number of vertices).
     */
    ushort m_NumParticles;
    /**
     * The particles' size.
     */
    float m_ParticleRadius;
    /**
     * Is the particle size array present?
     */
    bool m_HasRadii;
    /**
     * The individual particel sizes.
     */
    std::vector<float> m_Radii;
    /**
     * The number of active particles at the time the system was saved. This is also the number of valid entries in the following arrays.
     */
    ushort m_NumActive;
    /**
     * Is the particle size array present?
     */
    bool m_HasSizes;
    /**
     * The individual particel sizes.
     */
    std::vector<float> m_Sizes;
    /**
     * Is the particle rotation array present?
     */
    bool m_HasRotations;
    /**
     * The individual particle rotations.
     */
    std::vector<Quaternion> m_Rotations;
    /**
     * Unknown, probably a boolean.
     */
    byte m_UnknownByte1;
    /**
     * Unknown
     */
    Pointer<class NiObject*> m_UnknownLink;
    /**
     * Are the angles of rotation present?
     */
    bool m_HasRotationAngles;
    /**
     * Angles of rotation
     */
    std::vector<float> m_RotationAngles;
    /**
     * Are axes of rotation present?
     */
    bool m_HasRotationAxes;
    /**
     * Unknown
     */
    std::vector<Vector3> m_RotationAxes;
    /**
     * if value is no, a single image rendered
     */
    bool m_HasUVQuadrants;
    /**
     * 2,4,8,16,32,64 are potential values. If "Has" was no then this should be 256, which represents a 16x16 framed image, which is invalid
     */
    byte m_NumUVQuadrants;
    std::vector<Vector4> m_UVQuadrants;
    /**
     * Unknown
     */
    byte m_UnknownByte2;

public:
    const ushort& GetNumParticles() const { return m_NumParticles; }
    ushort& GetNumParticles() { return m_NumParticles; }
    void SetNumParticles(const ushort& value) { m_NumParticles = value; }

    const float& GetParticleRadius() const { return m_ParticleRadius; }
    float& GetParticleRadius() { return m_ParticleRadius; }
    void SetParticleRadius(const float& value) { m_ParticleRadius = value; }

    const bool& GetHasRadii() const { return m_HasRadii; }
    bool& GetHasRadii() { return m_HasRadii; }
    void SetHasRadii(const bool& value) { m_HasRadii = value; }

    const std::vector<float>& GetRadii() const { return m_Radii; }
    std::vector<float>& GetRadii() { return m_Radii; }
    void SetRadii(const std::vector<float>& value) { m_Radii = value; }

    const ushort& GetNumActive() const { return m_NumActive; }
    ushort& GetNumActive() { return m_NumActive; }
    void SetNumActive(const ushort& value) { m_NumActive = value; }

    const bool& GetHasSizes() const { return m_HasSizes; }
    bool& GetHasSizes() { return m_HasSizes; }
    void SetHasSizes(const bool& value) { m_HasSizes = value; }

    const std::vector<float>& GetSizes() const { return m_Sizes; }
    std::vector<float>& GetSizes() { return m_Sizes; }
    void SetSizes(const std::vector<float>& value) { m_Sizes = value; }

    const bool& GetHasRotations() const { return m_HasRotations; }
    bool& GetHasRotations() { return m_HasRotations; }
    void SetHasRotations(const bool& value) { m_HasRotations = value; }

    const std::vector<Quaternion>& GetRotations() const { return m_Rotations; }
    std::vector<Quaternion>& GetRotations() { return m_Rotations; }
    void SetRotations(const std::vector<Quaternion>& value) { m_Rotations = value; }

    const byte& GetUnknownByte1() const { return m_UnknownByte1; }
    byte& GetUnknownByte1() { return m_UnknownByte1; }
    void SetUnknownByte1(const byte& value) { m_UnknownByte1 = value; }

    const Pointer<class NiObject*>& GetUnknownLink() const { return m_UnknownLink; }
    Pointer<class NiObject*>& GetUnknownLink() { return m_UnknownLink; }
    void SetUnknownLink(const Pointer<class NiObject*>& value) { m_UnknownLink = value; }

    const bool& GetHasRotationAngles() const { return m_HasRotationAngles; }
    bool& GetHasRotationAngles() { return m_HasRotationAngles; }
    void SetHasRotationAngles(const bool& value) { m_HasRotationAngles = value; }

    const std::vector<float>& GetRotationAngles() const { return m_RotationAngles; }
    std::vector<float>& GetRotationAngles() { return m_RotationAngles; }
    void SetRotationAngles(const std::vector<float>& value) { m_RotationAngles = value; }

    const bool& GetHasRotationAxes() const { return m_HasRotationAxes; }
    bool& GetHasRotationAxes() { return m_HasRotationAxes; }
    void SetHasRotationAxes(const bool& value) { m_HasRotationAxes = value; }

    const std::vector<Vector3>& GetRotationAxes() const { return m_RotationAxes; }
    std::vector<Vector3>& GetRotationAxes() { return m_RotationAxes; }
    void SetRotationAxes(const std::vector<Vector3>& value) { m_RotationAxes = value; }

    const bool& GetHasUVQuadrants() const { return m_HasUVQuadrants; }
    bool& GetHasUVQuadrants() { return m_HasUVQuadrants; }
    void SetHasUVQuadrants(const bool& value) { m_HasUVQuadrants = value; }

    const byte& GetNumUVQuadrants() const { return m_NumUVQuadrants; }
    byte& GetNumUVQuadrants() { return m_NumUVQuadrants; }
    void SetNumUVQuadrants(const byte& value) { m_NumUVQuadrants = value; }

    const std::vector<Vector4>& GetUVQuadrants() const { return m_UVQuadrants; }
    std::vector<Vector4>& GetUVQuadrants() { return m_UVQuadrants; }
    void SetUVQuadrants(const std::vector<Vector4>& value) { m_UVQuadrants = value; }

    const byte& GetUnknownByte2() const { return m_UnknownByte2; }
    byte& GetUnknownByte2() { return m_UnknownByte2; }
    void SetUnknownByte2(const byte& value) { m_UnknownByte2 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
