#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "string.hpp"
#include "NiNode.hpp"
#include "NiLight.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


class NiShadowGenerator : public NiObject
{
protected:
    string m_Name;
    ushort m_UnknownFlags;
    uint m_NumUnknownLinks1;
    std::vector<Pointer<class NiNode*>> m_UnknownLinks1;
    int m_UnkownInt2;
    Pointer<class NiLight*> m_Target;
    float m_UnkownFloat4;
    byte m_UnkownByte5;
    int m_UnkownInt6;
    int m_UnkownInt7;
    int m_UnkownInt8;
    byte m_UnkownByte9;

public:
    const string& GetName() const { return m_Name; }
    string& GetName() { return m_Name; }
    void SetName(const string& value) { m_Name = value; }

    const ushort& GetUnknownFlags() const { return m_UnknownFlags; }
    ushort& GetUnknownFlags() { return m_UnknownFlags; }
    void SetUnknownFlags(const ushort& value) { m_UnknownFlags = value; }

    const uint& GetNumUnknownLinks1() const { return m_NumUnknownLinks1; }
    uint& GetNumUnknownLinks1() { return m_NumUnknownLinks1; }
    void SetNumUnknownLinks1(const uint& value) { m_NumUnknownLinks1 = value; }

    const std::vector<Pointer<class NiNode*>>& GetUnknownLinks1() const { return m_UnknownLinks1; }
    std::vector<Pointer<class NiNode*>>& GetUnknownLinks1() { return m_UnknownLinks1; }
    void SetUnknownLinks1(const std::vector<Pointer<class NiNode*>>& value) { m_UnknownLinks1 = value; }

    const int& GetUnkownInt2() const { return m_UnkownInt2; }
    int& GetUnkownInt2() { return m_UnkownInt2; }
    void SetUnkownInt2(const int& value) { m_UnkownInt2 = value; }

    const Pointer<class NiLight*>& GetTarget() const { return m_Target; }
    Pointer<class NiLight*>& GetTarget() { return m_Target; }
    void SetTarget(const Pointer<class NiLight*>& value) { m_Target = value; }

    const float& GetUnkownFloat4() const { return m_UnkownFloat4; }
    float& GetUnkownFloat4() { return m_UnkownFloat4; }
    void SetUnkownFloat4(const float& value) { m_UnkownFloat4 = value; }

    const byte& GetUnkownByte5() const { return m_UnkownByte5; }
    byte& GetUnkownByte5() { return m_UnkownByte5; }
    void SetUnkownByte5(const byte& value) { m_UnkownByte5 = value; }

    const int& GetUnkownInt6() const { return m_UnkownInt6; }
    int& GetUnkownInt6() { return m_UnkownInt6; }
    void SetUnkownInt6(const int& value) { m_UnkownInt6 = value; }

    const int& GetUnkownInt7() const { return m_UnkownInt7; }
    int& GetUnkownInt7() { return m_UnkownInt7; }
    void SetUnkownInt7(const int& value) { m_UnkownInt7 = value; }

    const int& GetUnkownInt8() const { return m_UnkownInt8; }
    int& GetUnkownInt8() { return m_UnkownInt8; }
    void SetUnkownInt8(const int& value) { m_UnkownInt8 = value; }

    const byte& GetUnkownByte9() const { return m_UnkownByte9; }
    byte& GetUnkownByte9() { return m_UnkownByte9; }
    void SetUnkownByte9(const byte& value) { m_UnkownByte9 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
