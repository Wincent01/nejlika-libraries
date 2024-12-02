#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Matrix33.hpp"
#include "Vector3.hpp"
#include "Vector3.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Sub data of NiBezierMesh
 *         
 */
class NiBezierTriangle4 : public NiObject
{
protected:
    /**
     * unknown
     */
    std::vector<uint> m_Unknown1;
    /**
     * unknown
     */
    ushort m_Unknown2;
    /**
     * unknown
     */
    Matrix33 m_Matrix;
    /**
     * unknown
     */
    Vector3 m_Vector1;
    /**
     * unknown
     */
    Vector3 m_Vector2;
    /**
     * unknown
     */
    std::vector<short> m_Unknown3;
    /**
     * unknown
     */
    byte m_Unknown4;
    /**
     * unknown
     */
    uint m_Unknown5;
    /**
     * unknown
     */
    std::vector<short> m_Unknown6;

public:
    const std::vector<uint>& GetUnknown1() const { return m_Unknown1; }
    std::vector<uint>& GetUnknown1() { return m_Unknown1; }
    void SetUnknown1(const std::vector<uint>& value) { m_Unknown1 = value; }

    const ushort& GetUnknown2() const { return m_Unknown2; }
    ushort& GetUnknown2() { return m_Unknown2; }
    void SetUnknown2(const ushort& value) { m_Unknown2 = value; }

    const Matrix33& GetMatrix() const { return m_Matrix; }
    Matrix33& GetMatrix() { return m_Matrix; }
    void SetMatrix(const Matrix33& value) { m_Matrix = value; }

    const Vector3& GetVector1() const { return m_Vector1; }
    Vector3& GetVector1() { return m_Vector1; }
    void SetVector1(const Vector3& value) { m_Vector1 = value; }

    const Vector3& GetVector2() const { return m_Vector2; }
    Vector3& GetVector2() { return m_Vector2; }
    void SetVector2(const Vector3& value) { m_Vector2 = value; }

    const std::vector<short>& GetUnknown3() const { return m_Unknown3; }
    std::vector<short>& GetUnknown3() { return m_Unknown3; }
    void SetUnknown3(const std::vector<short>& value) { m_Unknown3 = value; }

    const byte& GetUnknown4() const { return m_Unknown4; }
    byte& GetUnknown4() { return m_Unknown4; }
    void SetUnknown4(const byte& value) { m_Unknown4 = value; }

    const uint& GetUnknown5() const { return m_Unknown5; }
    uint& GetUnknown5() { return m_Unknown5; }
    void SetUnknown5(const uint& value) { m_Unknown5 = value; }

    const std::vector<short>& GetUnknown6() const { return m_Unknown6; }
    std::vector<short>& GetUnknown6() { return m_Unknown6; }
    void SetUnknown6(const std::vector<short>& value) { m_Unknown6 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
