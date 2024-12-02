#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiParticleModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown.
 *         
 */
class NiPlanarCollider : public NiParticleModifier
{
protected:
    /**
     * Usually 0?
     */
    ushort m_UnknownShort;
    /**
     * Unknown.
     */
    float m_UnknownFloat1;
    /**
     * Unknown.
     */
    float m_UnknownFloat2;
    /**
     * Unknown.
     */
    ushort m_UnknownShort2;
    /**
     * Unknown.
     */
    float m_UnknownFloat3;
    /**
     * Unknown.
     */
    float m_UnknownFloat4;
    /**
     * Unknown.
     */
    float m_UnknownFloat5;
    /**
     * Unknown.
     */
    float m_UnknownFloat6;
    /**
     * Unknown.
     */
    float m_UnknownFloat7;
    /**
     * Unknown.
     */
    float m_UnknownFloat8;
    /**
     * Unknown.
     */
    float m_UnknownFloat9;
    /**
     * Unknown.
     */
    float m_UnknownFloat10;
    /**
     * Unknown.
     */
    float m_UnknownFloat11;
    /**
     * Unknown.
     */
    float m_UnknownFloat12;
    /**
     * Unknown.
     */
    float m_UnknownFloat13;
    /**
     * Unknown.
     */
    float m_UnknownFloat14;
    /**
     * Unknown.
     */
    float m_UnknownFloat15;
    /**
     * Unknown.
     */
    float m_UnknownFloat16;

public:
    const ushort& GetUnknownShort() const { return m_UnknownShort; }
    ushort& GetUnknownShort() { return m_UnknownShort; }
    void SetUnknownShort(const ushort& value) { m_UnknownShort = value; }

    const float& GetUnknownFloat1() const { return m_UnknownFloat1; }
    float& GetUnknownFloat1() { return m_UnknownFloat1; }
    void SetUnknownFloat1(const float& value) { m_UnknownFloat1 = value; }

    const float& GetUnknownFloat2() const { return m_UnknownFloat2; }
    float& GetUnknownFloat2() { return m_UnknownFloat2; }
    void SetUnknownFloat2(const float& value) { m_UnknownFloat2 = value; }

    const ushort& GetUnknownShort2() const { return m_UnknownShort2; }
    ushort& GetUnknownShort2() { return m_UnknownShort2; }
    void SetUnknownShort2(const ushort& value) { m_UnknownShort2 = value; }

    const float& GetUnknownFloat3() const { return m_UnknownFloat3; }
    float& GetUnknownFloat3() { return m_UnknownFloat3; }
    void SetUnknownFloat3(const float& value) { m_UnknownFloat3 = value; }

    const float& GetUnknownFloat4() const { return m_UnknownFloat4; }
    float& GetUnknownFloat4() { return m_UnknownFloat4; }
    void SetUnknownFloat4(const float& value) { m_UnknownFloat4 = value; }

    const float& GetUnknownFloat5() const { return m_UnknownFloat5; }
    float& GetUnknownFloat5() { return m_UnknownFloat5; }
    void SetUnknownFloat5(const float& value) { m_UnknownFloat5 = value; }

    const float& GetUnknownFloat6() const { return m_UnknownFloat6; }
    float& GetUnknownFloat6() { return m_UnknownFloat6; }
    void SetUnknownFloat6(const float& value) { m_UnknownFloat6 = value; }

    const float& GetUnknownFloat7() const { return m_UnknownFloat7; }
    float& GetUnknownFloat7() { return m_UnknownFloat7; }
    void SetUnknownFloat7(const float& value) { m_UnknownFloat7 = value; }

    const float& GetUnknownFloat8() const { return m_UnknownFloat8; }
    float& GetUnknownFloat8() { return m_UnknownFloat8; }
    void SetUnknownFloat8(const float& value) { m_UnknownFloat8 = value; }

    const float& GetUnknownFloat9() const { return m_UnknownFloat9; }
    float& GetUnknownFloat9() { return m_UnknownFloat9; }
    void SetUnknownFloat9(const float& value) { m_UnknownFloat9 = value; }

    const float& GetUnknownFloat10() const { return m_UnknownFloat10; }
    float& GetUnknownFloat10() { return m_UnknownFloat10; }
    void SetUnknownFloat10(const float& value) { m_UnknownFloat10 = value; }

    const float& GetUnknownFloat11() const { return m_UnknownFloat11; }
    float& GetUnknownFloat11() { return m_UnknownFloat11; }
    void SetUnknownFloat11(const float& value) { m_UnknownFloat11 = value; }

    const float& GetUnknownFloat12() const { return m_UnknownFloat12; }
    float& GetUnknownFloat12() { return m_UnknownFloat12; }
    void SetUnknownFloat12(const float& value) { m_UnknownFloat12 = value; }

    const float& GetUnknownFloat13() const { return m_UnknownFloat13; }
    float& GetUnknownFloat13() { return m_UnknownFloat13; }
    void SetUnknownFloat13(const float& value) { m_UnknownFloat13 = value; }

    const float& GetUnknownFloat14() const { return m_UnknownFloat14; }
    float& GetUnknownFloat14() { return m_UnknownFloat14; }
    void SetUnknownFloat14(const float& value) { m_UnknownFloat14 = value; }

    const float& GetUnknownFloat15() const { return m_UnknownFloat15; }
    float& GetUnknownFloat15() { return m_UnknownFloat15; }
    void SetUnknownFloat15(const float& value) { m_UnknownFloat15 = value; }

    const float& GetUnknownFloat16() const { return m_UnknownFloat16; }
    float& GetUnknownFloat16() { return m_UnknownFloat16; }
    void SetUnknownFloat16(const float& value) { m_UnknownFloat16 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
