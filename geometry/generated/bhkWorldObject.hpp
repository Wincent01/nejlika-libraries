#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "bhkShape.hpp"
#include "OblivionLayer.hpp"
#include "SkyrimLayer.hpp"
#include "bhkSerializable.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Havok objects that have a position in the world?
 *         
 */
class bhkWorldObject : public bhkSerializable
{
protected:
    /**
     *  Link to the body for this collision object.
     */
    Pointer<class bhkShape*> m_Shape;
    /**
     * Sets mesh color in Oblivion Construction Set.
     */
    OblivionLayer m_Layer;
    /**
     * The first bit sets the LINK property and controls whether this body is physically linked to others. The next bit turns collision off. Then, the next bit sets the SCALED property in Oblivion. The next five bits make up the number of this part in a linked body list.
     */
    byte m_ColFilter;
    /**
     * Physical purpose of collision object? The setting affects objetct's havok behavior in game.
     */
    SkyrimLayer m_SkyrimLayer;
    /**
     * FLAGS are stored in highest 3 bits:
     *         	Bit 7: sets the LINK property and controls whether this body is physically linked to others.
     *         	Bit 6: turns collision off (not used for Layer SKYL_BIPED).
     *         	Bit 5: sets the SCALED property.
     * 
     *         	PART NUMBER in a linked body list is stored in lowest 5 bits (used only when Skyrim Layer is set to SKYL_BIPED):
     *         	0 - OTHER
     *         	1 - HEAD
     *         	2 - BODY
     *         	3 - SPINE1
     *         	4 - SPINE2
     *         	5 - LUPPERARM
     *         	6 - LFOREARM
     *         	7 - LHAND
     *         	8 - LTHIGH
     *         	9 - LCALF
     *         	10 - LFOOT
     *         	11 - RUPPERARM
     *         	12 - RFOREARM
     *         	13 - RHAND
     *         	14 - RTHIGH
     *         	15 - RCALF
     *         	16 - RFOOT
     *         	17 - TAIL
     *         	18 - SHIELD
     *         	19 - QUIVER
     *         	20 - WEAPON
     *         	21 - PONYTAIL
     *         	22 - WING
     *         	23 - PACK
     *         	24 - CHAIN
     *         	25 - ADDONHEAD
     *         	26 - ADDONCHEST
     *         	27 - ADDONARM
     *         	28 - ADDONLEG
     *         	29-31 - NULL
     *         
     */
    byte m_FlagsAndPartNumber;
    /**
     * Unknown.
     */
    ushort m_UnknownShort;

public:
    const Pointer<class bhkShape*>& GetShape() const { return m_Shape; }
    Pointer<class bhkShape*>& GetShape() { return m_Shape; }
    void SetShape(const Pointer<class bhkShape*>& value) { m_Shape = value; }

    const OblivionLayer& GetLayer() const { return m_Layer; }
    OblivionLayer& GetLayer() { return m_Layer; }
    void SetLayer(const OblivionLayer& value) { m_Layer = value; }

    const byte& GetColFilter() const { return m_ColFilter; }
    byte& GetColFilter() { return m_ColFilter; }
    void SetColFilter(const byte& value) { m_ColFilter = value; }

    const SkyrimLayer& GetSkyrimLayer() const { return m_SkyrimLayer; }
    SkyrimLayer& GetSkyrimLayer() { return m_SkyrimLayer; }
    void SetSkyrimLayer(const SkyrimLayer& value) { m_SkyrimLayer = value; }

    const byte& GetFlagsAndPartNumber() const { return m_FlagsAndPartNumber; }
    byte& GetFlagsAndPartNumber() { return m_FlagsAndPartNumber; }
    void SetFlagsAndPartNumber(const byte& value) { m_FlagsAndPartNumber = value; }

    const ushort& GetUnknownShort() const { return m_UnknownShort; }
    ushort& GetUnknownShort() { return m_UnknownShort; }
    void SetUnknownShort(const ushort& value) { m_UnknownShort = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
