#include "BoxBV.hpp"

using namespace nejlika::geometry;

void BoxBV::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Center.Read(reader, version, user, 0);

    m_Axis.resize(3);
    for (uint32_t i = 0; i < m_Axis.size(); i++)
    {
        m_Axis[i].Read(reader, version, user, 0);
    }

    m_Extent.resize(3);
    for (uint32_t i = 0; i < m_Extent.size(); i++)
    {
        m_Extent[i] = reader.Read<float>();
    }

}

void BoxBV::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    m_Center.Write(writer, version, user, 0);

    for (uint32_t i = 0; i < m_Axis.size(); i++)
    {
        m_Axis[i].Write(writer, version, user, 0);
    }

    for (uint32_t i = 0; i < m_Extent.size(); i++)
    {
        writer.Write(m_Extent[i]);
    }

}
