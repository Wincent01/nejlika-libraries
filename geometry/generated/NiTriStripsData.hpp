#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiTriBasedGeomData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Holds mesh data using strips of triangles.
 *         
 */
class NiTriStripsData : public NiTriBasedGeomData
{
protected:
    /**
     * Number of OpenGL triangle strips that are present.
     */
    ushort m_NumStrips;
    /**
     * The number of points in each triangle strip.
     */
    std::vector<ushort> m_StripLengths;
    /**
     * Do we have strip point data?
     */
    bool m_HasPoints;
    /**
     * The points in the Triangle strips.  Size is the sum of all entries in Strip Lengths.
     */
    std::vector<std::vector<ushort>> m_Points;

public:
    const ushort& GetNumStrips() const { return m_NumStrips; }
    ushort& GetNumStrips() { return m_NumStrips; }
    void SetNumStrips(const ushort& value) { m_NumStrips = value; }

    const std::vector<ushort>& GetStripLengths() const { return m_StripLengths; }
    std::vector<ushort>& GetStripLengths() { return m_StripLengths; }
    void SetStripLengths(const std::vector<ushort>& value) { m_StripLengths = value; }

    const bool& GetHasPoints() const { return m_HasPoints; }
    bool& GetHasPoints() { return m_HasPoints; }
    void SetHasPoints(const bool& value) { m_HasPoints = value; }

    const std::vector<std::vector<ushort>>& GetPoints() const { return m_Points; }
    std::vector<std::vector<ushort>>& GetPoints() { return m_Points; }
    void SetPoints(const std::vector<std::vector<ushort>>& value) { m_Points = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
