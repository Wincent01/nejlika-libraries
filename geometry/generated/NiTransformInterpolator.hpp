#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "Quaternion.hpp"
#include "NiTransformData.hpp"
#include "NiKeyBasedInterpolator.hpp"
namespace nejlika::geometry {


/**
 * 
 *         An interpolator for transform keyframes.
 *         
 */
class NiTransformInterpolator : public NiKeyBasedInterpolator
{
protected:
    /**
     * Translate.
     */
    Vector3 m_Translation;
    /**
     * Rotation.
     */
    Quaternion m_Rotation;
    /**
     * Scale.
     */
    float m_Scale;
    /**
     * Unknown.
     */
    std::vector<byte> m_UnknownBytes;
    /**
     * Refers to NiTransformData.
     */
    Pointer<class NiTransformData*> m_Data;

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

    const std::vector<byte>& GetUnknownBytes() const { return m_UnknownBytes; }
    std::vector<byte>& GetUnknownBytes() { return m_UnknownBytes; }
    void SetUnknownBytes(const std::vector<byte>& value) { m_UnknownBytes = value; }

    const Pointer<class NiTransformData*>& GetData() const { return m_Data; }
    Pointer<class NiTransformData*>& GetData() { return m_Data; }
    void SetData(const Pointer<class NiTransformData*>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
