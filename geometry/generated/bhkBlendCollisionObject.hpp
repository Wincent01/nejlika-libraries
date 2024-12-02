#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "bhkCollisionObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown.
 *         
 */
class bhkBlendCollisionObject : public bhkCollisionObject
{
protected:
    /**
     * Blending parameter?
     */
    float m_UnknownFloat1;
    /**
     * Another blending parameter?
     */
    float m_UnknownFloat2;

public:
    const float& GetUnknownFloat1() const { return m_UnknownFloat1; }
    float& GetUnknownFloat1() { return m_UnknownFloat1; }
    void SetUnknownFloat1(const float& value) { m_UnknownFloat1 = value; }

    const float& GetUnknownFloat2() const { return m_UnknownFloat2; }
    float& GetUnknownFloat2() { return m_UnknownFloat2; }
    void SetUnknownFloat2(const float& value) { m_UnknownFloat2 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
