#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "KeyGroup.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Timed boolean data.
 *         
 */
class NiBoolData : public NiObject
{
protected:
    /**
     * The boolean keys.
     */
    KeyGroup<byte> m_Data;

public:
    const KeyGroup<byte>& GetData() const { return m_Data; }
    KeyGroup<byte>& GetData() { return m_Data; }
    void SetData(const KeyGroup<byte>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
