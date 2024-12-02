#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle Description.
 *         
 */
class ParticleDesc : public Construct
{
protected:
    /**
     * Unknown.
     */
    Vector3 m_Translation;
    /**
     * Unknown.
     */
    std::vector<float> m_UnknownFloats1;
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
    float m_UnknownFloat3;
    /**
     * Unknown.
     */
    int m_UnknownInt1;

public:
    const Vector3& GetTranslation() const { return m_Translation; }
    Vector3& GetTranslation() { return m_Translation; }
    void SetTranslation(const Vector3& value) { m_Translation = value; }

    const std::vector<float>& GetUnknownFloats1() const { return m_UnknownFloats1; }
    std::vector<float>& GetUnknownFloats1() { return m_UnknownFloats1; }
    void SetUnknownFloats1(const std::vector<float>& value) { m_UnknownFloats1 = value; }

    const float& GetUnknownFloat1() const { return m_UnknownFloat1; }
    float& GetUnknownFloat1() { return m_UnknownFloat1; }
    void SetUnknownFloat1(const float& value) { m_UnknownFloat1 = value; }

    const float& GetUnknownFloat2() const { return m_UnknownFloat2; }
    float& GetUnknownFloat2() { return m_UnknownFloat2; }
    void SetUnknownFloat2(const float& value) { m_UnknownFloat2 = value; }

    const float& GetUnknownFloat3() const { return m_UnknownFloat3; }
    float& GetUnknownFloat3() { return m_UnknownFloat3; }
    void SetUnknownFloat3(const float& value) { m_UnknownFloat3 = value; }

    const int& GetUnknownInt1() const { return m_UnknownInt1; }
    int& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const int& value) { m_UnknownInt1 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
