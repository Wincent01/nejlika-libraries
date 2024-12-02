#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPosData.hpp"
#include "NiFloatData.hpp"
#include "NiTimeController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Time controller for a path.
 *         
 */
class NiPathController : public NiTimeController
{
protected:
    /**
     * Unknown.
     */
    ushort m_UnknownShort2;
    /**
     * Unknown, always 1?
     */
    uint m_UnknownInt1;
    /**
     * Unknown, often 0?
     */
    float m_UnknownFloat2;
    /**
     * Unknown, often 0?
     */
    float m_UnknownFloat3;
    /**
     * Unknown, always 0?
     */
    ushort m_UnknownShort;
    /**
     * Path controller data index (position data). ?
     */
    Pointer<class NiPosData*> m_PosData;
    /**
     * Path controller data index (float data). ?
     */
    Pointer<class NiFloatData*> m_FloatData;

public:
    const ushort& GetUnknownShort2() const { return m_UnknownShort2; }
    ushort& GetUnknownShort2() { return m_UnknownShort2; }
    void SetUnknownShort2(const ushort& value) { m_UnknownShort2 = value; }

    const uint& GetUnknownInt1() const { return m_UnknownInt1; }
    uint& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const uint& value) { m_UnknownInt1 = value; }

    const float& GetUnknownFloat2() const { return m_UnknownFloat2; }
    float& GetUnknownFloat2() { return m_UnknownFloat2; }
    void SetUnknownFloat2(const float& value) { m_UnknownFloat2 = value; }

    const float& GetUnknownFloat3() const { return m_UnknownFloat3; }
    float& GetUnknownFloat3() { return m_UnknownFloat3; }
    void SetUnknownFloat3(const float& value) { m_UnknownFloat3 = value; }

    const ushort& GetUnknownShort() const { return m_UnknownShort; }
    ushort& GetUnknownShort() { return m_UnknownShort; }
    void SetUnknownShort(const ushort& value) { m_UnknownShort = value; }

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
