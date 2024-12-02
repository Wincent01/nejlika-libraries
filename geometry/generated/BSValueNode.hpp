#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiNode.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-Specific node. Found on fxFire effects
 *         
 */
class BSValueNode : public NiNode
{
protected:
    /**
     * Value
     */
    int m_Value;
    /**
     * Unknown
     */
    byte m_UnknownByte;

public:
    const int& GetValue() const { return m_Value; }
    int& GetValue() { return m_Value; }
    void SetValue(const int& value) { m_Value = value; }

    const byte& GetUnknownByte() const { return m_UnknownByte; }
    byte& GetUnknownByte() { return m_UnknownByte; }
    void SetUnknownByte(const byte& value) { m_UnknownByte = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
