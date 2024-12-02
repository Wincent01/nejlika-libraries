#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiVisData.hpp"
#include "NiBoolInterpController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Time controller for visibility.
 *         
 */
class NiVisController : public NiBoolInterpController
{
protected:
    /**
     * Visibility controller data object index.
     */
    Pointer<class NiVisData*> m_Data;

public:
    const Pointer<class NiVisData*>& GetData() const { return m_Data; }
    Pointer<class NiVisData*>& GetData() { return m_Data; }
    void SetData(const Pointer<class NiVisData*>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
