#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiFloatInterpolator.hpp"
#include "NiTimeController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-specific node.
 *         
 */
class BSFrustumFOVController : public NiTimeController
{
protected:
    /**
     * Frustrum field of view animation interpolater and data.
     */
    Pointer<class NiFloatInterpolator*> m_Interpolator;

public:
    const Pointer<class NiFloatInterpolator*>& GetInterpolator() const { return m_Interpolator; }
    Pointer<class NiFloatInterpolator*>& GetInterpolator() { return m_Interpolator; }
    void SetInterpolator(const Pointer<class NiFloatInterpolator*>& value) { m_Interpolator = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
