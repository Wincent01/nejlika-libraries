#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "SizedString.hpp"
#include "NiExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         List of strings; for example, a list of all bone names.
 *         
 */
class NiStringsExtraData : public NiExtraData
{
protected:
    /**
     * Number of strings.
     */
    uint m_NumStrings;
    /**
     * The strings.
     */
    std::vector<SizedString> m_Data;

public:
    const uint& GetNumStrings() const { return m_NumStrings; }
    uint& GetNumStrings() { return m_NumStrings; }
    void SetNumStrings(const uint& value) { m_NumStrings = value; }

    const std::vector<SizedString>& GetData() const { return m_Data; }
    std::vector<SizedString>& GetData() { return m_Data; }
    void SetData(const std::vector<SizedString>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
