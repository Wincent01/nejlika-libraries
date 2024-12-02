#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiObject.hpp"
#include "NiCollisionObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Havok related collision object?
 *         
 */
class bhkNiCollisionObject : public NiCollisionObject
{
protected:
    /**
     * 
     *             Set to 1 for most objects, and to 41 for animated objects (OL_ANIM_STATIC). Bits: 0=Active 2=Notify 3=Set Local 6=Reset.
     *         
     */
    Flags m_Flags;
    /**
     * Links to the collision object data
     */
    Pointer<class NiObject*> m_Body;

public:
    const Flags& GetFlags() const { return m_Flags; }
    Flags& GetFlags() { return m_Flags; }
    void SetFlags(const Flags& value) { m_Flags = value; }

    const Pointer<class NiObject*>& GetBody() const { return m_Body; }
    Pointer<class NiObject*>& GetBody() { return m_Body; }
    void SetBody(const Pointer<class NiObject*>& value) { m_Body = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
