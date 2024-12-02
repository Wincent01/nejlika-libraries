#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "Vector3.hpp"
#include "bhkConvexShape.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A capsule.
 *         
 */
class bhkCapsuleShape : public bhkConvexShape
{
protected:
    /**
     * Unknown.
     */
    std::vector<byte> m_Unknown8Bytes;
    /**
     * First point on the capsule's axis.
     */
    Vector3 m_FirstPoint;
    /**
     * Matches first capsule radius.
     */
    float m_Radius1;
    /**
     * Second point on the capsule's axis.
     */
    Vector3 m_SecondPoint;
    /**
     * Matches second capsule radius.
     */
    float m_Radius2;

public:
    const std::vector<byte>& GetUnknown8Bytes() const { return m_Unknown8Bytes; }
    std::vector<byte>& GetUnknown8Bytes() { return m_Unknown8Bytes; }
    void SetUnknown8Bytes(const std::vector<byte>& value) { m_Unknown8Bytes = value; }

    const Vector3& GetFirstPoint() const { return m_FirstPoint; }
    Vector3& GetFirstPoint() { return m_FirstPoint; }
    void SetFirstPoint(const Vector3& value) { m_FirstPoint = value; }

    const float& GetRadius1() const { return m_Radius1; }
    float& GetRadius1() { return m_Radius1; }
    void SetRadius1(const float& value) { m_Radius1 = value; }

    const Vector3& GetSecondPoint() const { return m_SecondPoint; }
    Vector3& GetSecondPoint() { return m_SecondPoint; }
    void SetSecondPoint(const Vector3& value) { m_SecondPoint = value; }

    const float& GetRadius2() const { return m_Radius2; }
    float& GetRadius2() { return m_Radius2; }
    void SetRadius2(const float& value) { m_Radius2 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
