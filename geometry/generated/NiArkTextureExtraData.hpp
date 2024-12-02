#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "ArkTexture.hpp"
#include "NiExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown node.
 *         
 */
class NiArkTextureExtraData : public NiExtraData
{
protected:
    std::vector<int> m_UnknownInts1;
    byte m_UnknownByte;
    int m_UnknownInt2;
    int m_NumTextures;
    std::vector<ArkTexture> m_Textures;

public:
    const std::vector<int>& GetUnknownInts1() const { return m_UnknownInts1; }
    std::vector<int>& GetUnknownInts1() { return m_UnknownInts1; }
    void SetUnknownInts1(const std::vector<int>& value) { m_UnknownInts1 = value; }

    const byte& GetUnknownByte() const { return m_UnknownByte; }
    byte& GetUnknownByte() { return m_UnknownByte; }
    void SetUnknownByte(const byte& value) { m_UnknownByte = value; }

    const int& GetUnknownInt2() const { return m_UnknownInt2; }
    int& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const int& value) { m_UnknownInt2 = value; }

    const int& GetNumTextures() const { return m_NumTextures; }
    int& GetNumTextures() { return m_NumTextures; }
    void SetNumTextures(const int& value) { m_NumTextures = value; }

    const std::vector<ArkTexture>& GetTextures() const { return m_Textures; }
    std::vector<ArkTexture>& GetTextures() { return m_Textures; }
    void SetTextures(const std::vector<ArkTexture>& value) { m_Textures = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
