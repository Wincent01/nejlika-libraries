#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "TBC.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A generic key with support for interpolation. Type 1 is normal linear interpolation, type 2 has forward and backward tangents, and type 3 has tension, bias and continuity arguments. Note that color4 and byte always seem to be of type 1.
 *         
 */
template <typename TEMPLATE>
class Key : public Construct
{
protected:
    /**
     * Time of the key.
     */
    float m_Time;
    /**
     * The key value.
     */
    TEMPLATE m_Value;
    /**
     * Key forward tangent.
     */
    TEMPLATE m_Forward;
    /**
     * The key backward tangent.
     */
    TEMPLATE m_Backward;
    /**
     * The key's TBC.
     */
    TBC m_TBC;

public:
    const float& GetTime() const { return m_Time; }
    float& GetTime() { return m_Time; }
    void SetTime(const float& value) { m_Time = value; }

    const TEMPLATE& GetValue() const { return m_Value; }
    TEMPLATE& GetValue() { return m_Value; }
    void SetValue(const TEMPLATE& value) { m_Value = value; }

    const TEMPLATE& GetForward() const { return m_Forward; }
    TEMPLATE& GetForward() { return m_Forward; }
    void SetForward(const TEMPLATE& value) { m_Forward = value; }

    const TEMPLATE& GetBackward() const { return m_Backward; }
    TEMPLATE& GetBackward() { return m_Backward; }
    void SetBackward(const TEMPLATE& value) { m_Backward = value; }

    const TBC& GetTBC() const { return m_TBC; }
    TBC& GetTBC() { return m_TBC; }
    void SetTBC(const TBC& value) { m_TBC = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

template <typename TEMPLATE>
void Key<TEMPLATE>::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Time = reader.Read<float>();

    TEMPLATE_READ(TEMPLATE, m_Value);

    if (arg== 2)
    {
        TEMPLATE_READ(TEMPLATE, m_Forward);
    }

    if (arg== 2)
    {
        TEMPLATE_READ(TEMPLATE, m_Backward);
    }

    if (arg== 3)
    {
        m_TBC.Read(reader, version, user, 0);
    }

}

template <typename TEMPLATE>
void Key<TEMPLATE>::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_Time);

    TEMPLATE_WRITE(TEMPLATE, m_Value);

    if (arg== 2)
    {
        TEMPLATE_WRITE(TEMPLATE, m_Forward);
    }

    if (arg== 2)
    {
        TEMPLATE_WRITE(TEMPLATE, m_Backward);
    }

    if (arg== 3)
    {
        m_TBC.Write(writer, version, user, 0);
    }

}
}
