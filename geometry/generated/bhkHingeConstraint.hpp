#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "HingeDescriptor.hpp"
#include "bhkConstraint.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A hinge constraint.
 *         
 */
class bhkHingeConstraint : public bhkConstraint
{
protected:
    /**
     * Hinge constraing.
     */
    HingeDescriptor m_Hinge;

public:
    const HingeDescriptor& GetHinge() const { return m_Hinge; }
    HingeDescriptor& GetHinge() { return m_Hinge; }
    void SetHinge(const HingeDescriptor& value) { m_Hinge = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
