#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiNode.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


class CStreamableAssetData : public NiObject
{
protected:
    Pointer<class NiNode*> m_Root;
    std::vector<byte> m_UnknownBytes;

public:
    const Pointer<class NiNode*>& GetRoot() const { return m_Root; }
    Pointer<class NiNode*>& GetRoot() { return m_Root; }
    void SetRoot(const Pointer<class NiNode*>& value) { m_Root = value; }

    const std::vector<byte>& GetUnknownBytes() const { return m_UnknownBytes; }
    std::vector<byte>& GetUnknownBytes() { return m_UnknownBytes; }
    void SetUnknownBytes(const std::vector<byte>& value) { m_UnknownBytes = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
