#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiObject.hpp"
namespace nejlika::geometry {


class NiPSBoundUpdater : public NiObject
{
protected:
    byte m_Unknown1;
    byte m_Unknown2;

public:
    const byte& GetUnknown1() const { return m_Unknown1; }
    byte& GetUnknown1() { return m_Unknown1; }
    void SetUnknown1(const byte& value) { m_Unknown1 = value; }

    const byte& GetUnknown2() const { return m_Unknown2; }
    byte& GetUnknown2() { return m_Unknown2; }
    void SetUnknown2(const byte& value) { m_Unknown2 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
