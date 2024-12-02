#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "BSMultiBound.hpp"
#include "NiNode.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-specific node.
 *         
 */
class BSMultiBoundNode : public NiNode
{
protected:
    /**
     * Unknown.
     */
    Pointer<class BSMultiBound*> m_MultiBound;
    /**
     * Unknown
     */
    uint m_UnknownInt;

public:
    const Pointer<class BSMultiBound*>& GetMultiBound() const { return m_MultiBound; }
    Pointer<class BSMultiBound*>& GetMultiBound() { return m_MultiBound; }
    void SetMultiBound(const Pointer<class BSMultiBound*>& value) { m_MultiBound = value; }

    const uint& GetUnknownInt() const { return m_UnknownInt; }
    uint& GetUnknownInt() { return m_UnknownInt; }
    void SetUnknownInt(const uint& value) { m_UnknownInt = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
