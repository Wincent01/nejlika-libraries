#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "bhkWorldObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A havok node, describes physical properties.
 *     
 */
class bhkEntity : public bhkWorldObject
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}