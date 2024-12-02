#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Morph.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Geometry morphing data.
 *         
 */
class NiMorphData : public NiObject
{
protected:
    /**
     * Number of morphing object.
     */
    uint m_NumMorphs;
    /**
     * Number of vertices.
     */
    uint m_NumVertices;
    /**
     * This byte is always 1 in all official files.
     */
    byte m_RelativeTargets;
    /**
     * The geometry morphing objects.
     */
    std::vector<Morph> m_Morphs;

public:
    const uint& GetNumMorphs() const { return m_NumMorphs; }
    uint& GetNumMorphs() { return m_NumMorphs; }
    void SetNumMorphs(const uint& value) { m_NumMorphs = value; }

    const uint& GetNumVertices() const { return m_NumVertices; }
    uint& GetNumVertices() { return m_NumVertices; }
    void SetNumVertices(const uint& value) { m_NumVertices = value; }

    const byte& GetRelativeTargets() const { return m_RelativeTargets; }
    byte& GetRelativeTargets() { return m_RelativeTargets; }
    void SetRelativeTargets(const byte& value) { m_RelativeTargets = value; }

    const std::vector<Morph>& GetMorphs() const { return m_Morphs; }
    std::vector<Morph>& GetMorphs() { return m_Morphs; }
    void SetMorphs(const std::vector<Morph>& value) { m_Morphs = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
