#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "string.hpp"
#include "NiSingleInterpController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A particle system modifier controller.
 *         
 */
class NiPSysModifierCtlr : public NiSingleInterpController
{
protected:
    /**
     * Refers to modifier object by its name?
     */
    string m_ModifierName;

public:
    const string& GetModifierName() const { return m_ModifierName; }
    string& GetModifierName() { return m_ModifierName; }
    void SetModifierName(const string& value) { m_ModifierName = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
