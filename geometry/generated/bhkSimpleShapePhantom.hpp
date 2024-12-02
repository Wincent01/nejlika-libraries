#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "bhkShapePhantom.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown shape.
 *         
 */
class bhkSimpleShapePhantom : public bhkShapePhantom
{
protected:
    /**
     * Unknown.
     */
    std::vector<float> m_UnkownFloats;
    /**
     * Unknown. (1,0,0,0,0) x 3.
     */
    std::vector<std::vector<float>> m_UnknownFloats2;
    /**
     * Unknown.
     */
    float m_UnknownFloat;

public:
    const std::vector<float>& GetUnkownFloats() const { return m_UnkownFloats; }
    std::vector<float>& GetUnkownFloats() { return m_UnkownFloats; }
    void SetUnkownFloats(const std::vector<float>& value) { m_UnkownFloats = value; }

    const std::vector<std::vector<float>>& GetUnknownFloats2() const { return m_UnknownFloats2; }
    std::vector<std::vector<float>>& GetUnknownFloats2() { return m_UnknownFloats2; }
    void SetUnknownFloats2(const std::vector<std::vector<float>>& value) { m_UnknownFloats2 = value; }

    const float& GetUnknownFloat() const { return m_UnknownFloat; }
    float& GetUnknownFloat() { return m_UnknownFloat; }
    void SetUnknownFloat(const float& value) { m_UnknownFloat = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
