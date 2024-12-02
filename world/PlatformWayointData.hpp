#pragma once

#include <string>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"

namespace nejlika::world
{

class PlatformWaypointData : public WorldSerialize
{
public:
    PlatformWaypointData(nejlika::Reader& io, version version);

    PlatformWaypointData();

    void Save(nejlika::Writer& io, version version) const override;

    const vector4& GetRotation() const;

    bool GetLockPlayer() const;

    float GetSpeed() const;

    float GetWait() const;

    const str16& GetDepartAudioGuid() const;

    const str16& GetArriveAudioGuid() const;

    ~PlatformWaypointData();

private:
    vector4 m_Rotation;

    bool m_LockPlayer;

    float m_Speed;

    float m_Wait;

    str16 m_DepartAudioGuid;

    str16 m_ArriveAudioGuid;
};

}