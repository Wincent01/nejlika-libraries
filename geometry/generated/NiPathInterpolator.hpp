#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPosData.hpp"
#include "NiFloatData.hpp"
#include "NiKeyBasedInterpolator.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown interpolator.
 *         
 */
class NiPathInterpolator : public NiKeyBasedInterpolator
{
protected:
    /**
     * Unknown.
     */
    ushort m_UnknownShort;
    /**
     * Unknown.
     */
    uint m_UnknownInt;
    /**
     * Unknown.
     */
    float m_UnknownFloat1;
    /**
     * Unknown.
     */
    float m_UnknownFloat2;
    /**
     * Unknown. Zero.
     */
    ushort m_UnknownShort2;
    /**
     * Links to NiPosData.
     */
    Pointer<class NiPosData*> m_PosData;
    /**
     * Links to NiFloatData.
     */
    Pointer<class NiFloatData*> m_FloatData;

public:
    const ushort& GetUnknownShort() const { return m_UnknownShort; }
    ushort& GetUnknownShort() { return m_UnknownShort; }
    void SetUnknownShort(const ushort& value) { m_UnknownShort = value; }

    const uint& GetUnknownInt() const { return m_UnknownInt; }
    uint& GetUnknownInt() { return m_UnknownInt; }
    void SetUnknownInt(const uint& value) { m_UnknownInt = value; }

    const float& GetUnknownFloat1() const { return m_UnknownFloat1; }
    float& GetUnknownFloat1() { return m_UnknownFloat1; }
    void SetUnknownFloat1(const float& value) { m_UnknownFloat1 = value; }

    const float& GetUnknownFloat2() const { return m_UnknownFloat2; }
    float& GetUnknownFloat2() { return m_UnknownFloat2; }
    void SetUnknownFloat2(const float& value) { m_UnknownFloat2 = value; }

    const ushort& GetUnknownShort2() const { return m_UnknownShort2; }
    ushort& GetUnknownShort2() { return m_UnknownShort2; }
    void SetUnknownShort2(const ushort& value) { m_UnknownShort2 = value; }

    const Pointer<class NiPosData*>& GetPosData() const { return m_PosData; }
    Pointer<class NiPosData*>& GetPosData() { return m_PosData; }
    void SetPosData(const Pointer<class NiPosData*>& value) { m_PosData = value; }

    const Pointer<class NiFloatData*>& GetFloatData() const { return m_FloatData; }
    Pointer<class NiFloatData*>& GetFloatData() { return m_FloatData; }
    void SetFloatData(const Pointer<class NiFloatData*>& value) { m_FloatData = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
