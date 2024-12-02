#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "bhkEntity.hpp"
#include "bhkSerializable.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Describes a physical constraint.
 *         
 */
class bhkConstraint : public bhkSerializable
{
protected:
    /**
     * Number of bodies affected by this constraint.
     */
    uint m_NumEntities;
    /**
     * The entities affected by this constraint.
     */
    std::vector<Pointer<class bhkEntity*>> m_Entities;
    /**
     * Usually 1. Higher values indicate higher priority of this constraint?
     */
    uint m_Priority;

public:
    const uint& GetNumEntities() const { return m_NumEntities; }
    uint& GetNumEntities() { return m_NumEntities; }
    void SetNumEntities(const uint& value) { m_NumEntities = value; }

    const std::vector<Pointer<class bhkEntity*>>& GetEntities() const { return m_Entities; }
    std::vector<Pointer<class bhkEntity*>>& GetEntities() { return m_Entities; }
    void SetEntities(const std::vector<Pointer<class bhkEntity*>>& value) { m_Entities = value; }

    const uint& GetPriority() const { return m_Priority; }
    uint& GetPriority() { return m_Priority; }
    void SetPriority(const uint& value) { m_Priority = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
