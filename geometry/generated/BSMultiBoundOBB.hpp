#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "Vector3.hpp"
#include "Matrix33.hpp"
#include "BSMultiBoundData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Oriented bounding box.
 *         
 */
class BSMultiBoundOBB : public BSMultiBoundData
{
protected:
    /**
     * Center of the box.
     */
    Vector3 m_Center;
    /**
     * Size of the box along each axis.
     */
    Vector3 m_Size;
    /**
     * Rotation of the bounding box.
     */
    Matrix33 m_Rotation;

public:
    const Vector3& GetCenter() const { return m_Center; }
    Vector3& GetCenter() { return m_Center; }
    void SetCenter(const Vector3& value) { m_Center = value; }

    const Vector3& GetSize() const { return m_Size; }
    Vector3& GetSize() { return m_Size; }
    void SetSize(const Vector3& value) { m_Size = value; }

    const Matrix33& GetRotation() const { return m_Rotation; }
    Matrix33& GetRotation() { return m_Rotation; }
    void SetRotation(const Matrix33& value) { m_Rotation = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
