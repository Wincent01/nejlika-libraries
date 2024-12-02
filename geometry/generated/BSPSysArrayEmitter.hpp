#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSysVolumeEmitter.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle emitter that uses a node, its children and subchildren to emit from.  Emission will be evenly spread along points from nodes leading to their direct parents/children only.
 *     
 */
class BSPSysArrayEmitter : public NiPSysVolumeEmitter
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
