#include "BSWArray.hpp"

using namespace nejlika::geometry;

void BSWArray::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiExtraData::Read(reader, version, user, arg);

    m_NumItems = reader.Read<int>();

    m_Items.resize(m_NumItems);
    for (uint32_t i = 0; i < m_Items.size(); i++)
    {
        m_Items[i] = reader.Read<int>();
    }

}

void BSWArray::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiExtraData::Write(writer, version, user, arg);

    writer.Write(m_NumItems);

    for (uint32_t i = 0; i < m_Items.size(); i++)
    {
        writer.Write(m_Items[i]);
    }

}
