#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiBinaryVoxelData.hpp"
#include "NiExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Voxel extra data object.
 *         
 */
class NiBinaryVoxelExtraData : public NiExtraData
{
protected:
    /**
     * Unknown.  0?
     */
    uint m_UnknownInt;
    /**
     * Link to binary voxel data.
     */
    Pointer<class NiBinaryVoxelData*> m_Data;

public:
    const uint& GetUnknownInt() const { return m_UnknownInt; }
    uint& GetUnknownInt() { return m_UnknownInt; }
    void SetUnknownInt(const uint& value) { m_UnknownInt = value; }

    const Pointer<class NiBinaryVoxelData*>& GetData() const { return m_Data; }
    Pointer<class NiBinaryVoxelData*>& GetData() { return m_Data; }
    void SetData(const Pointer<class NiBinaryVoxelData*>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
