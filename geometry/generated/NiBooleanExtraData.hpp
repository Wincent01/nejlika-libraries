#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Boolean extra data.
 *         
 */
class NiBooleanExtraData : public NiExtraData
{
protected:
    /**
     * The boolean extra data value.
     */
    byte m_BooleanData;

public:
    const byte& GetBooleanData() const { return m_BooleanData; }
    byte& GetBooleanData() { return m_BooleanData; }
    void SetBooleanData(const byte& value) { m_BooleanData = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
