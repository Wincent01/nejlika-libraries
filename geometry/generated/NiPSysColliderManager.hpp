#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSysCollider.hpp"
#include "NiPSysModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle modifier that adds a defined shape to act as a collision object for particles to interact with.
 *         
 */
class NiPSysColliderManager : public NiPSysModifier
{
protected:
    /**
     * Link to a NiPSysPlanarCollider or NiPSysSphericalCollider.
     */
    Pointer<class NiPSysCollider*> m_Collider;

public:
    const Pointer<class NiPSysCollider*>& GetCollider() const { return m_Collider; }
    Pointer<class NiPSysCollider*>& GetCollider() { return m_Collider; }
    void SetCollider(const Pointer<class NiPSysCollider*>& value) { m_Collider = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
