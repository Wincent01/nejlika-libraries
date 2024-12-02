#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "Matrix33.hpp"
namespace nejlika::geometry {


class MTransform : public Construct
{
protected:
    /**
     * Translation.
     */
    Vector3 m_Translation;
    /**
     * Rotation.
     */
    Matrix33 m_Rotation;
    /**
     * Scale.
     */
    float m_Scale;

public:
    const Vector3& GetTranslation() const { return m_Translation; }
    Vector3& GetTranslation() { return m_Translation; }
    void SetTranslation(const Vector3& value) { m_Translation = value; }

    const Matrix33& GetRotation() const { return m_Rotation; }
    Matrix33& GetRotation() { return m_Rotation; }
    void SetRotation(const Matrix33& value) { m_Rotation = value; }

    const float& GetScale() const { return m_Scale; }
    float& GetScale() { return m_Scale; }
    void SetScale(const float& value) { m_Scale = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
