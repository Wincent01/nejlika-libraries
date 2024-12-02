#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "BillboardMode.hpp"
#include "NiNode.hpp"
namespace nejlika::geometry {


/**
 * 
 *         These nodes will always be rotated to face the camera creating a billboard effect for any attached objects.
 * 
 *         In pre-10.1.0.0 the Flags field is used for BillboardMode.
 *         Bit 0: hidden
 *         Bits 1-2: collision mode
 *         Bit 3: unknown (set in most official meshes)
 *         Bits 5-6: billboard mode
 * 
 *         Collision modes:
 *         00 NONE
 *         01 USE_TRIANGLES
 *         10 USE_OBBS
 *         11 CONTINUE
 * 
 *         Billboard modes:
 *         00 ALWAYS_FACE_CAMERA
 *         01 ROTATE_ABOUT_UP
 *         10 RIGID_FACE_CAMERA
 *         11 ALWAYS_FACE_CENTER
 *         
 */
class NiBillboardNode : public NiNode
{
protected:
    /**
     * The way the billboard will react to the camera.
     */
    BillboardMode m_BillboardMode;

public:
    const BillboardMode& GetBillboardMode() const { return m_BillboardMode; }
    BillboardMode& GetBillboardMode() { return m_BillboardMode; }
    void SetBillboardMode(const BillboardMode& value) { m_BillboardMode = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
