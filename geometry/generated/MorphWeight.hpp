#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiInterpolator.hpp"
namespace nejlika::geometry {


class MorphWeight : public Construct
{
protected:
    /**
     * Interpolator
     */
    Pointer<class NiInterpolator*> m_Interpolator;
    /**
     * Weight
     */
    float m_Weight;

public:
    const Pointer<class NiInterpolator*>& GetInterpolator() const { return m_Interpolator; }
    Pointer<class NiInterpolator*>& GetInterpolator() { return m_Interpolator; }
    void SetInterpolator(const Pointer<class NiInterpolator*>& value) { m_Interpolator = value; }

    const float& GetWeight() const { return m_Weight; }
    float& GetWeight() { return m_Weight; }
    void SetWeight(const float& value) { m_Weight = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
