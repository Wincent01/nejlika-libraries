#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiFloatData.hpp"
#include "NiFloatInterpController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Time controller for transparency.
 *         
 */
class NiAlphaController : public NiFloatInterpController
{
protected:
    /**
     * Alpha controller data index.
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
