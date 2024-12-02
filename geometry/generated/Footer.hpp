#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         The NIF file footer.
 *         
 */
class Footer : public Construct
{
protected:
    /**
     * The number of root references.
     */
    uint m_NumRoots;
    /**
     * List of root NIF objects. If there is a camera, for 1st person view, then this NIF object is referred to as well in this list, even if it is not a root object (usually we want the camera to be attached to the Bip Head node).
     */
    std::vector<Pointer<class NiObject*>> m_Roots;

public:
    const uint& GetNumRoots() const { return m_NumRoots; }
    uint& GetNumRoots() { return m_NumRoots; }
    void SetNumRoots(const uint& value) { m_NumRoots = value; }

    const std::vector<Pointer<class NiObject*>>& GetRoots() const { return m_Roots; }
    std::vector<Pointer<class NiObject*>>& GetRoots() { return m_Roots; }
    void SetRoots(const std::vector<Pointer<class NiObject*>>& value) { m_Roots = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
