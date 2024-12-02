#include "SizedString.hpp"

using namespace nejlika::geometry;

void SizedString::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Length = reader.Read<uint>();

    m_Value.resize(m_Length);
    for (uint32_t i = 0; i < m_Value.size(); i++)
    {
        m_Value[i] = reader.Read<char>();
    }

}

void SizedString::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_Length);

    for (uint32_t i = 0; i < m_Value.size(); i++)
    {
        writer.Write(m_Value[i]);
    }

}
