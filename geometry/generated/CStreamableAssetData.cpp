#include "CStreamableAssetData.hpp"

using namespace nejlika::geometry;

void CStreamableAssetData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_Root.Read(reader, version, user, 0);

    m_UnknownBytes.resize(5);
    for (uint32_t i = 0; i < m_UnknownBytes.size(); i++)
    {
        m_UnknownBytes[i] = reader.Read<byte>();
    }

}

void CStreamableAssetData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    m_Root.Write(writer, version, user, 0);

    for (uint32_t i = 0; i < m_UnknownBytes.size(); i++)
    {
        writer.Write(m_UnknownBytes[i]);
    }

}
