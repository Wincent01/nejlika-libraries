#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "TBC.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A special version of the key type used for quaternions.  Never has tangents.
 *         
 */
template <typename TEMPLATE>
class QuatKey : public Construct
{
protected:
    /**
     * Time the key applies.
     */
    float m_Time;
    /**
     * Value of the key.
     */
    TEMPLATE m_Value;
    /**
     * The TBC of the key.
     */
    TBC m_TBC;

public:
    const float& GetTime() const { return m_Time; }
    float& GetTime() { return m_Time; }
    void SetTime(const float& value) { m_Time = value; }

    const TEMPLATE& GetValue() const { return m_Value; }
    TEMPLATE& GetValue() { return m_Value; }
    void SetValue(const TEMPLATE& value) { m_Value = value; }

    const TBC& GetTBC() const { return m_TBC; }
    TBC& GetTBC() { return m_TBC; }
    void SetTBC(const TBC& value) { m_TBC = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

template <typename TEMPLATE>
void QuatKey<TEMPLATE>::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_Time = reader.Read<float>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && arg!= 4)
    {
        m_Time = reader.Read<float>();
    }

    if (arg!= 4)
    {
        TEMPLATE_READ(TEMPLATE, m_Value);
    }

    if (arg== 3)
    {
        m_TBC.Read(reader, version, user, 0);
    }

}

template <typename TEMPLATE>
void QuatKey<TEMPLATE>::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_Time);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && arg!= 4)
    {
        writer.Write(m_Time);
    }

    if (arg!= 4)
    {
        TEMPLATE_WRITE(TEMPLATE, m_Value);
    }

    if (arg== 3)
    {
        m_TBC.Write(writer, version, user, 0);
    }

}
}
