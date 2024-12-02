#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "BSSegment.hpp"
#include "NiTriShape.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-specific node.
 *         
 */
class BSSegmentedTriShape : public NiTriShape
{
protected:
    /**
     * Number of segments in the square grid
     */
    int m_NumSegments;
    /**
     * Configuration of each segment
     */
    std::vector<BSSegment> m_Segment;

public:
    const int& GetNumSegments() const { return m_NumSegments; }
    int& GetNumSegments() { return m_NumSegments; }
    void SetNumSegments(const int& value) { m_NumSegments = value; }

    const std::vector<BSSegment>& GetSegment() const { return m_Segment; }
    std::vector<BSSegment>& GetSegment() { return m_Segment; }
    void SetSegment(const std::vector<BSSegment>& value) { m_Segment = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
