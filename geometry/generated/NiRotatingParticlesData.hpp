#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Quaternion.hpp"
#include "NiParticlesData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Rotating particles data object.
 *         
 */
class NiRotatingParticlesData : public NiParticlesData
{
protected:
    /**
     * Is the particle rotation array present?
     */
    bool m_HasRotations2;
    /**
     * The individual particle rotations.
     */
    std::vector<Quaternion> m_Rotations2;

public:
    const bool& GetHasRotations2() const { return m_HasRotations2; }
    bool& GetHasRotations2() { return m_HasRotations2; }
    void SetHasRotations2(const bool& value) { m_HasRotations2 = value; }

    const std::vector<Quaternion>& GetRotations2() const { return m_Rotations2; }
    std::vector<Quaternion>& GetRotations2() { return m_Rotations2; }
    void SetRotations2(const std::vector<Quaternion>& value) { m_Rotations2 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
