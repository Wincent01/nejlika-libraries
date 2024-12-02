#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "bhkPhantom.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A Havok phantom that uses a Havok shape object for its collision volume instead of just a bounding box.
 *     
 */
class bhkShapePhantom : public bhkPhantom
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
