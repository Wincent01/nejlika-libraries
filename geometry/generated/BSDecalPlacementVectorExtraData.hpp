#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "DecalVectorArray.hpp"
#include "NiExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-specific node. (for dynamic decal projection?)
 *         
 */
class BSDecalPlacementVectorExtraData : public NiExtraData
{
protected:
    /**
     * Unknown
     */
    float m_UnknownFloat1;
    /**
     * Number of groups
     */
    short m_NumVectorBlocks;
    /**
     * Number of Blocks
     */
    std::vector<DecalVectorArray> m_VectorBlocks;

public:
    const float& GetUnknownFloat1() const { return m_UnknownFloat1; }
    float& GetUnknownFloat1() { return m_UnknownFloat1; }
    void SetUnknownFloat1(const float& value) { m_UnknownFloat1 = value; }

    const short& GetNumVectorBlocks() const { return m_NumVectorBlocks; }
    short& GetNumVectorBlocks() { return m_NumVectorBlocks; }
    void SetNumVectorBlocks(const short& value) { m_NumVectorBlocks = value; }

    const std::vector<DecalVectorArray>& GetVectorBlocks() const { return m_VectorBlocks; }
    std::vector<DecalVectorArray>& GetVectorBlocks() { return m_VectorBlocks; }
    void SetVectorBlocks(const std::vector<DecalVectorArray>& value) { m_VectorBlocks = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
