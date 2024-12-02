#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "KeyGroup.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Texture coordinate data.
 *         
 */
class NiUVData : public NiObject
{
protected:
    /**
     * 
     *             Four UV data groups. Appear to be U translation, V translation, U scaling/tiling, V scaling/tiling.
     *         
     */
    std::vector<KeyGroup<float>> m_UVGroups;

public:
    const std::vector<KeyGroup<float>>& GetUVGroups() const { return m_UVGroups; }
    std::vector<KeyGroup<float>>& GetUVGroups() { return m_UVGroups; }
    void SetUVGroups(const std::vector<KeyGroup<float>>& value) { m_UVGroups = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
