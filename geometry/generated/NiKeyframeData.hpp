#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "KeyType.hpp"
#include "QuatKey.hpp"
#include "Quaternion.hpp"
#include "KeyGroup.hpp"
#include "KeyGroup.hpp"
#include "Vector3.hpp"
#include "KeyGroup.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Keyframes for mesh animation.
 *         
 */
class NiKeyframeData : public NiObject
{
protected:
    /**
     * The number of quaternion rotation keys. If the rotation type is XYZ (type 4) then this *must* be set to 1, and in this case the actual number of keys is stored in the XYZ Rotations field.
     */
    uint m_NumRotationKeys;
    /**
     * The type of interpolation to use for rotation.  Can also be 4 to indicate that separate X, Y, and Z values are used for the rotation instead of Quaternions.
     */
    KeyType m_RotationType;
    /**
     * The rotation keys if Quaternion rotation is used.
     */
    std::vector<QuatKey<Quaternion>> m_QuaternionKeys;
    /**
     * Possibly a vestigial time value?  Doesn't appear to be significant.
     */
    float m_UnknownFloat;
    /**
     * Individual arrays of keys for rotating X, Y, and Z individually.
     */
    std::vector<KeyGroup<float>> m_XYZRotations;
    /**
     * Translation keys.
     */
    KeyGroup<Vector3> m_Translations;
    /**
     * Scale keys.
     */
    KeyGroup<float> m_Scales;

public:
    const uint& GetNumRotationKeys() const { return m_NumRotationKeys; }
    uint& GetNumRotationKeys() { return m_NumRotationKeys; }
    void SetNumRotationKeys(const uint& value) { m_NumRotationKeys = value; }

    const KeyType& GetRotationType() const { return m_RotationType; }
    KeyType& GetRotationType() { return m_RotationType; }
    void SetRotationType(const KeyType& value) { m_RotationType = value; }

    const std::vector<QuatKey<Quaternion>>& GetQuaternionKeys() const { return m_QuaternionKeys; }
    std::vector<QuatKey<Quaternion>>& GetQuaternionKeys() { return m_QuaternionKeys; }
    void SetQuaternionKeys(const std::vector<QuatKey<Quaternion>>& value) { m_QuaternionKeys = value; }

    const float& GetUnknownFloat() const { return m_UnknownFloat; }
    float& GetUnknownFloat() { return m_UnknownFloat; }
    void SetUnknownFloat(const float& value) { m_UnknownFloat = value; }

    const std::vector<KeyGroup<float>>& GetXYZRotations() const { return m_XYZRotations; }
    std::vector<KeyGroup<float>>& GetXYZRotations() { return m_XYZRotations; }
    void SetXYZRotations(const std::vector<KeyGroup<float>>& value) { m_XYZRotations = value; }

    const KeyGroup<Vector3>& GetTranslations() const { return m_Translations; }
    KeyGroup<Vector3>& GetTranslations() { return m_Translations; }
    void SetTranslations(const KeyGroup<Vector3>& value) { m_Translations = value; }

    const KeyGroup<float>& GetScales() const { return m_Scales; }
    KeyGroup<float>& GetScales() { return m_Scales; }
    void SetScales(const KeyGroup<float>& value) { m_Scales = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
