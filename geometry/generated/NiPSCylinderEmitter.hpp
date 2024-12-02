#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSSphereEmitter.hpp"
namespace nejlika::geometry {


class NiPSCylinderEmitter : public NiPSSphereEmitter
{
protected:
    float m_Unknown23;

public:
    const float& GetUnknown23() const { return m_Unknown23; }
    float& GetUnknown23() { return m_Unknown23; }
    void SetUnknown23(const float& value) { m_Unknown23 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
