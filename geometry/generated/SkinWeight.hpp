#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


/**
 * 
 *         A weighted vertex.
 *         
 */
class SkinWeight : public Construct
{
protected:
    /**
     * The vertex index, in the mesh.
     */
    ushort m_Index;
    /**
     * The vertex weight - between 0.0 and 1.0
     */
    float m_Weight;

public:
    const ushort& GetIndex() const { return m_Index; }
    ushort& GetIndex() { return m_Index; }
    void SetIndex(const ushort& value) { m_Index = value; }

    const float& GetWeight() const { return m_Weight; }
    float& GetWeight() { return m_Weight; }
    void SetWeight(const float& value) { m_Weight = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
