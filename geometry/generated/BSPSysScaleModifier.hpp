#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSysModifier.hpp"
namespace nejlika::geometry {


class BSPSysScaleModifier : public NiPSysModifier
{
protected:
    uint m_NumFloats;
    /**
     * Unknown
     */
    std::vector<float> m_Floats;

public:
    const uint& GetNumFloats() const { return m_NumFloats; }
    uint& GetNumFloats() { return m_NumFloats; }
    void SetNumFloats(const uint& value) { m_NumFloats = value; }

    const std::vector<float>& GetFloats() const { return m_Floats; }
    std::vector<float>& GetFloats() { return m_Floats; }
    void SetFloats(const std::vector<float>& value) { m_Floats = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
