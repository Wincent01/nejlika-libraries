#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "string.hpp"
namespace nejlika::geometry {


class SemanticData : public Construct
{
protected:
    /**
     * 
     *             Type of data (POSITION, POSITION_BP, INDEX, NORMAL, NORMAL_BP,
     *             TEXCOORD, BLENDINDICES, BLENDWEIGHT, BONE_PALETTE, COLOR, DISPLAYLIST,
     *             MORPH_POSITION, BINORMAL_BP, TANGENT_BP).
     *         
     */
    string m_Name;
    /**
     * 
     *             An extra index of the data. For example, if there are 3 uv maps,
     *             then the corresponding TEXCOORD data components would have indices
     *             0, 1, and 2, respectively.
     *         
     */
    uint m_Index;

public:
    const string& GetName() const { return m_Name; }
    string& GetName() { return m_Name; }
    void SetName(const string& value) { m_Name = value; }

    const uint& GetIndex() const { return m_Index; }
    uint& GetIndex() { return m_Index; }
    void SetIndex(const uint& value) { m_Index = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
