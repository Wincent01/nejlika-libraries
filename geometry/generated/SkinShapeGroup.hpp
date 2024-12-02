#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "SkinShape.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown.
 *         
 */
class SkinShapeGroup : public Construct
{
protected:
    /**
     * Counts unknown.
     */
    uint m_NumLinkPairs;
    /**
     * 
     *             First link is a NiTriShape object.
     *             Second link is a NiSkinInstance object.
     *         
     */
    std::vector<SkinShape> m_LinkPairs;

public:
    const uint& GetNumLinkPairs() const { return m_NumLinkPairs; }
    uint& GetNumLinkPairs() { return m_NumLinkPairs; }
    void SetNumLinkPairs(const uint& value) { m_NumLinkPairs = value; }

    const std::vector<SkinShape>& GetLinkPairs() const { return m_LinkPairs; }
    std::vector<SkinShape>& GetLinkPairs() { return m_LinkPairs; }
    void SetLinkPairs(const std::vector<SkinShape>& value) { m_LinkPairs = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
