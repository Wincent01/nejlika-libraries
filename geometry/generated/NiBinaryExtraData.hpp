#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "ByteArray.hpp"
#include "NiExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Binary extra data object. Used to store tangents and bitangents in Oblivion.
 *         
 */
class NiBinaryExtraData : public NiExtraData
{
protected:
    /**
     * The binary data.
     */
    ByteArray m_BinaryData;

public:
    const ByteArray& GetBinaryData() const { return m_BinaryData; }
    ByteArray& GetBinaryData() { return m_BinaryData; }
    void SetBinaryData(const ByteArray& value) { m_BinaryData = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
