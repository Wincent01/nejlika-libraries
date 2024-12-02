#include "NiUVData.hpp"

using namespace nejlika::geometry;

void NiUVData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_UVGroups.resize(4);
    for (uint32_t i = 0; i < m_UVGroups.size(); i++)
    {
        m_UVGroups[i].Read(reader, version, user, 0);
    }

}

void NiUVData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    for (uint32_t i = 0; i < m_UVGroups.size(); i++)
    {
        m_UVGroups[i].Write(writer, version, user, 0);
    }

}
