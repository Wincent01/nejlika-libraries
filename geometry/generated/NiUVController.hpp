#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiUVData.hpp"
#include "NiTimeController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Time controller for texture coordinates.
 *         
 */
class NiUVController : public NiTimeController
{
protected:
    /**
     * Always 0?
     */
    ushort m_UnknownShort;
    /**
     * Texture coordinate controller data index.
     */
    Pointer<class NiUVData*> m_Data;

public:
    const ushort& GetUnknownShort() const { return m_UnknownShort; }
    ushort& GetUnknownShort() { return m_UnknownShort; }
    void SetUnknownShort(const ushort& value) { m_UnknownShort = value; }

    const Pointer<class NiUVData*>& GetData() const { return m_Data; }
    Pointer<class NiUVData*>& GetData() { return m_Data; }
    void SetData(const Pointer<class NiUVData*>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
