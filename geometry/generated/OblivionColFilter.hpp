#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "OblivionLayer.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Oblivion's ColFilter property for Havok.
 *         
 */
class OblivionColFilter : public Construct
{
protected:
    /**
     * Sets mesh color in Oblivion Construction Set.
     */
    OblivionLayer m_Layer;
    /**
     * The first bit sets the LINK property and controls whether this body is physically linked to others. The next bit turns collision off. Then, the next bit sets the SCALED property in Oblivion. The next five bits make up the number of this part in a linked body list.
     */
    byte m_ColFilter;
    /**
     * Unknown.
     */
    ushort m_UnknownShort;

public:
    const OblivionLayer& GetLayer() const { return m_Layer; }
    OblivionLayer& GetLayer() { return m_Layer; }
    void SetLayer(const OblivionLayer& value) { m_Layer = value; }

    const byte& GetColFilter() const { return m_ColFilter; }
    byte& GetColFilter() { return m_ColFilter; }
    void SetColFilter(const byte& value) { m_ColFilter = value; }

    const ushort& GetUnknownShort() const { return m_UnknownShort; }
    ushort& GetUnknownShort() { return m_UnknownShort; }
    void SetUnknownShort(const ushort& value) { m_UnknownShort = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
