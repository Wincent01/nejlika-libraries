#include "NiVisData.hpp"

using namespace nejlika::geometry;

void NiVisData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_NumKeys = reader.Read<uint>();

    m_Keys.resize(m_NumKeys);
    for (uint32_t i = 0; i < m_Keys.size(); i++)
    {
        m_Keys[i].Read(reader, version, user, 1);
    }

}

void NiVisData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    writer.Write(m_NumKeys);

    for (uint32_t i = 0; i < m_Keys.size(); i++)
    {
        m_Keys[i].Write(writer, version, user, 1);
    }

}
