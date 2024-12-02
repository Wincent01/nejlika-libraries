#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


/**
 * 
 *         Group of vertex indices of vertices that match.
 *         
 */
class MatchGroup : public Construct
{
protected:
    /**
     * Number of vertices in this group.
     */
    ushort m_NumVertices;
    /**
     * The vertex indices.
     */
    std::vector<ushort> m_VertexIndices;

public:
    const ushort& GetNumVertices() const { return m_NumVertices; }
    ushort& GetNumVertices() { return m_NumVertices; }
    void SetNumVertices(const ushort& value) { m_NumVertices = value; }

    const std::vector<ushort>& GetVertexIndices() const { return m_VertexIndices; }
    std::vector<ushort>& GetVertexIndices() { return m_VertexIndices; }
    void SetVertexIndices(const std::vector<ushort>& value) { m_VertexIndices = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
