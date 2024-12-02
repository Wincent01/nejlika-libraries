#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "NiNode.hpp"
#include "NiAVObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A Portal
 *         
 */
class NiPortal : public NiAVObject
{
protected:
    /**
     * Unknown flags.
     */
    Flags m_UnknownFlags;
    /**
     * Unknown
     */
    short m_UnknownShort2;
    /**
     * Number of vertices in this polygon
     */
    ushort m_NumVertices;
    /**
     * Vertices
     */
    std::vector<Vector3> m_Vertices;
    /**
     * Target portal or room
     */
    Pointer<class NiNode*> m_Target;

public:
    const Flags& GetUnknownFlags() const { return m_UnknownFlags; }
    Flags& GetUnknownFlags() { return m_UnknownFlags; }
    void SetUnknownFlags(const Flags& value) { m_UnknownFlags = value; }

    const short& GetUnknownShort2() const { return m_UnknownShort2; }
    short& GetUnknownShort2() { return m_UnknownShort2; }
    void SetUnknownShort2(const short& value) { m_UnknownShort2 = value; }

    const ushort& GetNumVertices() const { return m_NumVertices; }
    ushort& GetNumVertices() { return m_NumVertices; }
    void SetNumVertices(const ushort& value) { m_NumVertices = value; }

    const std::vector<Vector3>& GetVertices() const { return m_Vertices; }
    std::vector<Vector3>& GetVertices() { return m_Vertices; }
    void SetVertices(const std::vector<Vector3>& value) { m_Vertices = value; }

    const Pointer<class NiNode*>& GetTarget() const { return m_Target; }
    Pointer<class NiNode*>& GetTarget() { return m_Target; }
    void SetTarget(const Pointer<class NiNode*>& value) { m_Target = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
