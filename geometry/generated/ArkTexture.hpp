#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "string.hpp"
#include "NiTexturingProperty.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A texture reference used by NiArkTextureExtraData.
 *         
 */
class ArkTexture : public Construct
{
protected:
    string m_TextureName;
    int m_UnknownInt3;
    int m_UnknownInt4;
    Pointer<class NiTexturingProperty*> m_TexturingProperty;
    std::vector<byte> m_UnknownBytes;

public:
    const string& GetTextureName() const { return m_TextureName; }
    string& GetTextureName() { return m_TextureName; }
    void SetTextureName(const string& value) { m_TextureName = value; }

    const int& GetUnknownInt3() const { return m_UnknownInt3; }
    int& GetUnknownInt3() { return m_UnknownInt3; }
    void SetUnknownInt3(const int& value) { m_UnknownInt3 = value; }

    const int& GetUnknownInt4() const { return m_UnknownInt4; }
    int& GetUnknownInt4() { return m_UnknownInt4; }
    void SetUnknownInt4(const int& value) { m_UnknownInt4 = value; }

    const Pointer<class NiTexturingProperty*>& GetTexturingProperty() const { return m_TexturingProperty; }
    Pointer<class NiTexturingProperty*>& GetTexturingProperty() { return m_TexturingProperty; }
    void SetTexturingProperty(const Pointer<class NiTexturingProperty*>& value) { m_TexturingProperty = value; }

    const std::vector<byte>& GetUnknownBytes() const { return m_UnknownBytes; }
    std::vector<byte>& GetUnknownBytes() { return m_UnknownBytes; }
    void SetUnknownBytes(const std::vector<byte>& value) { m_UnknownBytes = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
