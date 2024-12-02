#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "IntermediateAnim.hpp"
namespace nejlika::geometry {


class Transition : public Construct
{
protected:
    /**
     * Refers to another animation
     */
    int m_Animation;
    int m_Type;
    float m_Duration;
    int m_NumIntermediateAnims;
    std::vector<IntermediateAnim> m_IntermediateAnims;
    int m_NumTextKeyPairs;

public:
    const int& GetAnimation() const { return m_Animation; }
    int& GetAnimation() { return m_Animation; }
    void SetAnimation(const int& value) { m_Animation = value; }

    const int& GetType() const { return m_Type; }
    int& GetType() { return m_Type; }
    void SetType(const int& value) { m_Type = value; }

    const float& GetDuration() const { return m_Duration; }
    float& GetDuration() { return m_Duration; }
    void SetDuration(const float& value) { m_Duration = value; }

    const int& GetNumIntermediateAnims() const { return m_NumIntermediateAnims; }
    int& GetNumIntermediateAnims() { return m_NumIntermediateAnims; }
    void SetNumIntermediateAnims(const int& value) { m_NumIntermediateAnims = value; }

    const std::vector<IntermediateAnim>& GetIntermediateAnims() const { return m_IntermediateAnims; }
    std::vector<IntermediateAnim>& GetIntermediateAnims() { return m_IntermediateAnims; }
    void SetIntermediateAnims(const std::vector<IntermediateAnim>& value) { m_IntermediateAnims = value; }

    const int& GetNumTextKeyPairs() const { return m_NumTextKeyPairs; }
    int& GetNumTextKeyPairs() { return m_NumTextKeyPairs; }
    void SetNumTextKeyPairs(const int& value) { m_NumTextKeyPairs = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
