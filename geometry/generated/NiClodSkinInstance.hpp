#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiSkinInstance.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A copy of NISkinInstance for use with NiClod meshes.
 *     
 */
class NiClodSkinInstance : public NiSkinInstance
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
