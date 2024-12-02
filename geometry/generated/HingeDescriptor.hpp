#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
#include "Vector4.hpp"
namespace nejlika::geometry {


/**
 * 
 *     	This constraint allows rotation about a specified axis. 
 *     	
 *         
 */
class HingeDescriptor : public Construct
{
protected:
    /**
     * Pivot point around which the object will rotate.
     */
    Vector4 m_PivotA;
    /**
     * Vector in the rotation plane which defines the zero angle.
     */
    Vector4 m_Perp2AxleInA1;
    /**
     * Vector in the rotation plane, orthogonal on the previous one, which defines the positive direction of rotation.
     */
    Vector4 m_Perp2AxleInA2;
    /**
     * Pivot A in second entity coordinate system.
     */
    Vector4 m_PivotB;
    /**
     * Axle A (vector orthogonal on Perp2 Axles) in second entity coordinate system.
     */
    Vector4 m_AxleB;
    /**
     * Axis of rotation.
     */
    Vector4 m_AxleA;
    /**
     * Perp2 Axle In A1 in second entity coordinate system.
     */
    Vector4 m_Perp2AxleInB1;
    /**
     * Perp2 Axle In A2 in second entity coordinate system.
     */
    Vector4 m_Perp2AxleInB2;

public:
    const Vector4& GetPivotA() const { return m_PivotA; }
    Vector4& GetPivotA() { return m_PivotA; }
    void SetPivotA(const Vector4& value) { m_PivotA = value; }

    const Vector4& GetPerp2AxleInA1() const { return m_Perp2AxleInA1; }
    Vector4& GetPerp2AxleInA1() { return m_Perp2AxleInA1; }
    void SetPerp2AxleInA1(const Vector4& value) { m_Perp2AxleInA1 = value; }

    const Vector4& GetPerp2AxleInA2() const { return m_Perp2AxleInA2; }
    Vector4& GetPerp2AxleInA2() { return m_Perp2AxleInA2; }
    void SetPerp2AxleInA2(const Vector4& value) { m_Perp2AxleInA2 = value; }

    const Vector4& GetPivotB() const { return m_PivotB; }
    Vector4& GetPivotB() { return m_PivotB; }
    void SetPivotB(const Vector4& value) { m_PivotB = value; }

    const Vector4& GetAxleB() const { return m_AxleB; }
    Vector4& GetAxleB() { return m_AxleB; }
    void SetAxleB(const Vector4& value) { m_AxleB = value; }

    const Vector4& GetAxleA() const { return m_AxleA; }
    Vector4& GetAxleA() { return m_AxleA; }
    void SetAxleA(const Vector4& value) { m_AxleA = value; }

    const Vector4& GetPerp2AxleInB1() const { return m_Perp2AxleInB1; }
    Vector4& GetPerp2AxleInB1() { return m_Perp2AxleInB1; }
    void SetPerp2AxleInB1(const Vector4& value) { m_Perp2AxleInB1 = value; }

    const Vector4& GetPerp2AxleInB2() const { return m_Perp2AxleInB2; }
    Vector4& GetPerp2AxleInB2() { return m_Perp2AxleInB2; }
    void SetPerp2AxleInB2(const Vector4& value) { m_Perp2AxleInB2 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
