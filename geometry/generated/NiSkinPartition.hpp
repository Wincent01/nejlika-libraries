#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "SkinPartition.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Skinning data, optimized for hardware skinning. The mesh is partitioned in submeshes such that each vertex of a submesh is influenced only by a limited and fixed number of bones.
 *         
 */
class NiSkinPartition : public NiObject
{
protected:
    /**
     * Unknown.
     */
    uint m_NumSkinPartitionBlocks;
    /**
     * Skin partition objects.
     */
    std::vector<SkinPartition> m_SkinPartitionBlocks;

public:
    const uint& GetNumSkinPartitionBlocks() const { return m_NumSkinPartitionBlocks; }
    uint& GetNumSkinPartitionBlocks() { return m_NumSkinPartitionBlocks; }
    void SetNumSkinPartitionBlocks(const uint& value) { m_NumSkinPartitionBlocks = value; }

    const std::vector<SkinPartition>& GetSkinPartitionBlocks() const { return m_SkinPartitionBlocks; }
    std::vector<SkinPartition>& GetSkinPartitionBlocks() { return m_SkinPartitionBlocks; }
    void SetSkinPartitionBlocks(const std::vector<SkinPartition>& value) { m_SkinPartitionBlocks = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
