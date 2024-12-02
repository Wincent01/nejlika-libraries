#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "BSPartFlag.hpp"
#include "BSDismemberBodyPartType.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Body part list for DismemberSkinInstance
 *         
 */
class BodyPartList : public Construct
{
protected:
    /**
     * Flags related to the Body Partition
     */
    BSPartFlag m_PartFlag;
    /**
     * Body Part Index
     */
    BSDismemberBodyPartType m_BodyPart;

public:
    const BSPartFlag& GetPartFlag() const { return m_PartFlag; }
    BSPartFlag& GetPartFlag() { return m_PartFlag; }
    void SetPartFlag(const BSPartFlag& value) { m_PartFlag = value; }

    const BSDismemberBodyPartType& GetBodyPart() const { return m_BodyPart; }
    BSDismemberBodyPartType& GetBodyPart() { return m_BodyPart; }
    void SetBodyPart(const BSDismemberBodyPartType& value) { m_BodyPart = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
