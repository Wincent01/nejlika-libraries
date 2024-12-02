#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "TexType.hpp"
#include "TexTransform.hpp"
#include "NiFloatData.hpp"
#include "NiFloatInterpController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Texture transformation controller. The target texture slot should have "Has Texture Transform" enabled.
 *         
 */
class NiTextureTransformController : public NiFloatInterpController
{
protected:
    /**
     * Unknown.
     */
    byte m_Unknown2;
    /**
     *  The target texture slot.
     */
    TexType m_TextureSlot;
    /**
     * Determines how this controller animates the UV Coordinates.
     */
    TexTransform m_Operation;
    /**
     * Link to NiFloatData.
     */
    Pointer<class NiFloatData*> m_Data;

public:
    const byte& GetUnknown2() const { return m_Unknown2; }
    byte& GetUnknown2() { return m_Unknown2; }
    void SetUnknown2(const byte& value) { m_Unknown2 = value; }

    const TexType& GetTextureSlot() const { return m_TextureSlot; }
    TexType& GetTextureSlot() { return m_TextureSlot; }
    void SetTextureSlot(const TexType& value) { m_TextureSlot = value; }

    const TexTransform& GetOperation() const { return m_Operation; }
    TexTransform& GetOperation() { return m_Operation; }
    void SetOperation(const TexTransform& value) { m_Operation = value; }

    const Pointer<class NiFloatData*>& GetData() const { return m_Data; }
    Pointer<class NiFloatData*>& GetData() { return m_Data; }
    void SetData(const Pointer<class NiFloatData*>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
