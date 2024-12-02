#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiTextKeyExtraData.hpp"
#include "CycleType.hpp"
#include "NiControllerManager.hpp"
#include "string.hpp"
#include "NiStringPalette.hpp"
#include "BSAnimNotes.hpp"
#include "NiSequence.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Root node in .kf files (version 10.0.1.0 and up).
 *         
 */
class NiControllerSequence : public NiSequence
{
protected:
    /**
     * Weight/priority of animation?
     */
    float m_Weight;
    /**
     * Link to NiTextKeyExtraData. Replaces the other Text Keys field in versions 10.1.0.106 and up.
     */
    Pointer<class NiTextKeyExtraData*> m_TextKeys;
    /**
     * Anim cycle type? Is part of "Flags" in other objects?
     */
    CycleType m_CycleType;
    /**
     * Unknown.
     */
    uint m_UnknownInt0;
    /**
     * The animation frequency.
     */
    float m_Frequency;
    /**
     * The controller sequence start time?
     */
    float m_StartTime;
    /**
     * Unknown.
     */
    float m_UnknownFloat2;
    /**
     * The controller sequence stop time?
     */
    float m_StopTime;
    /**
     * Unknown.
     */
    byte m_UnknownByte;
    /**
     * Refers to NiControllerManager which references this object, if any.
     */
    Pointer<class NiControllerManager*> m_Manager;
    /**
     * Name of target node Controller acts on.
     */
    string m_TargetName;
    /**
     * Refers to NiStringPalette.
     */
    Pointer<class NiStringPalette*> m_StringPalette;
    /**
     * Unknown
     */
    Pointer<class BSAnimNotes*> m_AnimNotes;
    /**
     * Unknown
     */
    short m_UnknownShort1;
    /**
     * Unknown, found in some Lazeska and Krazy Rain .KFs (seems to be 64 when present).
     */
    uint m_UnknownInt3;

public:
    const float& GetWeight() const { return m_Weight; }
    float& GetWeight() { return m_Weight; }
    void SetWeight(const float& value) { m_Weight = value; }

    const Pointer<class NiTextKeyExtraData*>& GetTextKeys() const { return m_TextKeys; }
    Pointer<class NiTextKeyExtraData*>& GetTextKeys() { return m_TextKeys; }
    void SetTextKeys(const Pointer<class NiTextKeyExtraData*>& value) { m_TextKeys = value; }

    const CycleType& GetCycleType() const { return m_CycleType; }
    CycleType& GetCycleType() { return m_CycleType; }
    void SetCycleType(const CycleType& value) { m_CycleType = value; }

    const uint& GetUnknownInt0() const { return m_UnknownInt0; }
    uint& GetUnknownInt0() { return m_UnknownInt0; }
    void SetUnknownInt0(const uint& value) { m_UnknownInt0 = value; }

    const float& GetFrequency() const { return m_Frequency; }
    float& GetFrequency() { return m_Frequency; }
    void SetFrequency(const float& value) { m_Frequency = value; }

    const float& GetStartTime() const { return m_StartTime; }
    float& GetStartTime() { return m_StartTime; }
    void SetStartTime(const float& value) { m_StartTime = value; }

    const float& GetUnknownFloat2() const { return m_UnknownFloat2; }
    float& GetUnknownFloat2() { return m_UnknownFloat2; }
    void SetUnknownFloat2(const float& value) { m_UnknownFloat2 = value; }

    const float& GetStopTime() const { return m_StopTime; }
    float& GetStopTime() { return m_StopTime; }
    void SetStopTime(const float& value) { m_StopTime = value; }

    const byte& GetUnknownByte() const { return m_UnknownByte; }
    byte& GetUnknownByte() { return m_UnknownByte; }
    void SetUnknownByte(const byte& value) { m_UnknownByte = value; }

    const Pointer<class NiControllerManager*>& GetManager() const { return m_Manager; }
    Pointer<class NiControllerManager*>& GetManager() { return m_Manager; }
    void SetManager(const Pointer<class NiControllerManager*>& value) { m_Manager = value; }

    const string& GetTargetName() const { return m_TargetName; }
    string& GetTargetName() { return m_TargetName; }
    void SetTargetName(const string& value) { m_TargetName = value; }

    const Pointer<class NiStringPalette*>& GetStringPalette() const { return m_StringPalette; }
    Pointer<class NiStringPalette*>& GetStringPalette() { return m_StringPalette; }
    void SetStringPalette(const Pointer<class NiStringPalette*>& value) { m_StringPalette = value; }

    const Pointer<class BSAnimNotes*>& GetAnimNotes() const { return m_AnimNotes; }
    Pointer<class BSAnimNotes*>& GetAnimNotes() { return m_AnimNotes; }
    void SetAnimNotes(const Pointer<class BSAnimNotes*>& value) { m_AnimNotes = value; }

    const short& GetUnknownShort1() const { return m_UnknownShort1; }
    short& GetUnknownShort1() { return m_UnknownShort1; }
    void SetUnknownShort1(const short& value) { m_UnknownShort1 = value; }

    const uint& GetUnknownInt3() const { return m_UnknownInt3; }
    uint& GetUnknownInt3() { return m_UnknownInt3; }
    void SetUnknownInt3(const uint& value) { m_UnknownInt3 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
