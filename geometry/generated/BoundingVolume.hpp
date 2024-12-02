#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "BoundVolumeType.hpp"
#include "SphereBV.hpp"
#include "BoxBV.hpp"
#include "CapsuleBV.hpp"
#include "UnionBV.hpp"
#include "HalfSpaceBV.hpp"
namespace nejlika::geometry {

class UnionBV;

class BoundingVolume : public Construct
{
protected:
    /**
     * Type of collision data.
     */
    BoundVolumeType m_CollisionType;
    /**
     * Sphere
     */
    SphereBV m_Sphere;
    /**
     * Box
     */
    BoxBV m_Box;
    /**
     * Capsule
     */
    CapsuleBV m_Capsule;
    /**
     * Union
     */
    UnionBV m_Union;
    /**
     * Half Space
     */
    HalfSpaceBV m_HalfSpace;

public:
    const BoundVolumeType& GetCollisionType() const { return m_CollisionType; }
    BoundVolumeType& GetCollisionType() { return m_CollisionType; }
    void SetCollisionType(const BoundVolumeType& value) { m_CollisionType = value; }

    const SphereBV& GetSphere() const { return m_Sphere; }
    SphereBV& GetSphere() { return m_Sphere; }
    void SetSphere(const SphereBV& value) { m_Sphere = value; }

    const BoxBV& GetBox() const { return m_Box; }
    BoxBV& GetBox() { return m_Box; }
    void SetBox(const BoxBV& value) { m_Box = value; }

    const CapsuleBV& GetCapsule() const { return m_Capsule; }
    CapsuleBV& GetCapsule() { return m_Capsule; }
    void SetCapsule(const CapsuleBV& value) { m_Capsule = value; }

    const UnionBV& GetUnion() const { return m_Union; }
    UnionBV& GetUnion() { return m_Union; }
    void SetUnion(const UnionBV& value) { m_Union = value; }

    const HalfSpaceBV& GetHalfSpace() const { return m_HalfSpace; }
    HalfSpaceBV& GetHalfSpace() { return m_HalfSpace; }
    void SetHalfSpace(const HalfSpaceBV& value) { m_HalfSpace = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
