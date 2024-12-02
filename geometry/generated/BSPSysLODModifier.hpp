#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSysModifier.hpp"
namespace nejlika::geometry {


class BSPSysLODModifier : public NiPSysModifier
{
protected:
    /**
     * Unknown
     */
    float m_UknownFloat1;
    /**
     * Unknown
     */
    float m_UknownFloat2;
    /**
     * Unknown
     */
    float m_UknownFloat3;
    /**
     * Unknown
     */
    float m_UknownFloat4;

public:
    const float& GetUknownFloat1() const { return m_UknownFloat1; }
    float& GetUknownFloat1() { return m_UknownFloat1; }
    void SetUknownFloat1(const float& value) { m_UknownFloat1 = value; }

    const float& GetUknownFloat2() const { return m_UknownFloat2; }
    float& GetUknownFloat2() { return m_UknownFloat2; }
    void SetUknownFloat2(const float& value) { m_UknownFloat2 = value; }

    const float& GetUknownFloat3() const { return m_UknownFloat3; }
    float& GetUknownFloat3() { return m_UknownFloat3; }
    void SetUknownFloat3(const float& value) { m_UknownFloat3 = value; }

    const float& GetUknownFloat4() const { return m_UknownFloat4; }
    float& GetUknownFloat4() { return m_UknownFloat4; }
    void SetUknownFloat4(const float& value) { m_UknownFloat4 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
