#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiFloatData.hpp"
#include "NiPSysModifierCtlr.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A particle system modifier controller that deals with floating point data?
 *         
 */
class NiPSysModifierFloatCtlr : public NiPSysModifierCtlr
{
protected:
    /**
     * This controller's data.
     */
    Pointer<class NiFloatData*> m_Data;

public:
    const Pointer<class NiFloatData*>& GetData() const { return m_Data; }
    Pointer<class NiFloatData*>& GetData() { return m_Data; }
    void SetData(const Pointer<class NiFloatData*>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
