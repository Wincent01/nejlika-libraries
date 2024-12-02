#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "Matrix33.hpp"
#include "Vector3.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bounding box.
 *         
 */
class BoundingBox : public Construct
{
protected:
    /**
     * Usually 1.
     */
    uint m_UnknownInt;
    /**
     * Translation vector.
     */
    Vector3 m_Translation;
    /**
     * Rotation matrix.
     */
    Matrix33 m_Rotation;
    /**
     * Radius, per direction.
     */
    Vector3 m_Radius;

public:
    const uint& GetUnknownInt() const { return m_UnknownInt; }
    uint& GetUnknownInt() { return m_UnknownInt; }
    void SetUnknownInt(const uint& value) { m_UnknownInt = value; }

    const Vector3& GetTranslation() const { return m_Translation; }
    Vector3& GetTranslation() { return m_Translation; }
    void SetTranslation(const Vector3& value) { m_Translation = value; }

    const Matrix33& GetRotation() const { return m_Rotation; }
    Matrix33& GetRotation() { return m_Rotation; }
    void SetRotation(const Matrix33& value) { m_Rotation = value; }

    const Vector3& GetRadius() const { return m_Radius; }
    Vector3& GetRadius() { return m_Radius; }
    void SetRadius(const Vector3& value) { m_Radius = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
