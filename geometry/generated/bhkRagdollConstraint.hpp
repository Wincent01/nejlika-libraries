#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "RagdollDescriptor.hpp"
#include "bhkConstraint.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Ragdoll constraint.
 *         
 */
class bhkRagdollConstraint : public bhkConstraint
{
protected:
    /**
     * Ragdoll constraint.
     */
    RagdollDescriptor m_Ragdoll;

public:
    const RagdollDescriptor& GetRagdoll() const { return m_Ragdoll; }
    RagdollDescriptor& GetRagdoll() { return m_Ragdoll; }
    void SetRagdoll(const RagdollDescriptor& value) { m_Ragdoll = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
