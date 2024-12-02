#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiInterpolator.hpp"
#include "NiInterpController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A controller referring to a single interpolator.
 *         
 */
class NiSingleInterpController : public NiInterpController
{
protected:
    /**
     * Link to interpolator.
     */
    Pointer<class NiInterpolator*> m_Interpolator;

public:
    const Pointer<class NiInterpolator*>& GetInterpolator() const { return m_Interpolator; }
    Pointer<class NiInterpolator*>& GetInterpolator() { return m_Interpolator; }
    void SetInterpolator(const Pointer<class NiInterpolator*>& value) { m_Interpolator = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
