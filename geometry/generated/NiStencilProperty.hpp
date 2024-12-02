#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "StencilCompareMode.hpp"
#include "StencilAction.hpp"
#include "StencilAction.hpp"
#include "StencilAction.hpp"
#include "FaceDrawMode.hpp"
#include "NiProperty.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Allows control of stencil testing.
 *         
 */
class NiStencilProperty : public NiProperty
{
protected:
    /**
     * Property flags.
     */
    Flags m_Flags;
    /**
     * Enables or disables the stencil test.
     */
    byte m_StencilEnabled;
    /**
     * Selects the compare mode function (see: glStencilFunc).
     */
    StencilCompareMode m_StencilFunction;
    /**
     * Unknown.  Default is 0.
     */
    uint m_StencilRef;
    /**
     * A bit mask. The default is 0xffffffff.
     */
    uint m_StencilMask;
    StencilAction m_FailAction;
    StencilAction m_ZFailAction;
    StencilAction m_PassAction;
    /**
     * Used to enabled double sided faces. Default is 3 (DRAW_BOTH).
     */
    FaceDrawMode m_DrawMode;

public:
    const Flags& GetFlags() const { return m_Flags; }
    Flags& GetFlags() { return m_Flags; }
    void SetFlags(const Flags& value) { m_Flags = value; }

    const byte& GetStencilEnabled() const { return m_StencilEnabled; }
    byte& GetStencilEnabled() { return m_StencilEnabled; }
    void SetStencilEnabled(const byte& value) { m_StencilEnabled = value; }

    const StencilCompareMode& GetStencilFunction() const { return m_StencilFunction; }
    StencilCompareMode& GetStencilFunction() { return m_StencilFunction; }
    void SetStencilFunction(const StencilCompareMode& value) { m_StencilFunction = value; }

    const uint& GetStencilRef() const { return m_StencilRef; }
    uint& GetStencilRef() { return m_StencilRef; }
    void SetStencilRef(const uint& value) { m_StencilRef = value; }

    const uint& GetStencilMask() const { return m_StencilMask; }
    uint& GetStencilMask() { return m_StencilMask; }
    void SetStencilMask(const uint& value) { m_StencilMask = value; }

    const StencilAction& GetFailAction() const { return m_FailAction; }
    StencilAction& GetFailAction() { return m_FailAction; }
    void SetFailAction(const StencilAction& value) { m_FailAction = value; }

    const StencilAction& GetZFailAction() const { return m_ZFailAction; }
    StencilAction& GetZFailAction() { return m_ZFailAction; }
    void SetZFailAction(const StencilAction& value) { m_ZFailAction = value; }

    const StencilAction& GetPassAction() const { return m_PassAction; }
    StencilAction& GetPassAction() { return m_PassAction; }
    void SetPassAction(const StencilAction& value) { m_PassAction = value; }

    const FaceDrawMode& GetDrawMode() const { return m_DrawMode; }
    FaceDrawMode& GetDrawMode() { return m_DrawMode; }
    void SetDrawMode(const FaceDrawMode& value) { m_DrawMode = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
