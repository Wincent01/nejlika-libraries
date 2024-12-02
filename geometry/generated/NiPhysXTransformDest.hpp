#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiNode.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown PhysX node.
 *         
 */
class NiPhysXTransformDest : public NiObject
{
protected:
    /**
     * Unknown. =1?
     */
    byte m_UnknownByte1;
    /**
     * Unknown. =0
     */
    byte m_UnknownByte2;
    /**
     * Affected node?
     */
    Pointer<class NiNode*> m_Node;

public:
    const byte& GetUnknownByte1() const { return m_UnknownByte1; }
    byte& GetUnknownByte1() { return m_UnknownByte1; }
    void SetUnknownByte1(const byte& value) { m_UnknownByte1 = value; }

    const byte& GetUnknownByte2() const { return m_UnknownByte2; }
    byte& GetUnknownByte2() { return m_UnknownByte2; }
    void SetUnknownByte2(const byte& value) { m_UnknownByte2 = value; }

    const Pointer<class NiNode*>& GetNode() const { return m_Node; }
    Pointer<class NiNode*>& GetNode() { return m_Node; }
    void SetNode(const Pointer<class NiNode*>& value) { m_Node = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
