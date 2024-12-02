#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "bhkWorldObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Havok object that do not react with other objects when they collide (causing deflection, etc.) but still trigger collision notifications to the game.  Possible uses are traps, portals, AI fields, etc.
 *     
 */
class bhkPhantom : public bhkWorldObject
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
