#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSysEmitter.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Guild 2-Specific node
 *         
 */
class NiPSysTrailEmitter : public NiPSysEmitter
{
protected:
    /**
     * Unknown
     */
    int m_UnknownInt1;
    /**
     * Unknown
     */
    float m_UnknownFloat1;
    /**
     * Unknown
     */
    float m_UnknownFloat2;
    /**
     * Unknown
     */
    float m_UnknownFloat3;
    /**
     * Unknown
     */
    int m_UnknownInt2;
    /**
     * Unknown
     */
    float m_UnknownFloat4;
    /**
     * Unknown
     */
    int m_UnknownInt3;
    /**
     * Unknown
     */
    float m_UnknownFloat5;
    /**
     * Unknown
     */
    int m_UnknownInt4;
    /**
     * Unknown
     */
    float m_UnknownFloat6;
    /**
     * Unknown
     */
    float m_UnknownFloat7;

public:
    const int& GetUnknownInt1() const { return m_UnknownInt1; }
    int& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const int& value) { m_UnknownInt1 = value; }

    const float& GetUnknownFloat1() const { return m_UnknownFloat1; }
    float& GetUnknownFloat1() { return m_UnknownFloat1; }
    void SetUnknownFloat1(const float& value) { m_UnknownFloat1 = value; }

    const float& GetUnknownFloat2() const { return m_UnknownFloat2; }
    float& GetUnknownFloat2() { return m_UnknownFloat2; }
    void SetUnknownFloat2(const float& value) { m_UnknownFloat2 = value; }

    const float& GetUnknownFloat3() const { return m_UnknownFloat3; }
    float& GetUnknownFloat3() { return m_UnknownFloat3; }
    void SetUnknownFloat3(const float& value) { m_UnknownFloat3 = value; }

    const int& GetUnknownInt2() const { return m_UnknownInt2; }
    int& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const int& value) { m_UnknownInt2 = value; }

    const float& GetUnknownFloat4() const { return m_UnknownFloat4; }
    float& GetUnknownFloat4() { return m_UnknownFloat4; }
    void SetUnknownFloat4(const float& value) { m_UnknownFloat4 = value; }

    const int& GetUnknownInt3() const { return m_UnknownInt3; }
    int& GetUnknownInt3() { return m_UnknownInt3; }
    void SetUnknownInt3(const int& value) { m_UnknownInt3 = value; }

    const float& GetUnknownFloat5() const { return m_UnknownFloat5; }
    float& GetUnknownFloat5() { return m_UnknownFloat5; }
    void SetUnknownFloat5(const float& value) { m_UnknownFloat5 = value; }

    const int& GetUnknownInt4() const { return m_UnknownInt4; }
    int& GetUnknownInt4() { return m_UnknownInt4; }
    void SetUnknownInt4(const int& value) { m_UnknownInt4 = value; }

    const float& GetUnknownFloat6() const { return m_UnknownFloat6; }
    float& GetUnknownFloat6() { return m_UnknownFloat6; }
    void SetUnknownFloat6(const float& value) { m_UnknownFloat6 = value; }

    const float& GetUnknownFloat7() const { return m_UnknownFloat7; }
    float& GetUnknownFloat7() { return m_UnknownFloat7; }
    void SetUnknownFloat7(const float& value) { m_UnknownFloat7 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
