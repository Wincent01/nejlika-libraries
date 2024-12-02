#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "BSMultiBoundData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-specific node.
 *         
 */
class BSMultiBoundSphere : public BSMultiBoundData
{
protected:
    /**
     * Unknown Flag
     */
    int m_UnknownInt1;
    /**
     * Unknown Flag
     */
    int m_UnknownInt2;
    /**
     * Unknown Flag
     */
    int m_UnknownInt3;
    /**
     * Radius
     */
    float m_Radius;

public:
    const int& GetUnknownInt1() const { return m_UnknownInt1; }
    int& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const int& value) { m_UnknownInt1 = value; }

    const int& GetUnknownInt2() const { return m_UnknownInt2; }
    int& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const int& value) { m_UnknownInt2 = value; }

    const int& GetUnknownInt3() const { return m_UnknownInt3; }
    int& GetUnknownInt3() { return m_UnknownInt3; }
    void SetUnknownInt3(const int& value) { m_UnknownInt3 = value; }

    const float& GetRadius() const { return m_Radius; }
    float& GetRadius() { return m_Radius; }
    void SetRadius(const float& value) { m_Radius = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
