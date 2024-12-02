#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiTriShape.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Two dimensional screen elements.
 *     
 */
class NiScreenElements : public NiTriShape
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
