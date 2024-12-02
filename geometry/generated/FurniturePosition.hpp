#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "AnimationType.hpp"
#include "FurnitureEntryPoints.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Describes a furniture position?
 *         
 */
class FurniturePosition : public Construct
{
protected:
    /**
     * Offset of furniture marker.
     */
    Vector3 m_Offset;
    /**
     * Furniture marker orientation.
     */
    ushort m_Orientation;
    /**
     * Refers to a furnituremarkerxx.nif file. Always seems to be the same as Position Ref 2.
     */
    byte m_PositionRef1;
    /**
     * Refers to a furnituremarkerxx.nif file. Always seems to be the same as Position Ref 1.
     */
    byte m_PositionRef2;
    /**
     * Similar to Orientation, in float form.
     */
    float m_Heading;
    /**
     * Unknown
     */
    AnimationType m_AnimationType;
    /**
     * Unknown/unused in nif?
     */
    FurnitureEntryPoints m_EntryProperties;

public:
    const Vector3& GetOffset() const { return m_Offset; }
    Vector3& GetOffset() { return m_Offset; }
    void SetOffset(const Vector3& value) { m_Offset = value; }

    const ushort& GetOrientation() const { return m_Orientation; }
    ushort& GetOrientation() { return m_Orientation; }
    void SetOrientation(const ushort& value) { m_Orientation = value; }

    const byte& GetPositionRef1() const { return m_PositionRef1; }
    byte& GetPositionRef1() { return m_PositionRef1; }
    void SetPositionRef1(const byte& value) { m_PositionRef1 = value; }

    const byte& GetPositionRef2() const { return m_PositionRef2; }
    byte& GetPositionRef2() { return m_PositionRef2; }
    void SetPositionRef2(const byte& value) { m_PositionRef2 = value; }

    const float& GetHeading() const { return m_Heading; }
    float& GetHeading() { return m_Heading; }
    void SetHeading(const float& value) { m_Heading = value; }

    const AnimationType& GetAnimationType() const { return m_AnimationType; }
    AnimationType& GetAnimationType() { return m_AnimationType; }
    void SetAnimationType(const AnimationType& value) { m_AnimationType = value; }

    const FurnitureEntryPoints& GetEntryProperties() const { return m_EntryProperties; }
    FurnitureEntryPoints& GetEntryProperties() { return m_EntryProperties; }
    void SetEntryProperties(const FurnitureEntryPoints& value) { m_EntryProperties = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
