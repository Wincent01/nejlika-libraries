#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "BSFurnitureMarker.hpp"
namespace nejlika::geometry {


/**
 * 
 *     Furniture Marker for actors
 *     
 */
class BSFurnitureMarkerNode : public BSFurnitureMarker
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
