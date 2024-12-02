#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "Quaternion.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-specific node.
 *         
 */
class BSTreadTransformData : public Construct
{
protected:
    /**
     * Translation.
     */
    Vector3 m_Translation;
    /**
     * Rotation.
     */
    Quaternion m_Rotation;
    /**
     * Scale (usually float_min).
     */
    float m_Scale;

public:
    const Vector3& GetTranslation() const { return m_Translation; }
    Vector3& GetTranslation() { return m_Translation; }
    void SetTranslation(const Vector3& value) { m_Translation = value; }

    const Quaternion& GetRotation() const { return m_Rotation; }
    Quaternion& GetRotation() { return m_Rotation; }
    void SetRotation(const Quaternion& value) { m_Rotation = value; }

    const float& GetScale() const { return m_Scale; }
    float& GetScale() { return m_Scale; }
    void SetScale(const float& value) { m_Scale = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
