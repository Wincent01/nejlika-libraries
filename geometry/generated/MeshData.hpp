#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiDataStream.hpp"
#include "SemanticData.hpp"
namespace nejlika::geometry {


class MeshData : public Construct
{
protected:
    /**
     * 
     *             Reference to a data stream object which holds the data used by
     *             this reference.
     *         
     */
    Pointer<class NiDataStream*> m_Stream;
    /**
     * 
     *             Sets whether this stream data is per-instance data for use in
     *             hardware instancing.
     *         
     */
    bool m_IsPerInstance;
    /**
     * 
     *             The number of submesh-to-region mappings that this data stream
     *             has.
     *         
     */
    ushort m_NumSubmeshes;
    /**
     * 
     *             A lookup table that maps submeshes to regions.
     *         
     */
    std::vector<ushort> m_SubmeshToRegionMap;
    int m_NumComponents;
    /**
     * Describes the semantic of each component.
     */
    std::vector<SemanticData> m_ComponentSemantics;

public:
    const Pointer<class NiDataStream*>& GetStream() const { return m_Stream; }
    Pointer<class NiDataStream*>& GetStream() { return m_Stream; }
    void SetStream(const Pointer<class NiDataStream*>& value) { m_Stream = value; }

    const bool& GetIsPerInstance() const { return m_IsPerInstance; }
    bool& GetIsPerInstance() { return m_IsPerInstance; }
    void SetIsPerInstance(const bool& value) { m_IsPerInstance = value; }

    const ushort& GetNumSubmeshes() const { return m_NumSubmeshes; }
    ushort& GetNumSubmeshes() { return m_NumSubmeshes; }
    void SetNumSubmeshes(const ushort& value) { m_NumSubmeshes = value; }

    const std::vector<ushort>& GetSubmeshToRegionMap() const { return m_SubmeshToRegionMap; }
    std::vector<ushort>& GetSubmeshToRegionMap() { return m_SubmeshToRegionMap; }
    void SetSubmeshToRegionMap(const std::vector<ushort>& value) { m_SubmeshToRegionMap = value; }

    const int& GetNumComponents() const { return m_NumComponents; }
    int& GetNumComponents() { return m_NumComponents; }
    void SetNumComponents(const int& value) { m_NumComponents = value; }

    const std::vector<SemanticData>& GetComponentSemantics() const { return m_ComponentSemantics; }
    std::vector<SemanticData>& GetComponentSemantics() { return m_ComponentSemantics; }
    void SetComponentSemantics(const std::vector<SemanticData>& value) { m_ComponentSemantics = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
