#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiKeyframeController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         NiTransformController replaces the NiKeyframeController.
 *     
 */
class NiTransformController : public NiKeyframeController
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
