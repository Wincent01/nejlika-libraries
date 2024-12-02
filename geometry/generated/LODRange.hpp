#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


/**
 * 
 *         The distance range where a specific level of detail applies.
 *         
 */
class LODRange : public Construct
{
protected:
    /**
     * Begining of range.
     */
    float m_NearExtent;
    /**
     * End of Range.
     */
    float m_FarExtent;
    /**
     * Unknown (0,0,0).
     */
    std::vector<uint> m_UnknownInts;

public:
    const float& GetNearExtent() const { return m_NearExtent; }
    float& GetNearExtent() { return m_NearExtent; }
    void SetNearExtent(const float& value) { m_NearExtent = value; }

    const float& GetFarExtent() const { return m_FarExtent; }
    float& GetFarExtent() { return m_FarExtent; }
    void SetFarExtent(const float& value) { m_FarExtent = value; }

    const std::vector<uint>& GetUnknownInts() const { return m_UnknownInts; }
    std::vector<uint>& GetUnknownInts() { return m_UnknownInts; }
    void SetUnknownInts(const std::vector<uint>& value) { m_UnknownInts = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
