#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "SizedString.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A string type.
 *         
 */
class string : public Construct
{
protected:
    /**
     * The normal string.
     */
    SizedString m_String;
    /**
     * The string index.
     */
    StringIndex m_Index;

public:
    const SizedString& GetString() const { return m_String; }
    SizedString& GetString() { return m_String; }
    void SetString(const SizedString& value) { m_String = value; }

    const StringIndex& GetIndex() const { return m_Index; }
    StringIndex& GetIndex() { return m_Index; }
    void SetIndex(const StringIndex& value) { m_Index = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
