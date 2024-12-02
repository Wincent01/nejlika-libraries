#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


/**
 * 
 *         A range of indices, which make up a region (such as a submesh).
 *         
 */
class Region : public Construct
{
protected:
    uint m_StartIndex;
    uint m_NumIndices;

public:
    const uint& GetStartIndex() const { return m_StartIndex; }
    uint& GetStartIndex() { return m_StartIndex; }
    void SetStartIndex(const uint& value) { m_StartIndex = value; }

    const uint& GetNumIndices() const { return m_NumIndices; }
    uint& GetNumIndices() { return m_NumIndices; }
    void SetNumIndices(const uint& value) { m_NumIndices = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
