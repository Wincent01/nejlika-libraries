#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "BodyPartList.hpp"
#include "NiSkinInstance.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-specific node.
 *         
 */
class BSDismemberSkinInstance : public NiSkinInstance
{
protected:
    /**
     * Unknown
     */
    int m_NumPartitions;
    /**
     * Unknown
     */
    std::vector<BodyPartList> m_Partitions;

public:
    const int& GetNumPartitions() const { return m_NumPartitions; }
    int& GetNumPartitions() { return m_NumPartitions; }
    void SetNumPartitions(const int& value) { m_NumPartitions = value; }

    const std::vector<BodyPartList>& GetPartitions() const { return m_Partitions; }
    std::vector<BodyPartList>& GetPartitions() { return m_Partitions; }
    void SetPartitions(const std::vector<BodyPartList>& value) { m_Partitions = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
