#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiMeshModifier.hpp"
namespace nejlika::geometry {


class NiInstancingMeshModifier : public NiMeshModifier
{
protected:

public:

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
