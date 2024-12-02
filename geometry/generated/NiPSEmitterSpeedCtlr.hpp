#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiObject.hpp"
#include "NiTimeController.hpp"
namespace nejlika::geometry {


class NiPSEmitterSpeedCtlr : public NiTimeController
{
protected:
    Pointer<class NiObject*> m_Interpolator;
    int m_Unknown3;

public:
    const Pointer<class NiObject*>& GetInterpolator() const { return m_Interpolator; }
    Pointer<class NiObject*>& GetInterpolator() { return m_Interpolator; }
    void SetInterpolator(const Pointer<class NiObject*>& value) { m_Interpolator = value; }

    const int& GetUnknown3() const { return m_Unknown3; }
    int& GetUnknown3() { return m_Unknown3; }
    void SetUnknown3(const int& value) { m_Unknown3 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
