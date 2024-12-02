#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "FurniturePosition.hpp"
#include "NiExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown. Marks furniture sitting positions?
 *         
 */
class BSFurnitureMarker : public NiExtraData
{
protected:
    /**
     * Number of positions.
     */
    uint m_NumPositions;
    /**
     * Unknown. Probably has something to do with the furniture positions?
     */
    std::vector<FurniturePosition> m_Positions;

public:
    const uint& GetNumPositions() const { return m_NumPositions; }
    uint& GetNumPositions() { return m_NumPositions; }
    void SetNumPositions(const uint& value) { m_NumPositions = value; }

    const std::vector<FurniturePosition>& GetPositions() const { return m_Positions; }
    std::vector<FurniturePosition>& GetPositions() { return m_Positions; }
    void SetPositions(const std::vector<FurniturePosition>& value) { m_Positions = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
