#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown.
 *         
 */
class NiFloatsExtraData : public NiExtraData
{
protected:
    /**
     * Number of floats in the next field.
     */
    uint m_NumFloats;
    /**
     * Float data.
     */
    std::vector<float> m_Data;

public:
    const uint& GetNumFloats() const { return m_NumFloats; }
    uint& GetNumFloats() { return m_NumFloats; }
    void SetNumFloats(const uint& value) { m_NumFloats = value; }

    const std::vector<float>& GetData() const { return m_Data; }
    std::vector<float>& GetData() { return m_Data; }
    void SetData(const std::vector<float>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
