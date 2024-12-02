#include "FxWidget.hpp"

using namespace nejlika::geometry;

void FxWidget::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiNode::Read(reader, version, user, arg);

    m_Unknown3 = reader.Read<byte>();

    m_Unknown292Bytes.resize(292);
    for (uint32_t i = 0; i < m_Unknown292Bytes.size(); i++)
    {
        m_Unknown292Bytes[i] = reader.Read<byte>();
    }

}

void FxWidget::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiNode::Write(writer, version, user, arg);

    writer.Write(m_Unknown3);

    for (uint32_t i = 0; i < m_Unknown292Bytes.size(); i++)
    {
        writer.Write(m_Unknown292Bytes[i]);
    }

}
