#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "SizedString.hpp"
#include "SizedString.hpp"
#include "Animation.hpp"
#include "EndianType.hpp"

namespace nejlika::geometry {


class Kfm : public Construct
{
protected:
    HeaderString m_HeaderString;
    EndianType m_EndianType;
    SizedString m_NIFFileName;
    SizedString m_Master;
    int m_UnknownInt1;
    int m_UnknownInt2;
    float m_UnknownFloat1;
    float m_UnknownFloat2;
    int m_NumAnimations;
    std::vector<Animation> m_Animations;
    int m_UnknownInt3;

public:
    const HeaderString& GetHeaderString() const { return m_HeaderString; }
    HeaderString& GetHeaderString() { return m_HeaderString; }
    void SetHeaderString(const HeaderString& value) { m_HeaderString = value; }

    const EndianType& GetEndianType() const { return m_EndianType; }
    EndianType& GetEndianType() { return m_EndianType; }
    void SetEndianType(const EndianType& value) { m_EndianType = value; }

    const SizedString& GetNIFFileName() const { return m_NIFFileName; }
    SizedString& GetNIFFileName() { return m_NIFFileName; }
    void SetNIFFileName(const SizedString& value) { m_NIFFileName = value; }

    const SizedString& GetMaster() const { return m_Master; }
    SizedString& GetMaster() { return m_Master; }
    void SetMaster(const SizedString& value) { m_Master = value; }

    const int& GetUnknownInt1() const { return m_UnknownInt1; }
    int& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const int& value) { m_UnknownInt1 = value; }

    const int& GetUnknownInt2() const { return m_UnknownInt2; }
    int& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const int& value) { m_UnknownInt2 = value; }

    const float& GetUnknownFloat1() const { return m_UnknownFloat1; }
    float& GetUnknownFloat1() { return m_UnknownFloat1; }
    void SetUnknownFloat1(const float& value) { m_UnknownFloat1 = value; }

    const float& GetUnknownFloat2() const { return m_UnknownFloat2; }
    float& GetUnknownFloat2() { return m_UnknownFloat2; }
    void SetUnknownFloat2(const float& value) { m_UnknownFloat2 = value; }

    const int& GetNumAnimations() const { return m_NumAnimations; }
    int& GetNumAnimations() { return m_NumAnimations; }
    void SetNumAnimations(const int& value) { m_NumAnimations = value; }

    const std::vector<Animation>& GetAnimations() const { return m_Animations; }
    std::vector<Animation>& GetAnimations() { return m_Animations; }
    void SetAnimations(const std::vector<Animation>& value) { m_Animations = value; }

    const int& GetUnknownInt3() const { return m_UnknownInt3; }
    int& GetUnknownInt3() { return m_UnknownInt3; }
    void SetUnknownInt3(const int& value) { m_UnknownInt3 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
