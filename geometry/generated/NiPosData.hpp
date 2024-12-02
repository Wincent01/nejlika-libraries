#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "KeyGroup.hpp"
#include "Vector3.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Position data.
 *         
 */
class NiPosData : public NiObject
{
protected:
    /**
     * The position keys.
     */
    KeyGroup<Vector3> m_Data;

public:
    const KeyGroup<Vector3>& GetData() const { return m_Data; }
    KeyGroup<Vector3>& GetData() { return m_Data; }
    void SetData(const KeyGroup<Vector3>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
