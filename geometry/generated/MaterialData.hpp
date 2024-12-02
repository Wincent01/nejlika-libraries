#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "string.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Data stored per-material by NiRenderObject
 *         
 */
class MaterialData : public Construct
{
protected:
    /**
     * The name of the material.
     */
    string m_MaterialName;
    /**
     * Extra data associated with the material?
     */
    uint m_MaterialExtraData;

public:
    const string& GetMaterialName() const { return m_MaterialName; }
    string& GetMaterialName() { return m_MaterialName; }
    void SetMaterialName(const string& value) { m_MaterialName = value; }

    const uint& GetMaterialExtraData() const { return m_MaterialExtraData; }
    uint& GetMaterialExtraData() { return m_MaterialExtraData; }
    void SetMaterialExtraData(const uint& value) { m_MaterialExtraData = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
