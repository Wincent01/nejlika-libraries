#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Triangle.hpp"
#include "Vector3.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A triangle with extra data used for physics.
 *         
 */
class hkTriangle : public Construct
{
protected:
    /**
     * The triangle.
     */
    Triangle m_Triangle;
    /**
     * Additional havok information on how triangles are welded.
     */
    ushort m_WeldingInfo;
    /**
     * This is the triangle's normal.
     */
    Vector3 m_Normal;

public:
    const Triangle& GetTriangle() const { return m_Triangle; }
    Triangle& GetTriangle() { return m_Triangle; }
    void SetTriangle(const Triangle& value) { m_Triangle = value; }

    const ushort& GetWeldingInfo() const { return m_WeldingInfo; }
    ushort& GetWeldingInfo() { return m_WeldingInfo; }
    void SetWeldingInfo(const ushort& value) { m_WeldingInfo = value; }

    const Vector3& GetNormal() const { return m_Normal; }
    Vector3& GetNormal() { return m_Normal; }
    void SetNormal(const Vector3& value) { m_Normal = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
