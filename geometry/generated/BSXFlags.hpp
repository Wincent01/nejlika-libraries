#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiIntegerExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Controls animation and collision.  Integer holds flags:
 *         Bit 0 : enable havok, bAnimated(Skyrim)
 *         Bit 1 : enable collision, bHavok(Skyrim)
 *         Bit 2 : is skeleton nif?, bRagdoll(Skyrim)
 *         Bit 3 : enable animation, bComplex(Skyrim)
 *         Bit 4 : FlameNodes present, bAddon(Skyrim)
 *         Bit 5 : EditorMarkers present
 *         Bit 6 : bDynamic(Skyrim)
 *         Bit 7 : bArticulated(Skyrim)
 *         Bit 8 : bIKTarget(Skyrim)
 *         Bit 9 : Unknown(Skyrim)
 *     
 */
class BSXFlags : public NiIntegerExtraData
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
