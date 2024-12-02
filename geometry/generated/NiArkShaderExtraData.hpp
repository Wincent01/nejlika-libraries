#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "string.hpp"
#include "NiExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown node.
 *         
 */
class NiArkShaderExtraData : public NiExtraData
{
protected:
    int m_UnknownInt;
    string m_UnknownString;

public:
    const int& GetUnknownInt() const { return m_UnknownInt; }
    int& GetUnknownInt() { return m_UnknownInt; }
    void SetUnknownInt(const int& value) { m_UnknownInt = value; }

    const string& GetUnknownString() const { return m_UnknownString; }
    string& GetUnknownString() { return m_UnknownString; }
    void SetUnknownString(const string& value) { m_UnknownString = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
