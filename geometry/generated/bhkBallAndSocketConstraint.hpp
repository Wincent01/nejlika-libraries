#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "Vector3.hpp"
#include "bhkConstraint.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A Ball and Socket Constraint.
 *         
 */
class bhkBallAndSocketConstraint : public bhkConstraint
{
protected:
    /**
     * Unknown
     */
    std::vector<byte> m_Unknown4Bytes;
    /**
     * Unknown
     */
    Vector3 m_UnknownFloats1;
    /**
     * Unknown
     */
    Vector3 m_UnknownFloats2;
    /**
     * Unknown
     */
    uint m_UnknownInt1;

public:
    const std::vector<byte>& GetUnknown4Bytes() const { return m_Unknown4Bytes; }
    std::vector<byte>& GetUnknown4Bytes() { return m_Unknown4Bytes; }
    void SetUnknown4Bytes(const std::vector<byte>& value) { m_Unknown4Bytes = value; }

    const Vector3& GetUnknownFloats1() const { return m_UnknownFloats1; }
    Vector3& GetUnknownFloats1() { return m_UnknownFloats1; }
    void SetUnknownFloats1(const Vector3& value) { m_UnknownFloats1 = value; }

    const Vector3& GetUnknownFloats2() const { return m_UnknownFloats2; }
    Vector3& GetUnknownFloats2() { return m_UnknownFloats2; }
    void SetUnknownFloats2(const Vector3& value) { m_UnknownFloats2 = value; }

    const uint& GetUnknownInt1() const { return m_UnknownInt1; }
    uint& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const uint& value) { m_UnknownInt1 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
