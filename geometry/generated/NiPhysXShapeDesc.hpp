#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Quaternion.hpp"
#include "Quaternion.hpp"
#include "Quaternion.hpp"
#include "NiPhysXMeshDesc.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown PhysX node.
 *         
 */
class NiPhysXShapeDesc : public NiObject
{
protected:
    /**
     * Unknown
     */
    int m_UnknownInt1;
    /**
     * Unknown
     */
    Quaternion m_UnknownQuat1;
    /**
     * Unknown
     */
    Quaternion m_UnknownQuat2;
    /**
     * Unknown
     */
    Quaternion m_UnknownQuat3;
    /**
     * Unknown
     */
    short m_UnknownShort1;
    /**
     * Unknown
     */
    int m_UnknownInt2;
    /**
     * Unknown
     */
    short m_UnknownShort2;
    /**
     * Unknown
     */
    float m_UnknownFloat1;
    /**
     * Unknown
     */
    float m_UnknownFloat2;
    /**
     * Unknown
     */
    float m_UnknownFloat3;
    /**
     * Unknown
     */
    int m_UnknownInt3;
    /**
     * Unknown
     */
    int m_UnknownInt4;
    /**
     * Unknown
     */
    int m_UnknownInt5;
    /**
     * Unknown
     */
    int m_UnknownInt7;
    /**
     * Unknown
     */
    int m_UnknownInt8;
    /**
     * PhysX Mesh Description
     */
    Pointer<class NiPhysXMeshDesc*> m_MeshDescription;

public:
    const int& GetUnknownInt1() const { return m_UnknownInt1; }
    int& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const int& value) { m_UnknownInt1 = value; }

    const Quaternion& GetUnknownQuat1() const { return m_UnknownQuat1; }
    Quaternion& GetUnknownQuat1() { return m_UnknownQuat1; }
    void SetUnknownQuat1(const Quaternion& value) { m_UnknownQuat1 = value; }

    const Quaternion& GetUnknownQuat2() const { return m_UnknownQuat2; }
    Quaternion& GetUnknownQuat2() { return m_UnknownQuat2; }
    void SetUnknownQuat2(const Quaternion& value) { m_UnknownQuat2 = value; }

    const Quaternion& GetUnknownQuat3() const { return m_UnknownQuat3; }
    Quaternion& GetUnknownQuat3() { return m_UnknownQuat3; }
    void SetUnknownQuat3(const Quaternion& value) { m_UnknownQuat3 = value; }

    const short& GetUnknownShort1() const { return m_UnknownShort1; }
    short& GetUnknownShort1() { return m_UnknownShort1; }
    void SetUnknownShort1(const short& value) { m_UnknownShort1 = value; }

    const int& GetUnknownInt2() const { return m_UnknownInt2; }
    int& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const int& value) { m_UnknownInt2 = value; }

    const short& GetUnknownShort2() const { return m_UnknownShort2; }
    short& GetUnknownShort2() { return m_UnknownShort2; }
    void SetUnknownShort2(const short& value) { m_UnknownShort2 = value; }

    const float& GetUnknownFloat1() const { return m_UnknownFloat1; }
    float& GetUnknownFloat1() { return m_UnknownFloat1; }
    void SetUnknownFloat1(const float& value) { m_UnknownFloat1 = value; }

    const float& GetUnknownFloat2() const { return m_UnknownFloat2; }
    float& GetUnknownFloat2() { return m_UnknownFloat2; }
    void SetUnknownFloat2(const float& value) { m_UnknownFloat2 = value; }

    const float& GetUnknownFloat3() const { return m_UnknownFloat3; }
    float& GetUnknownFloat3() { return m_UnknownFloat3; }
    void SetUnknownFloat3(const float& value) { m_UnknownFloat3 = value; }

    const int& GetUnknownInt3() const { return m_UnknownInt3; }
    int& GetUnknownInt3() { return m_UnknownInt3; }
    void SetUnknownInt3(const int& value) { m_UnknownInt3 = value; }

    const int& GetUnknownInt4() const { return m_UnknownInt4; }
    int& GetUnknownInt4() { return m_UnknownInt4; }
    void SetUnknownInt4(const int& value) { m_UnknownInt4 = value; }

    const int& GetUnknownInt5() const { return m_UnknownInt5; }
    int& GetUnknownInt5() { return m_UnknownInt5; }
    void SetUnknownInt5(const int& value) { m_UnknownInt5 = value; }

    const int& GetUnknownInt7() const { return m_UnknownInt7; }
    int& GetUnknownInt7() { return m_UnknownInt7; }
    void SetUnknownInt7(const int& value) { m_UnknownInt7 = value; }

    const int& GetUnknownInt8() const { return m_UnknownInt8; }
    int& GetUnknownInt8() { return m_UnknownInt8; }
    void SetUnknownInt8(const int& value) { m_UnknownInt8 = value; }

    const Pointer<class NiPhysXMeshDesc*>& GetMeshDescription() const { return m_MeshDescription; }
    Pointer<class NiPhysXMeshDesc*>& GetMeshDescription() { return m_MeshDescription; }
    void SetMeshDescription(const Pointer<class NiPhysXMeshDesc*>& value) { m_MeshDescription = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
