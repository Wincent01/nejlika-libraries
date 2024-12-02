#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "BSShaderProperty.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-specific node? Found in Fallout3
 *     
 */
class WaterShaderProperty : public BSShaderProperty
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
