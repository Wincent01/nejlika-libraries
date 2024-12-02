#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "bhkConstraint.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A prismatic constraint.
 * 
 *         
 */
class bhkPrismaticConstraint : public bhkConstraint
{
protected:
    /**
     * Pivot A.
     */
    Vector4 m_PivotA;
    /**
     * 4x4 rotation matrix, rotates the child entity.
     */
    std::vector<Vector4> m_RotationMatrixA;
    /**
     * Pivot B.
     */
    Vector4 m_PivotB;
    /**
     * Describes the axis the object is able to travel along. Unit vector.
     */
    Vector4 m_SlidingB;
    /**
     * Plane normal. Describes the plane the object is able to move on.
     */
    Vector4 m_PlaneB;
    /**
     * Describes the axis the object is able to travel along. Unit vector.
     */
    Vector4 m_SlidingA;
    /**
     * Rotation axis.
     */
    Vector4 m_RotationA;
    /**
     * Plane normal. Describes the plane the object is able to move on.
     */
    Vector4 m_PlaneA;
    /**
     * Rotation axis.
     */
    Vector4 m_RotationB;
    /**
     * Describe the min distance the object is able to travel.
     */
    float m_MinDistance;
    /**
     * Describe the max distance the object is able to travel.
     */
    float m_MaxDistance;
    /**
     * Friction.
     */
    float m_Friction;
    /**
     * Unknown. Do not set this to anything over 0 as it will crash the game.
     */
    byte m_UnknownByte1;

public:
    const Vector4& GetPivotA() const { return m_PivotA; }
    Vector4& GetPivotA() { return m_PivotA; }
    void SetPivotA(const Vector4& value) { m_PivotA = value; }

    const std::vector<Vector4>& GetRotationMatrixA() const { return m_RotationMatrixA; }
    std::vector<Vector4>& GetRotationMatrixA() { return m_RotationMatrixA; }
    void SetRotationMatrixA(const std::vector<Vector4>& value) { m_RotationMatrixA = value; }

    const Vector4& GetPivotB() const { return m_PivotB; }
    Vector4& GetPivotB() { return m_PivotB; }
    void SetPivotB(const Vector4& value) { m_PivotB = value; }

    const Vector4& GetSlidingB() const { return m_SlidingB; }
    Vector4& GetSlidingB() { return m_SlidingB; }
    void SetSlidingB(const Vector4& value) { m_SlidingB = value; }

    const Vector4& GetPlaneB() const { return m_PlaneB; }
    Vector4& GetPlaneB() { return m_PlaneB; }
    void SetPlaneB(const Vector4& value) { m_PlaneB = value; }

    const Vector4& GetSlidingA() const { return m_SlidingA; }
    Vector4& GetSlidingA() { return m_SlidingA; }
    void SetSlidingA(const Vector4& value) { m_SlidingA = value; }

    const Vector4& GetRotationA() const { return m_RotationA; }
    Vector4& GetRotationA() { return m_RotationA; }
    void SetRotationA(const Vector4& value) { m_RotationA = value; }

    const Vector4& GetPlaneA() const { return m_PlaneA; }
    Vector4& GetPlaneA() { return m_PlaneA; }
    void SetPlaneA(const Vector4& value) { m_PlaneA = value; }

    const Vector4& GetRotationB() const { return m_RotationB; }
    Vector4& GetRotationB() { return m_RotationB; }
    void SetRotationB(const Vector4& value) { m_RotationB = value; }

    const float& GetMinDistance() const { return m_MinDistance; }
    float& GetMinDistance() { return m_MinDistance; }
    void SetMinDistance(const float& value) { m_MinDistance = value; }

    const float& GetMaxDistance() const { return m_MaxDistance; }
    float& GetMaxDistance() { return m_MaxDistance; }
    void SetMaxDistance(const float& value) { m_MaxDistance = value; }

    const float& GetFriction() const { return m_Friction; }
    float& GetFriction() { return m_Friction; }
    void SetFriction(const float& value) { m_Friction = value; }

    const byte& GetUnknownByte1() const { return m_UnknownByte1; }
    byte& GetUnknownByte1() { return m_UnknownByte1; }
    void SetUnknownByte1(const byte& value) { m_UnknownByte1 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
