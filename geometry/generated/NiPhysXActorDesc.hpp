#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Quaternion.hpp"
#include "Quaternion.hpp"
#include "Quaternion.hpp"
#include "NiPhysXBodyDesc.hpp"
#include "NiPhysXShapeDesc.hpp"
#include "NiObject.hpp"
#include "NiObject.hpp"
#include "NiObject.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown PhysX node.
 *         
 */
class NiPhysXActorDesc : public NiObject
{
protected:
    /**
     * Unknown
     */
    int m_UnknownInt1;
    /**
     * Unknown
     */
    int m_UnknownInt2;
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
    Pointer<class NiPhysXBodyDesc*> m_UnknownRef0;
    /**
     * Unknown
     */
    float m_UnknownInt4;
    /**
     * Unknown
     */
    int m_UnknownInt5;
    /**
     * Unknown
     */
    byte m_UnknownByte1;
    /**
     * Unknown
     */
    byte m_UnknownByte2;
    /**
     * Unknown
     */
    int m_UnknownInt6;
    /**
     * PhysX Shape Description
     */
    Pointer<class NiPhysXShapeDesc*> m_ShapeDescription;
    /**
     * Unknown
     */
    Pointer<class NiObject*> m_UnknownRef1;
    /**
     * Unknown
     */
    Pointer<class NiObject*> m_UnknownRef2;
    /**
     * Unknown
     */
    std::vector<Pointer<class NiObject*>> m_UnknownRefs3;

public:
    const int& GetUnknownInt1() const { return m_UnknownInt1; }
    int& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const int& value) { m_UnknownInt1 = value; }

    const int& GetUnknownInt2() const { return m_UnknownInt2; }
    int& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const int& value) { m_UnknownInt2 = value; }

    const Quaternion& GetUnknownQuat1() const { return m_UnknownQuat1; }
    Quaternion& GetUnknownQuat1() { return m_UnknownQuat1; }
    void SetUnknownQuat1(const Quaternion& value) { m_UnknownQuat1 = value; }

    const Quaternion& GetUnknownQuat2() const { return m_UnknownQuat2; }
    Quaternion& GetUnknownQuat2() { return m_UnknownQuat2; }
    void SetUnknownQuat2(const Quaternion& value) { m_UnknownQuat2 = value; }

    const Quaternion& GetUnknownQuat3() const { return m_UnknownQuat3; }
    Quaternion& GetUnknownQuat3() { return m_UnknownQuat3; }
    void SetUnknownQuat3(const Quaternion& value) { m_UnknownQuat3 = value; }

    const Pointer<class NiPhysXBodyDesc*>& GetUnknownRef0() const { return m_UnknownRef0; }
    Pointer<class NiPhysXBodyDesc*>& GetUnknownRef0() { return m_UnknownRef0; }
    void SetUnknownRef0(const Pointer<class NiPhysXBodyDesc*>& value) { m_UnknownRef0 = value; }

    const float& GetUnknownInt4() const { return m_UnknownInt4; }
    float& GetUnknownInt4() { return m_UnknownInt4; }
    void SetUnknownInt4(const float& value) { m_UnknownInt4 = value; }

    const int& GetUnknownInt5() const { return m_UnknownInt5; }
    int& GetUnknownInt5() { return m_UnknownInt5; }
    void SetUnknownInt5(const int& value) { m_UnknownInt5 = value; }

    const byte& GetUnknownByte1() const { return m_UnknownByte1; }
    byte& GetUnknownByte1() { return m_UnknownByte1; }
    void SetUnknownByte1(const byte& value) { m_UnknownByte1 = value; }

    const byte& GetUnknownByte2() const { return m_UnknownByte2; }
    byte& GetUnknownByte2() { return m_UnknownByte2; }
    void SetUnknownByte2(const byte& value) { m_UnknownByte2 = value; }

    const int& GetUnknownInt6() const { return m_UnknownInt6; }
    int& GetUnknownInt6() { return m_UnknownInt6; }
    void SetUnknownInt6(const int& value) { m_UnknownInt6 = value; }

    const Pointer<class NiPhysXShapeDesc*>& GetShapeDescription() const { return m_ShapeDescription; }
    Pointer<class NiPhysXShapeDesc*>& GetShapeDescription() { return m_ShapeDescription; }
    void SetShapeDescription(const Pointer<class NiPhysXShapeDesc*>& value) { m_ShapeDescription = value; }

    const Pointer<class NiObject*>& GetUnknownRef1() const { return m_UnknownRef1; }
    Pointer<class NiObject*>& GetUnknownRef1() { return m_UnknownRef1; }
    void SetUnknownRef1(const Pointer<class NiObject*>& value) { m_UnknownRef1 = value; }

    const Pointer<class NiObject*>& GetUnknownRef2() const { return m_UnknownRef2; }
    Pointer<class NiObject*>& GetUnknownRef2() { return m_UnknownRef2; }
    void SetUnknownRef2(const Pointer<class NiObject*>& value) { m_UnknownRef2 = value; }

    const std::vector<Pointer<class NiObject*>>& GetUnknownRefs3() const { return m_UnknownRefs3; }
    std::vector<Pointer<class NiObject*>>& GetUnknownRefs3() { return m_UnknownRefs3; }
    void SetUnknownRefs3(const std::vector<Pointer<class NiObject*>>& value) { m_UnknownRefs3 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
