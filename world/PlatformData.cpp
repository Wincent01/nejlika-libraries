#include "PlatformData.hpp"

nejlika::world::PlatformData::PlatformData(nejlika::Reader &io, version version)
{
    m_TravelingAudioGuid = (version >= 13 && version < 18) ? io.ReadString16<uint8_t>() : u"";

    m_TimeBasedMovement = (version >= 18) ? io.Read<bool>() : false;
}

nejlika::world::PlatformData::PlatformData()
{
}

void nejlika::world::PlatformData::Save(nejlika::Writer &io, version version) const
{
    if (version >= 13 && version < 18)
    {
        io.WriteString16<uint8_t>(m_TravelingAudioGuid);
    }

    if (version >= 18)
    {
        io.Write(m_TimeBasedMovement);
    }
}

const str16 &nejlika::world::PlatformData::GetTravelingAudioGuid() const
{
    return m_TravelingAudioGuid;
}

bool nejlika::world::PlatformData::IsTimeBasedMovement() const
{
    return m_TimeBasedMovement;
}

nejlika::world::PlatformData::~PlatformData()
{
}
