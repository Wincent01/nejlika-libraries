#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiControllerSequence.hpp"
#include "NiDefaultAVObjectPalette.hpp"
#include "NiTimeController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown. Root of all controllers?
 *         
 */
class NiControllerManager : public NiTimeController
{
protected:
    /**
     * Designates whether animation sequences are cumulative?
     */
    bool m_Cumulative;
    /**
     * The number of controller sequence objects.
     */
    uint m_NumControllerSequences;
    /**
     * Refers to a list of NiControllerSequence object.
     */
    std::vector<Pointer<class NiControllerSequence*>> m_ControllerSequences;
    /**
     * Refers to a NiDefaultAVObjectPalette.
     */
    Pointer<class NiDefaultAVObjectPalette*> m_ObjectPalette;

public:
    const bool& GetCumulative() const { return m_Cumulative; }
    bool& GetCumulative() { return m_Cumulative; }
    void SetCumulative(const bool& value) { m_Cumulative = value; }

    const uint& GetNumControllerSequences() const { return m_NumControllerSequences; }
    uint& GetNumControllerSequences() { return m_NumControllerSequences; }
    void SetNumControllerSequences(const uint& value) { m_NumControllerSequences = value; }

    const std::vector<Pointer<class NiControllerSequence*>>& GetControllerSequences() const { return m_ControllerSequences; }
    std::vector<Pointer<class NiControllerSequence*>>& GetControllerSequences() { return m_ControllerSequences; }
    void SetControllerSequences(const std::vector<Pointer<class NiControllerSequence*>>& value) { m_ControllerSequences = value; }

    const Pointer<class NiDefaultAVObjectPalette*>& GetObjectPalette() const { return m_ObjectPalette; }
    Pointer<class NiDefaultAVObjectPalette*>& GetObjectPalette() { return m_ObjectPalette; }
    void SetObjectPalette(const Pointer<class NiDefaultAVObjectPalette*>& value) { m_ObjectPalette = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
