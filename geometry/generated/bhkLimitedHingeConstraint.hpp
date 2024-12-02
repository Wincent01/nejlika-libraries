#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "LimitedHingeDescriptor.hpp"
#include "bhkConstraint.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Hinge constraint.
 *         
 */
class bhkLimitedHingeConstraint : public bhkConstraint
{
protected:
    /**
     * Describes a limited hinge constraint
     */
    LimitedHingeDescriptor m_LimitedHinge;

public:
    const LimitedHingeDescriptor& GetLimitedHinge() const { return m_LimitedHinge; }
    LimitedHingeDescriptor& GetLimitedHinge() { return m_LimitedHinge; }
    void SetLimitedHinge(const LimitedHingeDescriptor& value) { m_LimitedHinge = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
