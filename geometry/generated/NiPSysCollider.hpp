#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSysSpawnModifier.hpp"
#include "NiObject.hpp"
#include "NiObject.hpp"
#include "NiNode.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle system collider.
 *         
 */
class NiPSysCollider : public NiObject
{
protected:
    /**
     * Defines amount of bounce the collider object has.
     */
    float m_Bounce;
    /**
     * Unknown.
     */
    bool m_SpawnOnCollide;
    /**
     * Kill particles on impact if set to yes.
     */
    bool m_DieOnCollide;
    /**
     * Link to NiPSysSpawnModifier object?
     */
    Pointer<class NiPSysSpawnModifier*> m_SpawnModifier;
    /**
     * Link to parent.
     */
    Pointer<class NiObject*> m_Parent;
    /**
     * The next collider.
     */
    Pointer<class NiObject*> m_NextCollider;
    /**
     * Links to a NiNode that will define where in object space the collider is located/oriented.
     */
    Pointer<class NiNode*> m_ColliderObject;

public:
    const float& GetBounce() const { return m_Bounce; }
    float& GetBounce() { return m_Bounce; }
    void SetBounce(const float& value) { m_Bounce = value; }

    const bool& GetSpawnOnCollide() const { return m_SpawnOnCollide; }
    bool& GetSpawnOnCollide() { return m_SpawnOnCollide; }
    void SetSpawnOnCollide(const bool& value) { m_SpawnOnCollide = value; }

    const bool& GetDieOnCollide() const { return m_DieOnCollide; }
    bool& GetDieOnCollide() { return m_DieOnCollide; }
    void SetDieOnCollide(const bool& value) { m_DieOnCollide = value; }

    const Pointer<class NiPSysSpawnModifier*>& GetSpawnModifier() const { return m_SpawnModifier; }
    Pointer<class NiPSysSpawnModifier*>& GetSpawnModifier() { return m_SpawnModifier; }
    void SetSpawnModifier(const Pointer<class NiPSysSpawnModifier*>& value) { m_SpawnModifier = value; }

    const Pointer<class NiObject*>& GetParent() const { return m_Parent; }
    Pointer<class NiObject*>& GetParent() { return m_Parent; }
    void SetParent(const Pointer<class NiObject*>& value) { m_Parent = value; }

    const Pointer<class NiObject*>& GetNextCollider() const { return m_NextCollider; }
    Pointer<class NiObject*>& GetNextCollider() { return m_NextCollider; }
    void SetNextCollider(const Pointer<class NiObject*>& value) { m_NextCollider = value; }

    const Pointer<class NiNode*>& GetColliderObject() const { return m_ColliderObject; }
    Pointer<class NiNode*>& GetColliderObject() { return m_ColliderObject; }
    void SetColliderObject(const Pointer<class NiNode*>& value) { m_ColliderObject = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
