#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiNode.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Morrowind-specific node for collision mesh.
 *     
 */
class RootCollisionNode : public NiNode
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
