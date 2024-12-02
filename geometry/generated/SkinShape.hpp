#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiTriBasedGeom.hpp"
#include "NiSkinInstance.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Reference to shape and skin instance.
 *         
 */
class SkinShape : public Construct
{
protected:
    /**
     * The shape.
     */
    Pointer<class NiTriBasedGeom*> m_Shape;
    /**
     * Skinning instance for the shape?
     */
    Pointer<class NiSkinInstance*> m_SkinInstance;

public:
    const Pointer<class NiTriBasedGeom*>& GetShape() const { return m_Shape; }
    Pointer<class NiTriBasedGeom*>& GetShape() { return m_Shape; }
    void SetShape(const Pointer<class NiTriBasedGeom*>& value) { m_Shape = value; }

    const Pointer<class NiSkinInstance*>& GetSkinInstance() const { return m_SkinInstance; }
    Pointer<class NiSkinInstance*>& GetSkinInstance() { return m_SkinInstance; }
    void SetSkinInstance(const Pointer<class NiSkinInstance*>& value) { m_SkinInstance = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
