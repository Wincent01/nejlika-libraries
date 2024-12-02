#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "Matrix33.hpp"
#include "Vector3.hpp"
#include "NiProperty.hpp"
#include "BoundingBox.hpp"
#include "NiCollisionObject.hpp"
#include "NiObjectNET.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Generic node object.
 *         
 */
class NiAVObject : public NiObjectNET
{
protected:
    /**
     * Some flags; commonly 0x000C or 0x000A.
     */
    Flags m_Flags;
    /**
     * Unknown Flag
     */
    ushort m_UnknownShort1;
    /**
     * The translation vector.
     */
    Vector3 m_Translation;
    /**
     * The rotation part of the transformation matrix.
     */
    Matrix33 m_Rotation;
    /**
     * Scaling part (only uniform scaling is supported).
     */
    float m_Scale;
    /**
     * Unknown function. Always seems to be (0, 0, 0)
     */
    Vector3 m_Velocity;
    /**
     * The number of property objects referenced.
     */
    uint m_NumProperties;
    /**
     * List of node properties.
     */
    std::vector<Pointer<class NiProperty*>> m_Properties;
    /**
     * Always 2,0,2,0.
     */
    std::vector<uint> m_Unknown1;
    /**
     * 0 or 1.
     */
    byte m_Unknown2;
    /**
     * Do we have a bounding box?
     */
    bool m_HasBoundingBox;
    /**
     * The bounding box.
     */
    BoundingBox m_BoundingBox;
    /**
     * Refers to NiCollisionObject, which is usually a bounding box or other simple collision shape.  In Oblivion this links the Havok objects.
     */
    Pointer<class NiCollisionObject*> m_CollisionObject;

public:
    const Flags& GetFlags() const { return m_Flags; }
    Flags& GetFlags() { return m_Flags; }
    void SetFlags(const Flags& value) { m_Flags = value; }

    const ushort& GetUnknownShort1() const { return m_UnknownShort1; }
    ushort& GetUnknownShort1() { return m_UnknownShort1; }
    void SetUnknownShort1(const ushort& value) { m_UnknownShort1 = value; }

    const Vector3& GetTranslation() const { return m_Translation; }
    Vector3& GetTranslation() { return m_Translation; }
    void SetTranslation(const Vector3& value) { m_Translation = value; }

    const Matrix33& GetRotation() const { return m_Rotation; }
    Matrix33& GetRotation() { return m_Rotation; }
    void SetRotation(const Matrix33& value) { m_Rotation = value; }

    const float& GetScale() const { return m_Scale; }
    float& GetScale() { return m_Scale; }
    void SetScale(const float& value) { m_Scale = value; }

    const Vector3& GetVelocity() const { return m_Velocity; }
    Vector3& GetVelocity() { return m_Velocity; }
    void SetVelocity(const Vector3& value) { m_Velocity = value; }

    const uint& GetNumProperties() const { return m_NumProperties; }
    uint& GetNumProperties() { return m_NumProperties; }
    void SetNumProperties(const uint& value) { m_NumProperties = value; }

    const std::vector<Pointer<class NiProperty*>>& GetProperties() const { return m_Properties; }
    std::vector<Pointer<class NiProperty*>>& GetProperties() { return m_Properties; }
    void SetProperties(const std::vector<Pointer<class NiProperty*>>& value) { m_Properties = value; }

    const std::vector<uint>& GetUnknown1() const { return m_Unknown1; }
    std::vector<uint>& GetUnknown1() { return m_Unknown1; }
    void SetUnknown1(const std::vector<uint>& value) { m_Unknown1 = value; }

    const byte& GetUnknown2() const { return m_Unknown2; }
    byte& GetUnknown2() { return m_Unknown2; }
    void SetUnknown2(const byte& value) { m_Unknown2 = value; }

    const bool& GetHasBoundingBox() const { return m_HasBoundingBox; }
    bool& GetHasBoundingBox() { return m_HasBoundingBox; }
    void SetHasBoundingBox(const bool& value) { m_HasBoundingBox = value; }

    const BoundingBox& GetBoundingBox() const { return m_BoundingBox; }
    BoundingBox& GetBoundingBox() { return m_BoundingBox; }
    void SetBoundingBox(const BoundingBox& value) { m_BoundingBox = value; }

    const Pointer<class NiCollisionObject*>& GetCollisionObject() const { return m_CollisionObject; }
    Pointer<class NiCollisionObject*>& GetCollisionObject() { return m_CollisionObject; }
    void SetCollisionObject(const Pointer<class NiCollisionObject*>& value) { m_CollisionObject = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
