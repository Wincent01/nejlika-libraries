#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiNode.hpp"
#include "NiPSysData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle meshes data.
 *         
 */
class NiMeshPSysData : public NiPSysData
{
protected:
    /**
     * Unknown. Possible vertex count but probably not.
     */
    uint m_UnknownInt2;
    /**
     * Unknown. 0?
     */
    byte m_UnknownByte3;
    /**
     * Unknown.
     */
    uint m_NumUnknownInts1;
    /**
     * Unknown integers
     */
    std::vector<uint> m_UnknownInts1;
    /**
     * Unknown NiNode.
     */
    Pointer<class NiNode*> m_UnknownNode;

public:
    const uint& GetUnknownInt2() const { return m_UnknownInt2; }
    uint& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const uint& value) { m_UnknownInt2 = value; }

    const byte& GetUnknownByte3() const { return m_UnknownByte3; }
    byte& GetUnknownByte3() { return m_UnknownByte3; }
    void SetUnknownByte3(const byte& value) { m_UnknownByte3 = value; }

    const uint& GetNumUnknownInts1() const { return m_NumUnknownInts1; }
    uint& GetNumUnknownInts1() { return m_NumUnknownInts1; }
    void SetNumUnknownInts1(const uint& value) { m_NumUnknownInts1 = value; }

    const std::vector<uint>& GetUnknownInts1() const { return m_UnknownInts1; }
    std::vector<uint>& GetUnknownInts1() { return m_UnknownInts1; }
    void SetUnknownInts1(const std::vector<uint>& value) { m_UnknownInts1 = value; }

    const Pointer<class NiNode*>& GetUnknownNode() const { return m_UnknownNode; }
    Pointer<class NiNode*>& GetUnknownNode() { return m_UnknownNode; }
    void SetUnknownNode(const Pointer<class NiNode*>& value) { m_UnknownNode = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
