#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "FxRadioButton.hpp"
#include "FxWidget.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown.
 *         
 */
class FxRadioButton : public FxWidget
{
protected:
    /**
     * Unknown.
     */
    uint m_UnknownInt1;
    /**
     * Unknown.
     */
    uint m_UnknownInt2;
    /**
     * Unknown.
     */
    uint m_UnknownInt3;
    /**
     * Number of unknown links.
     */
    uint m_NumButtons;
    /**
     * Unknown pointers to other buttons.  Maybe other buttons in a group so they can be switch off if this one is switched on?
     */
    std::vector<Pointer<class FxRadioButton*>> m_Buttons;

public:
    const uint& GetUnknownInt1() const { return m_UnknownInt1; }
    uint& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const uint& value) { m_UnknownInt1 = value; }

    const uint& GetUnknownInt2() const { return m_UnknownInt2; }
    uint& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const uint& value) { m_UnknownInt2 = value; }

    const uint& GetUnknownInt3() const { return m_UnknownInt3; }
    uint& GetUnknownInt3() { return m_UnknownInt3; }
    void SetUnknownInt3(const uint& value) { m_UnknownInt3 = value; }

    const uint& GetNumButtons() const { return m_NumButtons; }
    uint& GetNumButtons() { return m_NumButtons; }
    void SetNumButtons(const uint& value) { m_NumButtons = value; }

    const std::vector<Pointer<class FxRadioButton*>>& GetButtons() const { return m_Buttons; }
    std::vector<Pointer<class FxRadioButton*>>& GetButtons() { return m_Buttons; }
    void SetButtons(const std::vector<Pointer<class FxRadioButton*>>& value) { m_Buttons = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
