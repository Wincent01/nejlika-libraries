#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSysModifier.hpp"
#include "NiParticles.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A particle system.
 * 		
 */
class NiParticleSystem : public NiParticles
{
protected:
    /**
     * Unknown
     */
    ushort m_UnknownShort2;
    /**
     * Unknown
     */
    ushort m_UnknownShort3;
    /**
     * Unknown
     */
    uint m_UnknownInt1;
    /**
     * If true, Particles are birthed into world space.  If false, Particles are birthed into object space.
     */
    bool m_WorldSpace;
    /**
     * The number of modifier references.
     */
    uint m_NumModifiers;
    /**
     * The list of particle modifiers.
     */
    std::vector<Pointer<class NiPSysModifier*>> m_Modifiers;

public:
    const ushort& GetUnknownShort2() const { return m_UnknownShort2; }
    ushort& GetUnknownShort2() { return m_UnknownShort2; }
    void SetUnknownShort2(const ushort& value) { m_UnknownShort2 = value; }

    const ushort& GetUnknownShort3() const { return m_UnknownShort3; }
    ushort& GetUnknownShort3() { return m_UnknownShort3; }
    void SetUnknownShort3(const ushort& value) { m_UnknownShort3 = value; }

    const uint& GetUnknownInt1() const { return m_UnknownInt1; }
    uint& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const uint& value) { m_UnknownInt1 = value; }

    const bool& GetWorldSpace() const { return m_WorldSpace; }
    bool& GetWorldSpace() { return m_WorldSpace; }
    void SetWorldSpace(const bool& value) { m_WorldSpace = value; }

    const uint& GetNumModifiers() const { return m_NumModifiers; }
    uint& GetNumModifiers() { return m_NumModifiers; }
    void SetNumModifiers(const uint& value) { m_NumModifiers = value; }

    const std::vector<Pointer<class NiPSysModifier*>>& GetModifiers() const { return m_Modifiers; }
    std::vector<Pointer<class NiPSysModifier*>>& GetModifiers() { return m_Modifiers; }
    void SetModifiers(const std::vector<Pointer<class NiPSysModifier*>>& value) { m_Modifiers = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
