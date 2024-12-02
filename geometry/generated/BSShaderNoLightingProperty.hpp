#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "SizedString.hpp"
#include "BSShaderLightingProperty.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-specific property.
 *         
 */
class BSShaderNoLightingProperty : public BSShaderLightingProperty
{
protected:
    /**
     * The texture glow map.
     */
    SizedString m_FileName;
    /**
     * Unknown
     */
    float m_UnknownFloat2;
    /**
     * 
     *             Normally what appears to be a junk value (0xB33BBD2E). Appears to be related to glow when Unk Flags is (0x82000148).
     *         
     */
    float m_UnknownFloat3;
    /**
     * Unknown
     */
    float m_UnknownFloat4;
    /**
     * Unknown
     */
    float m_UnknownFloat5;

public:
    const SizedString& GetFileName() const { return m_FileName; }
    SizedString& GetFileName() { return m_FileName; }
    void SetFileName(const SizedString& value) { m_FileName = value; }

    const float& GetUnknownFloat2() const { return m_UnknownFloat2; }
    float& GetUnknownFloat2() { return m_UnknownFloat2; }
    void SetUnknownFloat2(const float& value) { m_UnknownFloat2 = value; }

    const float& GetUnknownFloat3() const { return m_UnknownFloat3; }
    float& GetUnknownFloat3() { return m_UnknownFloat3; }
    void SetUnknownFloat3(const float& value) { m_UnknownFloat3 = value; }

    const float& GetUnknownFloat4() const { return m_UnknownFloat4; }
    float& GetUnknownFloat4() { return m_UnknownFloat4; }
    void SetUnknownFloat4(const float& value) { m_UnknownFloat4 = value; }

    const float& GetUnknownFloat5() const { return m_UnknownFloat5; }
    float& GetUnknownFloat5() { return m_UnknownFloat5; }
    void SetUnknownFloat5(const float& value) { m_UnknownFloat5 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
