#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiObject.hpp"
#include "NiAVObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Camera object.
 *         
 */
class NiCamera : public NiAVObject
{
protected:
    /**
     * Unknown.
     */
    ushort m_UnknownShort;
    /**
     * Frustrum left.
     */
    float m_FrustumLeft;
    /**
     * Frustrum right.
     */
    float m_FrustumRight;
    /**
     * Frustrum top.
     */
    float m_FrustumTop;
    /**
     * Frustrum bottom.
     */
    float m_FrustumBottom;
    /**
     * Frustrum near.
     */
    float m_FrustumNear;
    /**
     * Frustrum far.
     */
    float m_FrustumFar;
    /**
     * Determines whether perspective is used.  Orthographic means no perspective.
     */
    bool m_UseOrthographicProjection;
    /**
     * Viewport left.
     */
    float m_ViewportLeft;
    /**
     * Viewport right.
     */
    float m_ViewportRight;
    /**
     * Viewport top.
     */
    float m_ViewportTop;
    /**
     * Viewport bottom.
     */
    float m_ViewportBottom;
    /**
     * Level of detail adjust.
     */
    float m_LODAdjust;
    /**
     * Unknown.
     */
    Pointer<class NiObject*> m_UnknownLink;
    /**
     * Unknown.  Changing value crashes viewer.
     */
    uint m_UnknownInt;
    /**
     * Unknown.  Changing value crashes viewer.
     */
    uint m_UnknownInt2;
    /**
     * Unknown.
     */
    uint m_UnknownInt3;

public:
    const ushort& GetUnknownShort() const { return m_UnknownShort; }
    ushort& GetUnknownShort() { return m_UnknownShort; }
    void SetUnknownShort(const ushort& value) { m_UnknownShort = value; }

    const float& GetFrustumLeft() const { return m_FrustumLeft; }
    float& GetFrustumLeft() { return m_FrustumLeft; }
    void SetFrustumLeft(const float& value) { m_FrustumLeft = value; }

    const float& GetFrustumRight() const { return m_FrustumRight; }
    float& GetFrustumRight() { return m_FrustumRight; }
    void SetFrustumRight(const float& value) { m_FrustumRight = value; }

    const float& GetFrustumTop() const { return m_FrustumTop; }
    float& GetFrustumTop() { return m_FrustumTop; }
    void SetFrustumTop(const float& value) { m_FrustumTop = value; }

    const float& GetFrustumBottom() const { return m_FrustumBottom; }
    float& GetFrustumBottom() { return m_FrustumBottom; }
    void SetFrustumBottom(const float& value) { m_FrustumBottom = value; }

    const float& GetFrustumNear() const { return m_FrustumNear; }
    float& GetFrustumNear() { return m_FrustumNear; }
    void SetFrustumNear(const float& value) { m_FrustumNear = value; }

    const float& GetFrustumFar() const { return m_FrustumFar; }
    float& GetFrustumFar() { return m_FrustumFar; }
    void SetFrustumFar(const float& value) { m_FrustumFar = value; }

    const bool& GetUseOrthographicProjection() const { return m_UseOrthographicProjection; }
    bool& GetUseOrthographicProjection() { return m_UseOrthographicProjection; }
    void SetUseOrthographicProjection(const bool& value) { m_UseOrthographicProjection = value; }

    const float& GetViewportLeft() const { return m_ViewportLeft; }
    float& GetViewportLeft() { return m_ViewportLeft; }
    void SetViewportLeft(const float& value) { m_ViewportLeft = value; }

    const float& GetViewportRight() const { return m_ViewportRight; }
    float& GetViewportRight() { return m_ViewportRight; }
    void SetViewportRight(const float& value) { m_ViewportRight = value; }

    const float& GetViewportTop() const { return m_ViewportTop; }
    float& GetViewportTop() { return m_ViewportTop; }
    void SetViewportTop(const float& value) { m_ViewportTop = value; }

    const float& GetViewportBottom() const { return m_ViewportBottom; }
    float& GetViewportBottom() { return m_ViewportBottom; }
    void SetViewportBottom(const float& value) { m_ViewportBottom = value; }

    const float& GetLODAdjust() const { return m_LODAdjust; }
    float& GetLODAdjust() { return m_LODAdjust; }
    void SetLODAdjust(const float& value) { m_LODAdjust = value; }

    const Pointer<class NiObject*>& GetUnknownLink() const { return m_UnknownLink; }
    Pointer<class NiObject*>& GetUnknownLink() { return m_UnknownLink; }
    void SetUnknownLink(const Pointer<class NiObject*>& value) { m_UnknownLink = value; }

    const uint& GetUnknownInt() const { return m_UnknownInt; }
    uint& GetUnknownInt() { return m_UnknownInt; }
    void SetUnknownInt(const uint& value) { m_UnknownInt = value; }

    const uint& GetUnknownInt2() const { return m_UnknownInt2; }
    uint& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const uint& value) { m_UnknownInt2 = value; }

    const uint& GetUnknownInt3() const { return m_UnknownInt3; }
    uint& GetUnknownInt3() { return m_UnknownInt3; }
    void SetUnknownInt3(const uint& value) { m_UnknownInt3 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
