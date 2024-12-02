#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "KeyGroup.hpp"
#include "Color4.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Color data for material color controller.
 *         
 */
class NiColorData : public NiObject
{
protected:
    /**
     * The color keys.
     */
    KeyGroup<Color4> m_Data;

public:
    const KeyGroup<Color4>& GetData() const { return m_Data; }
    KeyGroup<Color4>& GetData() { return m_Data; }
    void SetData(const KeyGroup<Color4>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
