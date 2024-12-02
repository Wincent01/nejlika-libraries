#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Extra integer data.
 *         
 */
class NiIntegerExtraData : public NiExtraData
{
protected:
    /**
     * The value of the extra data.
     */
    uint m_IntegerData;

public:
    const uint& GetIntegerData() const { return m_IntegerData; }
    uint& GetIntegerData() { return m_IntegerData; }
    void SetIntegerData(const uint& value) { m_IntegerData = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
