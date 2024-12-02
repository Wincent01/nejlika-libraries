#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Integers data.
 *         
 */
class NiIntegersExtraData : public NiExtraData
{
protected:
    /**
     * Number of integers.
     */
    uint m_NumIntegers;
    /**
     * Integers.
     */
    std::vector<uint> m_Data;

public:
    const uint& GetNumIntegers() const { return m_NumIntegers; }
    uint& GetNumIntegers() { return m_NumIntegers; }
    void SetNumIntegers(const uint& value) { m_NumIntegers = value; }

    const std::vector<uint>& GetData() const { return m_Data; }
    std::vector<uint>& GetData() { return m_Data; }
    void SetData(const std::vector<uint>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
