#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiKeyframeData.hpp"
#include "NiSingleInterpController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A time controller object for animation key frames.
 *         
 */
class NiKeyframeController : public NiSingleInterpController
{
protected:
    /**
     * Keyframe controller data index.
     */
    Pointer<class NiKeyframeData*> m_Data;

public:
    const Pointer<class NiKeyframeData*>& GetData() const { return m_Data; }
    Pointer<class NiKeyframeData*>& GetData() { return m_Data; }
    void SetData(const Pointer<class NiKeyframeData*>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
