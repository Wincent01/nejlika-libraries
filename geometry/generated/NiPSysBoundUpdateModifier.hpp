#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPSysModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown particle system modifier.
 *         
 */
class NiPSysBoundUpdateModifier : public NiPSysModifier
{
protected:
    /**
     * Unknown.
     */
    ushort m_UpdateSkip;

public:
    const ushort& GetUpdateSkip() const { return m_UpdateSkip; }
    ushort& GetUpdateSkip() { return m_UpdateSkip; }
    void SetUpdateSkip(const ushort& value) { m_UpdateSkip = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
