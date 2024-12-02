#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiAVObject.hpp"
#include "NiPSysModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Base for all force field particle modifiers.
 *         
 */
class NiPSysFieldModifier : public NiPSysModifier
{
protected:
    /**
     * Force Field Object
     */
    Pointer<class NiAVObject*> m_FieldObject;
    /**
     * Magnitude of the force
     */
    float m_Magnitude;
    /**
     * Controls how quick the field diminishes
     */
    float m_Attenuation;
    /**
     * Use maximum distance
     */
    bool m_UseMaxDistance;
    /**
     * Maximum distance
     */
    float m_MaxDistance;

public:
    const Pointer<class NiAVObject*>& GetFieldObject() const { return m_FieldObject; }
    Pointer<class NiAVObject*>& GetFieldObject() { return m_FieldObject; }
    void SetFieldObject(const Pointer<class NiAVObject*>& value) { m_FieldObject = value; }

    const float& GetMagnitude() const { return m_Magnitude; }
    float& GetMagnitude() { return m_Magnitude; }
    void SetMagnitude(const float& value) { m_Magnitude = value; }

    const float& GetAttenuation() const { return m_Attenuation; }
    float& GetAttenuation() { return m_Attenuation; }
    void SetAttenuation(const float& value) { m_Attenuation = value; }

    const bool& GetUseMaxDistance() const { return m_UseMaxDistance; }
    bool& GetUseMaxDistance() { return m_UseMaxDistance; }
    void SetUseMaxDistance(const bool& value) { m_UseMaxDistance = value; }

    const float& GetMaxDistance() const { return m_MaxDistance; }
    float& GetMaxDistance() { return m_MaxDistance; }
    void SetMaxDistance(const float& value) { m_MaxDistance = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
