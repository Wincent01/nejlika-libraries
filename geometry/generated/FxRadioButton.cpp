#include "FxRadioButton.hpp"

using namespace nejlika::geometry;

void FxRadioButton::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    FxWidget::Read(reader, version, user, arg);

    m_UnknownInt1 = reader.Read<uint>();

    m_UnknownInt2 = reader.Read<uint>();

    m_UnknownInt3 = reader.Read<uint>();

    m_NumButtons = reader.Read<uint>();

    m_Buttons.resize(m_NumButtons);
    for (uint32_t i = 0; i < m_Buttons.size(); i++)
    {
        m_Buttons[i].Read(reader, version, user, 0);
    }

}

void FxRadioButton::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    FxWidget::Write(writer, version, user, arg);

    writer.Write(m_UnknownInt1);

    writer.Write(m_UnknownInt2);

    writer.Write(m_UnknownInt3);

    writer.Write(m_NumButtons);

    for (uint32_t i = 0; i < m_Buttons.size(); i++)
    {
        m_Buttons[i].Write(writer, version, user, 0);
    }

}
