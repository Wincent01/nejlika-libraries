#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "string.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Stores Bone Level of Detail info in a BSBoneLODExtraData
 *         
 */
class BoneLOD : public Construct
{
protected:
    /**
     * Distance to cull?
     */
    uint m_Distance;
    /**
     * The bones name
     */
    string m_BoneName;

public:
    const uint& GetDistance() const { return m_Distance; }
    uint& GetDistance() { return m_Distance; }
    void SetDistance(const uint& value) { m_Distance = value; }

    const string& GetBoneName() const { return m_BoneName; }
    string& GetBoneName() { return m_BoneName; }
    void SetBoneName(const string& value) { m_BoneName = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
