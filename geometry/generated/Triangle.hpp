#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


/**
 * 
 *         List of three vertex indices.
 *         
 */
class Triangle : public Construct
{
protected:
    /**
     * First vertex index.
     */
    ushort m_v1;
    /**
     * Second vertex index.
     */
    ushort m_v2;
    /**
     * Third vertex index.
     */
    ushort m_v3;

public:
    const ushort& Getv1() const { return m_v1; }
    ushort& Getv1() { return m_v1; }
    void Setv1(const ushort& value) { m_v1 = value; }

    const ushort& Getv2() const { return m_v2; }
    ushort& Getv2() { return m_v2; }
    void Setv2(const ushort& value) { m_v2 = value; }

    const ushort& Getv3() const { return m_v3; }
    ushort& Getv3() { return m_v3; }
    void Setv3(const ushort& value) { m_v3 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
