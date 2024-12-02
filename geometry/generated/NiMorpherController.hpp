#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiMorphData.hpp"
#include "NiInterpController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown! Used by Daoc.
 *         
 */
class NiMorpherController : public NiInterpController
{
protected:
    /**
     * This controller's data.
     */
    Pointer<class NiMorphData*> m_Data;

public:
    const Pointer<class NiMorphData*>& GetData() const { return m_Data; }
    Pointer<class NiMorphData*>& GetData() { return m_Data; }
    void SetData(const Pointer<class NiMorphData*>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
