#include "NiTransparentProperty.hpp"

using namespace nejlika::geometry;

void NiTransparentProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiProperty::Read(reader, version, user, arg);

    m_Unknown.resize(6);
    for (uint32_t i = 0; i < m_Unknown.size(); i++)
    {
        m_Unknown[i] = reader.Read<byte>();
    }

}

void NiTransparentProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiProperty::Write(writer, version, user, arg);

    for (uint32_t i = 0; i < m_Unknown.size(); i++)
    {
        writer.Write(m_Unknown[i]);
    }

}
