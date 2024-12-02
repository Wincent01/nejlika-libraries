#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "BoneLOD.hpp"
#include "NiExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *     Unknown
 * 		
 */
class BSBoneLODExtraData : public NiExtraData
{
protected:
    /**
     * Number of bone entries
     */
    uint m_BoneLODCount;
    /**
     * Bone Entry
     */
    std::vector<BoneLOD> m_BoneLODInfo;

public:
    const uint& GetBoneLODCount() const { return m_BoneLODCount; }
    uint& GetBoneLODCount() { return m_BoneLODCount; }
    void SetBoneLODCount(const uint& value) { m_BoneLODCount = value; }

    const std::vector<BoneLOD>& GetBoneLODInfo() const { return m_BoneLODInfo; }
    std::vector<BoneLOD>& GetBoneLODInfo() { return m_BoneLODInfo; }
    void SetBoneLODInfo(const std::vector<BoneLOD>& value) { m_BoneLODInfo = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
