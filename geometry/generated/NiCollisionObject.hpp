#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiAVObject.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         This is the most common collision object found in NIF files. It acts as a real object that
 *         is visible and possibly (if the body allows for it) interactive. The node itself
 *         is simple, it only has three properties.
 *         For this type of collision object, bhkRigidBody or bhkRigidBodyT is generally used.
 *         
 */
class NiCollisionObject : public NiObject
{
protected:
    /**
     * Index of the AV object referring to this collision object.
     */
    Pointer<class NiAVObject*> m_Target;

public:
    const Pointer<class NiAVObject*>& GetTarget() const { return m_Target; }
    Pointer<class NiAVObject*>& GetTarget() { return m_Target; }
    void SetTarget(const Pointer<class NiAVObject*>& value) { m_Target = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
