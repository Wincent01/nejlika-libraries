#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-specific node.
 *         
 */
class BSWArray : public NiExtraData
{
protected:
    /**
     * Unknown
     */
    int m_NumItems;
    /**
     * Unknown
     */
    std::vector<int> m_Items;

public:
    const int& GetNumItems() const { return m_NumItems; }
    int& GetNumItems() { return m_NumItems; }
    void SetNumItems(const int& value) { m_NumItems = value; }

    const std::vector<int>& GetItems() const { return m_Items; }
    std::vector<int>& GetItems() { return m_Items; }
    void SetItems(const std::vector<int>& value) { m_Items = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
