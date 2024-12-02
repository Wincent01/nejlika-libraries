#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "bhkShape.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Havok collision object that uses multiple shapes?
 *     
 */
class bhkShapeCollection : public bhkShape
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
