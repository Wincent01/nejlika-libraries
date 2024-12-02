#include "PropertyData.hpp"


nejlika::world::PropertyData::PropertyData(nejlika::Reader &io, version version)
{
    m_PathType = static_cast<PropertyPathType>(io.Read<uint32_t>());

    m_Price = io.Read<uint32_t>();

    m_Time = io.Read<uint32_t>();

    m_AssociatedZone = io.Read<uint64_t>();
    
    m_Name = version >= 5 ? io.ReadString16<uint8_t>() : u"";

    m_Description = version >= 5 ? io.ReadString16<uint32_t>() : u"";

    m_PropertyType = version >= 6 ? static_cast<PropertyType>(io.Read<uint32_t>()) : PropertyType::Premiere;

    m_CloneLimit = version >= 7 ? io.Read<uint32_t>() : 0;

    m_ReputationMultiplier = version >= 7 ? io.Read<float>() : 1.0f;

    m_PeriodType = version >= 7 ? io.Read<uint32_t>() : 0;

    m_AchievementRequired = version >= 8 ? io.Read<uint32_t>() : 0;

    m_ZonePosition = version >= 8 ? io.Read<vector3>() : vector3();

    m_MaxBuildHeight = version >= 8 ? io.Read<float>() : 0.0f;
}

nejlika::world::PropertyData::PropertyData()
{
}

void nejlika::world::PropertyData::Save(nejlika::Writer &io, version version) const
{
    io.Write(static_cast<uint32_t>(m_PathType));

    io.Write(m_Price);

    io.Write(m_Time);

    io.Write(m_AssociatedZone);

    if (version >= 5)
    {
        io.WriteString16<uint8_t>(m_Name);

        io.WriteString16<uint32_t>(m_Description);
    }

    if (version >= 6)
    {
        io.Write(static_cast<uint32_t>(m_PropertyType));
    }

    if (version >= 7)
    {
        io.Write(m_CloneLimit);

        io.Write(m_ReputationMultiplier);
        
        io.Write(m_PeriodType);
    }

    if (version >= 8)
    {
        io.Write(m_AchievementRequired);

        io.Write(m_ZonePosition);

        io.Write(m_MaxBuildHeight);
    }
}

PropertyPathType nejlika::world::PropertyData::GetPathType() const
{
    return m_PathType;
}

uint32_t nejlika::world::PropertyData::GetPrice() const
{
    return m_Price;
}

uint32_t nejlika::world::PropertyData::GetTime() const
{
    return m_Time;
}

uint64_t nejlika::world::PropertyData::GetAssociatedZone() const
{
    return m_AssociatedZone;
}

const str16 &nejlika::world::PropertyData::GetName() const
{
    return m_Name;
}

const str16 &nejlika::world::PropertyData::GetDescription() const
{
    return m_Description;
}

PropertyType nejlika::world::PropertyData::GetPropertyType() const
{
    return m_PropertyType;
}

uint32_t nejlika::world::PropertyData::GetCloneLimit() const
{
    return m_CloneLimit;
}

float nejlika::world::PropertyData::GetReputationMultiplier() const
{
    return m_ReputationMultiplier;
}

uint32_t nejlika::world::PropertyData::GetPeriodType() const
{
    return m_PeriodType;
}

uint32_t nejlika::world::PropertyData::GetAchievementRequired() const
{
    return m_AchievementRequired;
}

const vector3 &nejlika::world::PropertyData::GetZonePosition() const
{
    return m_ZonePosition;
}

float nejlika::world::PropertyData::GetMaxBuildHeight() const
{
    return m_MaxBuildHeight;
}

nejlika::world::PropertyData::~PropertyData()
{
}
