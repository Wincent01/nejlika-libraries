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
class NiSphericalCollider : public NiParticleModifier
{
protected:
    /**
     * Unknown.
     */
    float m_UnknownFloat1;
    /**
     * Unknown.
     */
    ushort m_UnknownShort1;
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

public:
    const float& GetUnknownFloat1() const { return m_UnknownFloat1; }
    float& GetUnknownFloat1() { return m_UnknownFloat1; }
    void SetUnknownFloat1(const float& value) { m_UnknownFloat1 = value; }

    const ushort& GetUnknownShort1() const { return m_UnknownShort1; }
    ushort& GetUnknownShort1() { return m_UnknownShort1; }
    void SetUnknownShort1(const ushort& value) { m_UnknownShort1 = value; }

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


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
