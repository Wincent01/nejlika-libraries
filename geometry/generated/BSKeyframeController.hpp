#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiKeyframeData.hpp"
#include "NiKeyframeController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         An extended keyframe controller.
 *         
 */
class BSKeyframeController : public NiKeyframeController
{
protected:
    /**
     * A link to more keyframe data.
     */
    Pointer<class NiKeyframeData*> m_Data2;

public:
    const Pointer<class NiKeyframeData*>& GetData2() const { return m_Data2; }
    Pointer<class NiKeyframeData*>& GetData2() { return m_Data2; }
    void SetData2(const Pointer<class NiKeyframeData*>& value) { m_Data2 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
