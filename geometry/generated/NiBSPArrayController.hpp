#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiParticleSystemController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A particle system controller, used by BS in conjunction with NiBSParticleNode.
 *     
 */
class NiBSPArrayController : public NiParticleSystemController
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
