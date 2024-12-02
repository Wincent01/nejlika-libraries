#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "KeyGroup.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Possibly the 1D position along a 3D path.
 *         
 */
class NiFloatData : public NiObject
{
protected:
    /**
     * The keys.
     */
    KeyGroup<float> m_Data;

public:
    const KeyGroup<float>& GetData() const { return m_Data; }
    KeyGroup<float>& GetData() { return m_Data; }
    void SetData(const KeyGroup<float>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
