#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "TargetColor.hpp"
#include "NiPosData.hpp"
#include "NiSingleInterpController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A controller that interpolates point 3 data?
 *         
 */
class NiPoint3InterpController : public NiSingleInterpController
{
protected:
    /**
     * Selects which color to control.
     */
    TargetColor m_TargetColor;
    /**
     * Material color controller data object index. Points to NiPosData.
     */
    Pointer<class NiPosData*> m_Data;

public:
    const TargetColor& GetTargetColor() const { return m_TargetColor; }
    TargetColor& GetTargetColor() { return m_TargetColor; }
    void SetTargetColor(const TargetColor& value) { m_TargetColor = value; }

    const Pointer<class NiPosData*>& GetData() const { return m_Data; }
    Pointer<class NiPosData*>& GetData() { return m_Data; }
    void SetData(const Pointer<class NiPosData*>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
