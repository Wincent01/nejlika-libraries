#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "bhkRefObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Havok objects that can be saved and loaded from disk?
 *     
 */
class bhkSerializable : public bhkRefObject
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
