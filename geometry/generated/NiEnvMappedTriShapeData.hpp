#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiTriShapeData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Holds mesh data using a list of singular triangles.
 *     
 */
class NiEnvMappedTriShapeData : public NiTriShapeData
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
