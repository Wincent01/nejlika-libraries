#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-specific node.
 *         
 */
class BSAnimNotes : public NiObject
{
protected:
    /**
     * Unknown
     */
    short m_UnknownShort1;

public:
    const short& GetUnknownShort1() const { return m_UnknownShort1; }
    short& GetUnknownShort1() { return m_UnknownShort1; }
    void SetUnknownShort1(const short& value) { m_UnknownShort1 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
