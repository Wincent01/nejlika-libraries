#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "OblivionSubShape.hpp"
#include "Vector3.hpp"
#include "Vector3.hpp"
#include "hkPackedNiTriStripsData.hpp"
#include "bhkShapeCollection.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A shape constructed from strips data.
 *         
 */
class bhkPackedNiTriStripsShape : public bhkShapeCollection
{
protected:
    /**
     * Number of subparts.
     */
    ushort m_NumSubShapes;
    /**
     * The subparts.
     */
    std::vector<OblivionSubShape> m_SubShapes;
    /**
     * Unknown.
     */
    uint m_UnknownInt1;
    /**
     * Unknown. Looks like a memory pointer and may be garbage.
     */
    uint m_UnknownInt2;
    /**
     * Unknown. Same as Unknown Float 3
     */
    float m_UnknownFloat1;
    /**
     * Unknown. Sometimes 0.0f or -1. but sometimes really large number.  Suspect its garbage.
     */
    uint m_UnknownInt3;
    /**
     * Unknown. Same as scale below?
     */
    Vector3 m_ScaleCopy;
    /**
     * Unknown. Usually 0.0 but sometimes 1.0.  Same as Unknown Float 4
     */
    float m_UnknownFloat2;
    /**
     * Unknown. Same as Unknown Float 1
     */
    float m_UnknownFloat3;
    /**
     * Scale.
     */
    Vector3 m_Scale;
    /**
     * Unknown. Usually 0.0 but sometimes 1.0.  Same as Unknown Float 2
     */
    float m_UnknownFloat4;
    /**
     * A link to the shape's NiTriStripsData.
     */
    Pointer<class hkPackedNiTriStripsData*> m_Data;

public:
    const ushort& GetNumSubShapes() const { return m_NumSubShapes; }
    ushort& GetNumSubShapes() { return m_NumSubShapes; }
    void SetNumSubShapes(const ushort& value) { m_NumSubShapes = value; }

    const std::vector<OblivionSubShape>& GetSubShapes() const { return m_SubShapes; }
    std::vector<OblivionSubShape>& GetSubShapes() { return m_SubShapes; }
    void SetSubShapes(const std::vector<OblivionSubShape>& value) { m_SubShapes = value; }

    const uint& GetUnknownInt1() const { return m_UnknownInt1; }
    uint& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const uint& value) { m_UnknownInt1 = value; }

    const uint& GetUnknownInt2() const { return m_UnknownInt2; }
    uint& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const uint& value) { m_UnknownInt2 = value; }

    const float& GetUnknownFloat1() const { return m_UnknownFloat1; }
    float& GetUnknownFloat1() { return m_UnknownFloat1; }
    void SetUnknownFloat1(const float& value) { m_UnknownFloat1 = value; }

    const uint& GetUnknownInt3() const { return m_UnknownInt3; }
    uint& GetUnknownInt3() { return m_UnknownInt3; }
    void SetUnknownInt3(const uint& value) { m_UnknownInt3 = value; }

    const Vector3& GetScaleCopy() const { return m_ScaleCopy; }
    Vector3& GetScaleCopy() { return m_ScaleCopy; }
    void SetScaleCopy(const Vector3& value) { m_ScaleCopy = value; }

    const float& GetUnknownFloat2() const { return m_UnknownFloat2; }
    float& GetUnknownFloat2() { return m_UnknownFloat2; }
    void SetUnknownFloat2(const float& value) { m_UnknownFloat2 = value; }

    const float& GetUnknownFloat3() const { return m_UnknownFloat3; }
    float& GetUnknownFloat3() { return m_UnknownFloat3; }
    void SetUnknownFloat3(const float& value) { m_UnknownFloat3 = value; }

    const Vector3& GetScale() const { return m_Scale; }
    Vector3& GetScale() { return m_Scale; }
    void SetScale(const Vector3& value) { m_Scale = value; }

    const float& GetUnknownFloat4() const { return m_UnknownFloat4; }
    float& GetUnknownFloat4() { return m_UnknownFloat4; }
    void SetUnknownFloat4(const float& value) { m_UnknownFloat4 = value; }

    const Pointer<class hkPackedNiTriStripsData*>& GetData() const { return m_Data; }
    Pointer<class hkPackedNiTriStripsData*>& GetData() { return m_Data; }
    void SetData(const Pointer<class hkPackedNiTriStripsData*>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
