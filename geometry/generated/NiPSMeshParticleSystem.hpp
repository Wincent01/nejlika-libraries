#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSParticleSystem.hpp"
namespace nejlika::geometry {


class NiPSMeshParticleSystem : public NiPSParticleSystem
{
protected:
    int m_Unknown23;
    /**
     * Unknown - may or may not be emitted mesh?
     */
    int m_Unknown24;
    int m_Unknown25;
    byte m_Unknown26;

public:
    const int& GetUnknown23() const { return m_Unknown23; }
    int& GetUnknown23() { return m_Unknown23; }
    void SetUnknown23(const int& value) { m_Unknown23 = value; }

    const int& GetUnknown24() const { return m_Unknown24; }
    int& GetUnknown24() { return m_Unknown24; }
    void SetUnknown24(const int& value) { m_Unknown24 = value; }

    const int& GetUnknown25() const { return m_Unknown25; }
    int& GetUnknown25() { return m_Unknown25; }
    void SetUnknown25(const int& value) { m_Unknown25 = value; }

    const byte& GetUnknown26() const { return m_Unknown26; }
    byte& GetUnknown26() { return m_Unknown26; }
    void SetUnknown26(const byte& value) { m_Unknown26 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
