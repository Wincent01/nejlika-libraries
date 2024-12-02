#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Color4.hpp"
#include "NiExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown.
 *         
 */
class NiColorExtraData : public NiExtraData
{
protected:
    /**
     * RGBA Color?
     */
    Color4 m_Data;

public:
    const Color4& GetData() const { return m_Data; }
    Color4& GetData() { return m_Data; }
    void SetData(const Color4& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
