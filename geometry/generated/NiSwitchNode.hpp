#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiNode.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A node used to switch between branches, such as for LOD levels?
 *         
 */
class NiSwitchNode : public NiNode
{
protected:
    /**
     * Flags
     */
    ushort m_UnknownFlags1;
    /**
     * Index?
     */
    int m_UnknownInt1;

public:
    const ushort& GetUnknownFlags1() const { return m_UnknownFlags1; }
    ushort& GetUnknownFlags1() { return m_UnknownFlags1; }
    void SetUnknownFlags1(const ushort& value) { m_UnknownFlags1 = value; }

    const int& GetUnknownInt1() const { return m_UnknownInt1; }
    int& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const int& value) { m_UnknownInt1 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
