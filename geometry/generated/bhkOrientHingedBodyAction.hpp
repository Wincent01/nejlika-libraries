#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "bhkSerializable.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-Specific node.
 *         
 */
class bhkOrientHingedBodyAction : public bhkSerializable
{
protected:
    std::vector<int> m_UnknownInts1;

public:
    const std::vector<int>& GetUnknownInts1() const { return m_UnknownInts1; }
    std::vector<int>& GetUnknownInts1() { return m_UnknownInts1; }
    void SetUnknownInts1(const std::vector<int>& value) { m_UnknownInts1 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
