#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "BSShaderProperty.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-specific property.
 *         
 */
class BSShaderLightingProperty : public BSShaderProperty
{
protected:
    /**
     * Unknown
     */
    int m_UnknownInt3;

public:
    const int& GetUnknownInt3() const { return m_UnknownInt3; }
    int& GetUnknownInt3() { return m_UnknownInt3; }
    void SetUnknownInt3(const int& value) { m_UnknownInt3 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
