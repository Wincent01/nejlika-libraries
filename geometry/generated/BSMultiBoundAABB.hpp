#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "Vector3.hpp"
#include "BSMultiBoundData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-specific node.
 *         
 */
class BSMultiBoundAABB : public BSMultiBoundData
{
protected:
    /**
     * Position of the AABB's center
     */
    Vector3 m_Position;
    /**
     * Extent of the AABB in all directions
     */
    Vector3 m_Extent;

public:
    const Vector3& GetPosition() const { return m_Position; }
    Vector3& GetPosition() { return m_Position; }
    void SetPosition(const Vector3& value) { m_Position = value; }

    const Vector3& GetExtent() const { return m_Extent; }
    Vector3& GetExtent() { return m_Extent; }
    void SetExtent(const Vector3& value) { m_Extent = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
