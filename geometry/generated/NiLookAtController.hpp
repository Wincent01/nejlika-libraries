#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiNode.hpp"
#include "NiTimeController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown. Start time is 3.4e+38 and stop time is -3.4e+38.
 *         
 */
class NiLookAtController : public NiTimeController
{
protected:
    /**
     * Unknown.
     */
    ushort m_Unknown1;
    /**
     * Link to the node to look at?
     */
    Pointer<class NiNode*> m_LookAtNode;

public:
    const ushort& GetUnknown1() const { return m_Unknown1; }
    ushort& GetUnknown1() { return m_Unknown1; }
    void SetUnknown1(const ushort& value) { m_Unknown1 = value; }

    const Pointer<class NiNode*>& GetLookAtNode() const { return m_LookAtNode; }
    Pointer<class NiNode*>& GetLookAtNode() { return m_LookAtNode; }
    void SetLookAtNode(const Pointer<class NiNode*>& value) { m_LookAtNode = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
