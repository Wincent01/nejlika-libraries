#include "NiPSysEmitterCtlrData.hpp"

using namespace nejlika::geometry;

void NiPSysEmitterCtlrData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_FloatKeys.Read(reader, version, user, 0);

    m_NumVisibilityKeys = reader.Read<uint>();

    m_VisibilityKeys.resize(m_NumVisibilityKeys);
    for (uint32_t i = 0; i < m_VisibilityKeys.size(); i++)
    {
        m_VisibilityKeys[i].Read(reader, version, user, 1);
    }

}

void NiPSysEmitterCtlrData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    m_FloatKeys.Write(writer, version, user, 0);

    writer.Write(m_NumVisibilityKeys);

    for (uint32_t i = 0; i < m_VisibilityKeys.size(); i++)
    {
        m_VisibilityKeys[i].Write(writer, version, user, 1);
    }

}
