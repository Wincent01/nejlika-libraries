#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiInterpolator.hpp"
#include "NiInterpolator.hpp"
#include "NiInterpolator.hpp"
#include "NiInterpolator.hpp"
#include "NiInterpolator.hpp"
#include "NiInterpolator.hpp"
#include "NiInterpolator.hpp"
#include "NiInterpolator.hpp"
#include "NiInterpolator.hpp"
#include "NiFloatInterpController.hpp"
namespace nejlika::geometry {


/**
 * 
 *     Skyrim, Paired with dummy TriShapes, this controller generates lightning shapes for special effects.
 *     First interpolator controls Generation.
 * 		
 */
class BSProceduralLightningController : public NiFloatInterpController
{
protected:
    /**
     * References interpolator for Mutation of strips
     */
    Pointer<class NiInterpolator*> m_Interpolator2Mutation;
    /**
     * Unknown
     */
    Pointer<class NiInterpolator*> m_Interpolator3;
    /**
     * Unknown
     */
    Pointer<class NiInterpolator*> m_Interpolator4;
    /**
     * Unknown
     */
    Pointer<class NiInterpolator*> m_Interpolator5;
    /**
     * Unknown
     */
    Pointer<class NiInterpolator*> m_Interpolator6;
    /**
     * Unknown
     */
    Pointer<class NiInterpolator*> m_Interpolator7;
    /**
     * Unknown
     */
    Pointer<class NiInterpolator*> m_Interpolator8;
    /**
     * References interpolator for Amplitutde control. 0=straight, 50=wide
     */
    Pointer<class NiInterpolator*> m_Interpolator9ArcOffset;
    /**
     * Unknown
     */
    ushort m_UnknownShort1;
    /**
     * Unknown
     */
    ushort m_UnknownShort2;
    /**
     * Unknown
     */
    ushort m_UnknownShort3;
    /**
     * How far lightning will stretch to.
     */
    float m_DistanceWeight;
    /**
     * Unknown
     */
    float m_Float2;
    /**
     * How wide the bolt will be
     */
    float m_StripWidth;
    /**
     * Influences forking behavior
     */
    float m_Fork;
    /**
     * Unknown
     */
    float m_Float5;
    /**
     * Unknown
     */
    byte m_Byte1;
    /**
     * Unknown
     */
    byte m_Byte2;
    /**
     * Unknown
     */
    byte m_Byte3;
    /**
     * Unknown, unsure if this is actually another interpolator link.
     */
    Pointer<class NiInterpolator*> m_Interpolator10;

public:
    const Pointer<class NiInterpolator*>& GetInterpolator2Mutation() const { return m_Interpolator2Mutation; }
    Pointer<class NiInterpolator*>& GetInterpolator2Mutation() { return m_Interpolator2Mutation; }
    void SetInterpolator2Mutation(const Pointer<class NiInterpolator*>& value) { m_Interpolator2Mutation = value; }

    const Pointer<class NiInterpolator*>& GetInterpolator3() const { return m_Interpolator3; }
    Pointer<class NiInterpolator*>& GetInterpolator3() { return m_Interpolator3; }
    void SetInterpolator3(const Pointer<class NiInterpolator*>& value) { m_Interpolator3 = value; }

    const Pointer<class NiInterpolator*>& GetInterpolator4() const { return m_Interpolator4; }
    Pointer<class NiInterpolator*>& GetInterpolator4() { return m_Interpolator4; }
    void SetInterpolator4(const Pointer<class NiInterpolator*>& value) { m_Interpolator4 = value; }

    const Pointer<class NiInterpolator*>& GetInterpolator5() const { return m_Interpolator5; }
    Pointer<class NiInterpolator*>& GetInterpolator5() { return m_Interpolator5; }
    void SetInterpolator5(const Pointer<class NiInterpolator*>& value) { m_Interpolator5 = value; }

    const Pointer<class NiInterpolator*>& GetInterpolator6() const { return m_Interpolator6; }
    Pointer<class NiInterpolator*>& GetInterpolator6() { return m_Interpolator6; }
    void SetInterpolator6(const Pointer<class NiInterpolator*>& value) { m_Interpolator6 = value; }

    const Pointer<class NiInterpolator*>& GetInterpolator7() const { return m_Interpolator7; }
    Pointer<class NiInterpolator*>& GetInterpolator7() { return m_Interpolator7; }
    void SetInterpolator7(const Pointer<class NiInterpolator*>& value) { m_Interpolator7 = value; }

    const Pointer<class NiInterpolator*>& GetInterpolator8() const { return m_Interpolator8; }
    Pointer<class NiInterpolator*>& GetInterpolator8() { return m_Interpolator8; }
    void SetInterpolator8(const Pointer<class NiInterpolator*>& value) { m_Interpolator8 = value; }

    const Pointer<class NiInterpolator*>& GetInterpolator9ArcOffset() const { return m_Interpolator9ArcOffset; }
    Pointer<class NiInterpolator*>& GetInterpolator9ArcOffset() { return m_Interpolator9ArcOffset; }
    void SetInterpolator9ArcOffset(const Pointer<class NiInterpolator*>& value) { m_Interpolator9ArcOffset = value; }

    const ushort& GetUnknownShort1() const { return m_UnknownShort1; }
    ushort& GetUnknownShort1() { return m_UnknownShort1; }
    void SetUnknownShort1(const ushort& value) { m_UnknownShort1 = value; }

    const ushort& GetUnknownShort2() const { return m_UnknownShort2; }
    ushort& GetUnknownShort2() { return m_UnknownShort2; }
    void SetUnknownShort2(const ushort& value) { m_UnknownShort2 = value; }

    const ushort& GetUnknownShort3() const { return m_UnknownShort3; }
    ushort& GetUnknownShort3() { return m_UnknownShort3; }
    void SetUnknownShort3(const ushort& value) { m_UnknownShort3 = value; }

    const float& GetDistanceWeight() const { return m_DistanceWeight; }
    float& GetDistanceWeight() { return m_DistanceWeight; }
    void SetDistanceWeight(const float& value) { m_DistanceWeight = value; }

    const float& GetFloat2() const { return m_Float2; }
    float& GetFloat2() { return m_Float2; }
    void SetFloat2(const float& value) { m_Float2 = value; }

    const float& GetStripWidth() const { return m_StripWidth; }
    float& GetStripWidth() { return m_StripWidth; }
    void SetStripWidth(const float& value) { m_StripWidth = value; }

    const float& GetFork() const { return m_Fork; }
    float& GetFork() { return m_Fork; }
    void SetFork(const float& value) { m_Fork = value; }

    const float& GetFloat5() const { return m_Float5; }
    float& GetFloat5() { return m_Float5; }
    void SetFloat5(const float& value) { m_Float5 = value; }

    const byte& GetByte1() const { return m_Byte1; }
    byte& GetByte1() { return m_Byte1; }
    void SetByte1(const byte& value) { m_Byte1 = value; }

    const byte& GetByte2() const { return m_Byte2; }
    byte& GetByte2() { return m_Byte2; }
    void SetByte2(const byte& value) { m_Byte2 = value; }

    const byte& GetByte3() const { return m_Byte3; }
    byte& GetByte3() { return m_Byte3; }
    void SetByte3(const byte& value) { m_Byte3 = value; }

    const Pointer<class NiInterpolator*>& GetInterpolator10() const { return m_Interpolator10; }
    Pointer<class NiInterpolator*>& GetInterpolator10() { return m_Interpolator10; }
    void SetInterpolator10(const Pointer<class NiInterpolator*>& value) { m_Interpolator10 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
