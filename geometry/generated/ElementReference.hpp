#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "SemanticData.hpp"
namespace nejlika::geometry {


class ElementReference : public Construct
{
protected:
    /**
     * The element semantic.
     */
    SemanticData m_Semantic;
    /**
     * Whether or not to normalize the data.
     */
    uint m_NormalizeFlag;

public:
    const SemanticData& GetSemantic() const { return m_Semantic; }
    SemanticData& GetSemantic() { return m_Semantic; }
    void SetSemantic(const SemanticData& value) { m_Semantic = value; }

    const uint& GetNormalizeFlag() const { return m_NormalizeFlag; }
    uint& GetNormalizeFlag() { return m_NormalizeFlag; }
    void SetNormalizeFlag(const uint& value) { m_NormalizeFlag = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
