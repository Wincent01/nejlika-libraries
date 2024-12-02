#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSysEmitterCtlrData.hpp"
#include "NiInterpolator.hpp"
#include "NiPSysModifierCtlr.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle system (multi?) emitter controller.
 *         
 */
class BSPSysMultiTargetEmitterCtlr : public NiPSysModifierCtlr
{
protected:
    /**
     * This controller's data
     */
    Pointer<class NiPSysEmitterCtlrData*> m_Data;
    /**
     * Links to a bool interpolator. Controls emitter's visibility status?
     */
    Pointer<class NiInterpolator*> m_VisibilityInterpolator;
    /**
     * Unknown
     */
    short m_UnknownShort1;
    /**
     * Unknown
     */
    int m_UnknownInt1;

public:
    const Pointer<class NiPSysEmitterCtlrData*>& GetData() const { return m_Data; }
    Pointer<class NiPSysEmitterCtlrData*>& GetData() { return m_Data; }
    void SetData(const Pointer<class NiPSysEmitterCtlrData*>& value) { m_Data = value; }

    const Pointer<class NiInterpolator*>& GetVisibilityInterpolator() const { return m_VisibilityInterpolator; }
    Pointer<class NiInterpolator*>& GetVisibilityInterpolator() { return m_VisibilityInterpolator; }
    void SetVisibilityInterpolator(const Pointer<class NiInterpolator*>& value) { m_VisibilityInterpolator = value; }

    const short& GetUnknownShort1() const { return m_UnknownShort1; }
    short& GetUnknownShort1() { return m_UnknownShort1; }
    void SetUnknownShort1(const short& value) { m_UnknownShort1 = value; }

    const int& GetUnknownInt1() const { return m_UnknownInt1; }
    int& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const int& value) { m_UnknownInt1 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
