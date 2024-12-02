#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "bhkConvexShape.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A box.
 *         
 */
class bhkBoxShape : public bhkConvexShape
{
protected:
    /**
     * Unknown.
     */
    std::vector<byte> m_Unknown8Bytes;
    /**
     * Looks like this could be the box size.
     */
    Vector3 m_Dimensions;
    /**
     * The smallest of the three sizes. Might be used for optimization.
     */
    float m_MinimumSize;

public:
    const std::vector<byte>& GetUnknown8Bytes() const { return m_Unknown8Bytes; }
    std::vector<byte>& GetUnknown8Bytes() { return m_Unknown8Bytes; }
    void SetUnknown8Bytes(const std::vector<byte>& value) { m_Unknown8Bytes = value; }

    const Vector3& GetDimensions() const { return m_Dimensions; }
    Vector3& GetDimensions() { return m_Dimensions; }
    void SetDimensions(const Vector3& value) { m_Dimensions = value; }

    const float& GetMinimumSize() const { return m_MinimumSize; }
    float& GetMinimumSize() { return m_MinimumSize; }
    void SetMinimumSize(const float& value) { m_MinimumSize = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
