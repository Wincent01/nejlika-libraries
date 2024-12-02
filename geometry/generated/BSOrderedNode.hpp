#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector4.hpp"
#include "NiNode.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-Specific node.
 *         
 */
class BSOrderedNode : public NiNode
{
protected:
    /**
     * Unknown
     */
    Vector4 m_AlphaSortBound;
    /**
     * Unknown
     */
    byte m_IsStaticBound;

public:
    const Vector4& GetAlphaSortBound() const { return m_AlphaSortBound; }
    Vector4& GetAlphaSortBound() { return m_AlphaSortBound; }
    void SetAlphaSortBound(const Vector4& value) { m_AlphaSortBound = value; }

    const byte& GetIsStaticBound() const { return m_IsStaticBound; }
    byte& GetIsStaticBound() { return m_IsStaticBound; }
    void SetIsStaticBound(const byte& value) { m_IsStaticBound = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
