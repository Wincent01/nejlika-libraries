#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector4.hpp"
#include "Vector4.hpp"
#include "bhkConstraint.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A spring constraint.
 *         
 */
class bhkStiffSpringConstraint : public bhkConstraint
{
protected:
    /**
     * Pivot A.
     */
    Vector4 m_PivotA;
    /**
     * Pivot B.
     */
    Vector4 m_PivotB;
    /**
     * Length.
     */
    float m_Length;

public:
    const Vector4& GetPivotA() const { return m_PivotA; }
    Vector4& GetPivotA() { return m_PivotA; }
    void SetPivotA(const Vector4& value) { m_PivotA = value; }

    const Vector4& GetPivotB() const { return m_PivotB; }
    Vector4& GetPivotB() { return m_PivotB; }
    void SetPivotB(const Vector4& value) { m_PivotB = value; }

    const float& GetLength() const { return m_Length; }
    float& GetLength() { return m_Length; }
    void SetLength(const float& value) { m_Length = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
