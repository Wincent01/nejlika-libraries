#include "BSBoneLODExtraData.hpp"

using namespace nejlika::geometry;

void BSBoneLODExtraData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiExtraData::Read(reader, version, user, arg);

    m_BoneLODCount = reader.Read<uint>();

    m_BoneLODInfo.resize(m_BoneLODCount);
    for (uint32_t i = 0; i < m_BoneLODInfo.size(); i++)
    {
        m_BoneLODInfo[i].Read(reader, version, user, 0);
    }

}

void BSBoneLODExtraData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiExtraData::Write(writer, version, user, arg);

    writer.Write(m_BoneLODCount);

    for (uint32_t i = 0; i < m_BoneLODInfo.size(); i++)
    {
        m_BoneLODInfo[i].Write(writer, version, user, 0);
    }

}
