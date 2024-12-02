#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Float extra data.
 *         
 */
class NiFloatExtraData : public NiExtraData
{
protected:
    /**
     * The float data.
     */
    float m_FloatData;

public:
    const float& GetFloatData() const { return m_FloatData; }
    float& GetFloatData() { return m_FloatData; }
    void SetFloatData(const float& value) { m_FloatData = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
