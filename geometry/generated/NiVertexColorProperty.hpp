#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "VertMode.hpp"
#include "LightMode.hpp"
#include "NiProperty.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Property of vertex colors. This object is referred to by the root object of the NIF file whenever some NiTriShapeData object has vertex colors with non-default settings; if not present, vertex colors have vertex_mode=2 and lighting_mode=1.
 *         
 */
class NiVertexColorProperty : public NiProperty
{
protected:
    /**
     * 
     *             Property flags. Appears to be unused until 20.1.0.3.
     * 
     *             Bits 0-2: Unknown
     *             Bit 3: Lighting Mode?
     *             Bits 4-5: Vertex Mode?
     *         
     */
    Flags m_Flags;
    /**
     * 
     *             Determines how vertex and material colors are mixed.
     *             related gl function: glColorMaterial
     *             In Flags from version 20.1.0.3 onwards.
     *         
     */
    VertMode m_VertexMode;
    /**
     * The light mode. In Flags from 20.1.0.3 on.
     */
    LightMode m_LightingMode;

public:
    const Flags& GetFlags() const { return m_Flags; }
    Flags& GetFlags() { return m_Flags; }
    void SetFlags(const Flags& value) { m_Flags = value; }

    const VertMode& GetVertexMode() const { return m_VertexMode; }
    VertMode& GetVertexMode() { return m_VertexMode; }
    void SetVertexMode(const VertMode& value) { m_VertexMode = value; }

    const LightMode& GetLightingMode() const { return m_LightingMode; }
    LightMode& GetLightingMode() { return m_LightingMode; }
    void SetLightingMode(const LightMode& value) { m_LightingMode = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
