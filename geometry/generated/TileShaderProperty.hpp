#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "SizedString.hpp"
#include "BSShaderLightingProperty.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-specific node.
 *         
 */
class TileShaderProperty : public BSShaderLightingProperty
{
protected:
    /**
     * Texture file name
     */
    SizedString m_FileName;

public:
    const SizedString& GetFileName() const { return m_FileName; }
    SizedString& GetFileName() { return m_FileName; }
    void SetFileName(const SizedString& value) { m_FileName = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
