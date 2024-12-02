#pragma once

#include <string>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"

namespace nejlika::world
{

class PropertyData : public WorldSerialize
{
public:
    PropertyData(nejlika::Reader& io, version version);

    PropertyData();

    void Save(nejlika::Writer& io, version version) const override;

    PropertyPathType GetPathType() const;

    uint32_t GetPrice() const;

    uint32_t GetTime() const;

    uint64_t GetAssociatedZone() const;

    const str16& GetName() const;

    const str16& GetDescription() const;

    PropertyType GetPropertyType() const;

    uint32_t GetCloneLimit() const;

    float GetReputationMultiplier() const;

    uint32_t GetPeriodType() const;

    uint32_t GetAchievementRequired() const;

    const vector3& GetZonePosition() const;

    float GetMaxBuildHeight() const;

    ~PropertyData();

private:
    PropertyPathType m_PathType;

    uint32_t m_Price;

    uint32_t m_Time;

    uint64_t m_AssociatedZone;

    str16 m_Name;

    str16 m_Description;

    PropertyType m_PropertyType;

    uint32_t m_CloneLimit;

    float m_ReputationMultiplier;

    uint32_t m_PeriodType;

    uint32_t m_AchievementRequired;

    vector3 m_ZonePosition;

    float m_MaxBuildHeight;
};

}