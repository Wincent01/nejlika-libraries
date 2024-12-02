#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiObject.hpp"
#include "Vector3.hpp"
#include "NiPSysModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown.
 *         
 */
class NiPSysDragModifier : public NiPSysModifier
{
protected:
    /**
     * Parent reference.
     */
    Pointer<class NiObject*> m_Parent;
    /**
     * The drag axis.
     */
    Vector3 m_DragAxis;
    /**
     * Drag percentage.
     */
    float m_Percentage;
    /**
     * The range.
     */
    float m_Range;
    /**
     * The range falloff.
     */
    float m_RangeFalloff;

public:
    const Pointer<class NiObject*>& GetParent() const { return m_Parent; }
    Pointer<class NiObject*>& GetParent() { return m_Parent; }
    void SetParent(const Pointer<class NiObject*>& value) { m_Parent = value; }

    const Vector3& GetDragAxis() const { return m_DragAxis; }
    Vector3& GetDragAxis() { return m_DragAxis; }
    void SetDragAxis(const Vector3& value) { m_DragAxis = value; }

    const float& GetPercentage() const { return m_Percentage; }
    float& GetPercentage() { return m_Percentage; }
    void SetPercentage(const float& value) { m_Percentage = value; }

    const float& GetRange() const { return m_Range; }
    float& GetRange() { return m_Range; }
    void SetRange(const float& value) { m_Range = value; }

    const float& GetRangeFalloff() const { return m_RangeFalloff; }
    float& GetRangeFalloff() { return m_RangeFalloff; }
    void SetRangeFalloff(const float& value) { m_RangeFalloff = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
