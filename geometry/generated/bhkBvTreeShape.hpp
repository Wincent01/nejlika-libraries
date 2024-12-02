#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "bhkShape.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A tree-like Havok data structure stored in an assembly-like binary code?
 *     
 */
class bhkBvTreeShape : public bhkShape
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
