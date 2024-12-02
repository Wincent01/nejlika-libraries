#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiTimeController.hpp"
#include "NiObjectNET.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A generic time controller object.
 *         
 */
class NiTimeController : public NiObject
{
protected:
    /**
     * Index of the next controller.
     */
    Pointer<class NiTimeController*> m_NextController;
    /**
     * 
     *             Controller flags (usually 0x000C). Probably controls loops.
     *             Bit 0 : Anim type, 0=APP_TIME 1=APP_INIT
     *             Bit 1-2 : Cycle type  00=Loop 01=Reverse 10=Loop
     *             Bit 3 : Active
     *             Bit 4 : Play backwards
     *         
     */
    Flags m_Flags;
    /**
     * Frequency (is usually 1.0).
     */
    float m_Frequency;
    /**
     * Phase (usually 0.0).
     */
    float m_Phase;
    /**
     * Controller start time.
     */
    float m_StartTime;
    /**
     * Controller stop time.
     */
    float m_StopTime;
    /**
     * Controller target (object index of the first controllable ancestor of this object).
     */
    Pointer<class NiObjectNET*> m_Target;
    /**
     * Unknown integer.
     */
    uint m_UnknownInteger;

public:
    const Pointer<class NiTimeController*>& GetNextController() const { return m_NextController; }
    Pointer<class NiTimeController*>& GetNextController() { return m_NextController; }
    void SetNextController(const Pointer<class NiTimeController*>& value) { m_NextController = value; }

    const Flags& GetFlags() const { return m_Flags; }
    Flags& GetFlags() { return m_Flags; }
    void SetFlags(const Flags& value) { m_Flags = value; }

    const float& GetFrequency() const { return m_Frequency; }
    float& GetFrequency() { return m_Frequency; }
    void SetFrequency(const float& value) { m_Frequency = value; }

    const float& GetPhase() const { return m_Phase; }
    float& GetPhase() { return m_Phase; }
    void SetPhase(const float& value) { m_Phase = value; }

    const float& GetStartTime() const { return m_StartTime; }
    float& GetStartTime() { return m_StartTime; }
    void SetStartTime(const float& value) { m_StartTime = value; }

    const float& GetStopTime() const { return m_StopTime; }
    float& GetStopTime() { return m_StopTime; }
    void SetStopTime(const float& value) { m_StopTime = value; }

    const Pointer<class NiObjectNET*>& GetTarget() const { return m_Target; }
    Pointer<class NiObjectNET*>& GetTarget() { return m_Target; }
    void SetTarget(const Pointer<class NiObjectNET*>& value) { m_Target = value; }

    const uint& GetUnknownInteger() const { return m_UnknownInteger; }
    uint& GetUnknownInteger() { return m_UnknownInteger; }
    void SetUnknownInteger(const uint& value) { m_UnknownInteger = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
