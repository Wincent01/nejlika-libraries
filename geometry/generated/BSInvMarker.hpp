#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *     Orientation marker for Skyrim's inventory view.
 *         How to show the nif in the player's inventory.
 *         Typically attached to the root node of the nif tree.
 *         If not present, then Skyrim will still show the nif in inventory,
 *         using the default values.
 *         Name should be 'INV' (without the quotes).
 *         For rotations, a short of "4712" appears as "4.712" but "959" appears as "0.959"  meshes\weapons\daedric\daedricbowskinned.nif
 *         
 */
class BSInvMarker : public NiExtraData
{
protected:
    ushort m_RotationX;
    ushort m_RotationY;
    ushort m_RotationZ;
    /**
     * Zoom factor.
     */
    float m_Zoom;

public:
    const ushort& GetRotationX() const { return m_RotationX; }
    ushort& GetRotationX() { return m_RotationX; }
    void SetRotationX(const ushort& value) { m_RotationX = value; }

    const ushort& GetRotationY() const { return m_RotationY; }
    ushort& GetRotationY() { return m_RotationY; }
    void SetRotationY(const ushort& value) { m_RotationY = value; }

    const ushort& GetRotationZ() const { return m_RotationZ; }
    ushort& GetRotationZ() { return m_RotationZ; }
    void SetRotationZ(const ushort& value) { m_RotationZ = value; }

    const float& GetZoom() const { return m_Zoom; }
    float& GetZoom() { return m_Zoom; }
    void SetZoom(const float& value) { m_Zoom = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
