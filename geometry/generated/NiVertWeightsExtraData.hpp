#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Not used in skinning.
 *         Unsure of use - perhaps for morphing animation or gravity.
 *         
 */
class NiVertWeightsExtraData : public NiExtraData
{
protected:
    /**
     * Number of bytes in this data object.
     */
    uint m_NumBytes;
    /**
     * Number of vertices.
     */
    ushort m_NumVertices;
    /**
     * The vertex weights.
     */
    std::vector<float> m_Weight;

public:
    const uint& GetNumBytes() const { return m_NumBytes; }
    uint& GetNumBytes() { return m_NumBytes; }
    void SetNumBytes(const uint& value) { m_NumBytes = value; }

    const ushort& GetNumVertices() const { return m_NumVertices; }
    ushort& GetNumVertices() { return m_NumVertices; }
    void SetNumVertices(const ushort& value) { m_NumVertices = value; }

    const std::vector<float>& GetWeight() const { return m_Weight; }
    std::vector<float>& GetWeight() { return m_Weight; }
    void SetWeight(const std::vector<float>& value) { m_Weight = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
