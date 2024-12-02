#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "string.hpp"
#include "NiNode.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


class NiPSPlanarCollider : public NiObject
{
protected:
    string m_Name;
    int m_UnknownInt1;
    int m_UnknownInt2;
    short m_UnknownShort3;
    byte m_UnknownByte4;
    std::vector<float> m_UnknownFloats5;
    Pointer<class NiNode*> m_UnknownLink6;

public:
    const string& GetName() const { return m_Name; }
    string& GetName() { return m_Name; }
    void SetName(const string& value) { m_Name = value; }

    const int& GetUnknownInt1() const { return m_UnknownInt1; }
    int& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const int& value) { m_UnknownInt1 = value; }

    const int& GetUnknownInt2() const { return m_UnknownInt2; }
    int& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const int& value) { m_UnknownInt2 = value; }

    const short& GetUnknownShort3() const { return m_UnknownShort3; }
    short& GetUnknownShort3() { return m_UnknownShort3; }
    void SetUnknownShort3(const short& value) { m_UnknownShort3 = value; }

    const byte& GetUnknownByte4() const { return m_UnknownByte4; }
    byte& GetUnknownByte4() { return m_UnknownByte4; }
    void SetUnknownByte4(const byte& value) { m_UnknownByte4 = value; }

    const std::vector<float>& GetUnknownFloats5() const { return m_UnknownFloats5; }
    std::vector<float>& GetUnknownFloats5() { return m_UnknownFloats5; }
    void SetUnknownFloats5(const std::vector<float>& value) { m_UnknownFloats5 = value; }

    const Pointer<class NiNode*>& GetUnknownLink6() const { return m_UnknownLink6; }
    Pointer<class NiNode*>& GetUnknownLink6() { return m_UnknownLink6; }
    void SetUnknownLink6(const Pointer<class NiNode*>& value) { m_UnknownLink6 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
