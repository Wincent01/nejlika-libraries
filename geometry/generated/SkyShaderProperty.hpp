#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "SizedString.hpp"
#include "BSShaderProperty.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-specific node? Found in Fallout3
 *         
 */
class SkyShaderProperty : public BSShaderProperty
{
protected:
    /**
     * Unknown
     */
    int m_UnknownInt4;
    /**
     * The texture.
     */
    SizedString m_FileName;
    /**
     * Unknown
     */
    int m_UnknownInt5;

public:
    const int& GetUnknownInt4() const { return m_UnknownInt4; }
    int& GetUnknownInt4() { return m_UnknownInt4; }
    void SetUnknownInt4(const int& value) { m_UnknownInt4 = value; }

    const SizedString& GetFileName() const { return m_FileName; }
    SizedString& GetFileName() { return m_FileName; }
    void SetFileName(const SizedString& value) { m_FileName = value; }

    const int& GetUnknownInt5() const { return m_UnknownInt5; }
    int& GetUnknownInt5() { return m_UnknownInt5; }
    void SetUnknownInt5(const int& value) { m_UnknownInt5 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
