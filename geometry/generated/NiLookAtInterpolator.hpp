#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiNode.hpp"
#include "string.hpp"
#include "Vector3.hpp"
#include "Quaternion.hpp"
#include "NiPoint3Interpolator.hpp"
#include "NiFloatInterpolator.hpp"
#include "NiFloatInterpolator.hpp"
#include "NiInterpolator.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown.
 *         
 */
class NiLookAtInterpolator : public NiInterpolator
{
protected:
    /**
     * Unknown.
     */
    ushort m_UnknownShort;
    /**
     * Refers to a Node to focus on.
     */
    Pointer<class NiNode*> m_LookAt;
    /**
     * Target node name.
     */
    string m_Target;
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
     * Refers to NiPoint3Interpolator.
     */
    Pointer<class NiPoint3Interpolator*> m_UnknownLink1;
    /**
     * Refers to a NiFloatInterpolator.
     */
    Pointer<class NiFloatInterpolator*> m_UnknownLink2;
    /**
     * Refers to a NiFloatInterpolator.
     */
    Pointer<class NiFloatInterpolator*> m_UnknownLink3;

public:
    const ushort& GetUnknownShort() const { return m_UnknownShort; }
    ushort& GetUnknownShort() { return m_UnknownShort; }
    void SetUnknownShort(const ushort& value) { m_UnknownShort = value; }

    const Pointer<class NiNode*>& GetLookAt() const { return m_LookAt; }
    Pointer<class NiNode*>& GetLookAt() { return m_LookAt; }
    void SetLookAt(const Pointer<class NiNode*>& value) { m_LookAt = value; }

    const string& GetTarget() const { return m_Target; }
    string& GetTarget() { return m_Target; }
    void SetTarget(const string& value) { m_Target = value; }

    const Vector3& GetTranslation() const { return m_Translation; }
    Vector3& GetTranslation() { return m_Translation; }
    void SetTranslation(const Vector3& value) { m_Translation = value; }

    const Quaternion& GetRotation() const { return m_Rotation; }
    Quaternion& GetRotation() { return m_Rotation; }
    void SetRotation(const Quaternion& value) { m_Rotation = value; }

    const float& GetScale() const { return m_Scale; }
    float& GetScale() { return m_Scale; }
    void SetScale(const float& value) { m_Scale = value; }

    const Pointer<class NiPoint3Interpolator*>& GetUnknownLink1() const { return m_UnknownLink1; }
    Pointer<class NiPoint3Interpolator*>& GetUnknownLink1() { return m_UnknownLink1; }
    void SetUnknownLink1(const Pointer<class NiPoint3Interpolator*>& value) { m_UnknownLink1 = value; }

    const Pointer<class NiFloatInterpolator*>& GetUnknownLink2() const { return m_UnknownLink2; }
    Pointer<class NiFloatInterpolator*>& GetUnknownLink2() { return m_UnknownLink2; }
    void SetUnknownLink2(const Pointer<class NiFloatInterpolator*>& value) { m_UnknownLink2 = value; }

    const Pointer<class NiFloatInterpolator*>& GetUnknownLink3() const { return m_UnknownLink3; }
    Pointer<class NiFloatInterpolator*>& GetUnknownLink3() { return m_UnknownLink3; }
    void SetUnknownLink3(const Pointer<class NiFloatInterpolator*>& value) { m_UnknownLink3 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
