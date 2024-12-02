#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Abstract base class for a single step in the particle system simulation process.  It has no seralized data.
 *     
 */
class NiPSSimulatorStep : public NiObject
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
