#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSysData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-Specific (mesh?) Particle System Data.
 *         
 */
class BSStripPSysData : public NiPSysData
{
protected:
    /**
     * Unknown
     */
    short m_UnknownShort5;
    /**
     * Unknown
     */
    byte m_UnknownByte6;
    /**
     * Unknown
     */
    int m_UnknownInt7;
    /**
     * Unknown
     */
    float m_UnknownFloat8;

public:
    const short& GetUnknownShort5() const { return m_UnknownShort5; }
    short& GetUnknownShort5() { return m_UnknownShort5; }
    void SetUnknownShort5(const short& value) { m_UnknownShort5 = value; }

    const byte& GetUnknownByte6() const { return m_UnknownByte6; }
    byte& GetUnknownByte6() { return m_UnknownByte6; }
    void SetUnknownByte6(const byte& value) { m_UnknownByte6 = value; }

    const int& GetUnknownInt7() const { return m_UnknownInt7; }
    int& GetUnknownInt7() { return m_UnknownInt7; }
    void SetUnknownInt7(const int& value) { m_UnknownInt7 = value; }

    const float& GetUnknownFloat8() const { return m_UnknownFloat8; }
    float& GetUnknownFloat8() { return m_UnknownFloat8; }
    void SetUnknownFloat8(const float& value) { m_UnknownFloat8 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
