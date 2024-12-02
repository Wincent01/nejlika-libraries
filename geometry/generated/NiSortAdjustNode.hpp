#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "SortingMode.hpp"
#include "NiNode.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown node.  Found in Loki.
 *         
 */
class NiSortAdjustNode : public NiNode
{
protected:
    /**
     * Sorting
     */
    SortingMode m_SortingMode;
    /**
     * Unknown.
     */
    int m_UnknownInt2;

public:
    const SortingMode& GetSortingMode() const { return m_SortingMode; }
    SortingMode& GetSortingMode() { return m_SortingMode; }
    void SetSortingMode(const SortingMode& value) { m_SortingMode = value; }

    const int& GetUnknownInt2() const { return m_UnknownInt2; }
    int& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const int& value) { m_UnknownInt2 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
