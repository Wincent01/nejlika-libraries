#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "DataStreamUsage.hpp"
#include "DataStreamAccess.hpp"
#include "CloningBehavior.hpp"
#include "Region.hpp"
#include "ComponentFormat.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


class NiDataStream : public NiObject
{
protected:
    DataStreamUsage m_Usage;
    DataStreamAccess m_Access;
    /**
     * The size in bytes of this data stream.
     */
    uint m_NumBytes;
    CloningBehavior m_CloningBehavior;
    /**
     * Number of regions (such as submeshes).
     */
    uint m_NumRegions;
    /**
     * The regions in the mesh. Regions can be used to mark off submeshes which are independent draw calls.
     */
    std::vector<Region> m_Regions;
    /**
     * Number of components of the data (matches corresponding field in MeshData).
     */
    uint m_NumComponents;
    /**
     * The format of each component in this data stream.
     */
    std::vector<ComponentFormat> m_ComponentFormats;
    std::vector<byte> m_Data;
    bool m_Streamable;

public:
    const DataStreamUsage& GetUsage() const { return m_Usage; }
    DataStreamUsage& GetUsage() { return m_Usage; }
    void SetUsage(const DataStreamUsage& value) { m_Usage = value; }

    const DataStreamAccess& GetAccess() const { return m_Access; }
    DataStreamAccess& GetAccess() { return m_Access; }
    void SetAccess(const DataStreamAccess& value) { m_Access = value; }

    const uint& GetNumBytes() const { return m_NumBytes; }
    uint& GetNumBytes() { return m_NumBytes; }
    void SetNumBytes(const uint& value) { m_NumBytes = value; }

    const CloningBehavior& GetCloningBehavior() const { return m_CloningBehavior; }
    CloningBehavior& GetCloningBehavior() { return m_CloningBehavior; }
    void SetCloningBehavior(const CloningBehavior& value) { m_CloningBehavior = value; }

    const uint& GetNumRegions() const { return m_NumRegions; }
    uint& GetNumRegions() { return m_NumRegions; }
    void SetNumRegions(const uint& value) { m_NumRegions = value; }

    const std::vector<Region>& GetRegions() const { return m_Regions; }
    std::vector<Region>& GetRegions() { return m_Regions; }
    void SetRegions(const std::vector<Region>& value) { m_Regions = value; }

    const uint& GetNumComponents() const { return m_NumComponents; }
    uint& GetNumComponents() { return m_NumComponents; }
    void SetNumComponents(const uint& value) { m_NumComponents = value; }

    const std::vector<ComponentFormat>& GetComponentFormats() const { return m_ComponentFormats; }
    std::vector<ComponentFormat>& GetComponentFormats() { return m_ComponentFormats; }
    void SetComponentFormats(const std::vector<ComponentFormat>& value) { m_ComponentFormats = value; }

    const std::vector<byte>& GetData() const { return m_Data; }
    std::vector<byte>& GetData() { return m_Data; }
    void SetData(const std::vector<byte>& value) { m_Data = value; }

    const bool& GetStreamable() const { return m_Streamable; }
    bool& GetStreamable() { return m_Streamable; }
    void SetStreamable(const bool& value) { m_Streamable = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
