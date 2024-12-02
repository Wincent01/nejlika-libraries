#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiTimeController.hpp"
namespace nejlika::geometry {


class NiPSGravityStrengthCtlr : public NiTimeController
{
protected:
    int m_Unknown2;
    int m_Unknown3;

public:
    const int& GetUnknown2() const { return m_Unknown2; }
    int& GetUnknown2() { return m_Unknown2; }
    void SetUnknown2(const int& value) { m_Unknown2 = value; }

    const int& GetUnknown3() const { return m_Unknown3; }
    int& GetUnknown3() { return m_Unknown3; }
    void SetUnknown3(const int& value) { m_Unknown3 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
