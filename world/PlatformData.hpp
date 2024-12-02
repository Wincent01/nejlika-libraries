#pragma once

#include <string>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"

namespace nejlika::world
{

class PlatformData : public WorldSerialize
{
public:
    PlatformData(nejlika::Reader& io, version version);

    PlatformData();

    void Save(nejlika::Writer& io, version version) const override;

    const str16& GetTravelingAudioGuid() const;

    bool IsTimeBasedMovement() const;
    
    ~PlatformData();

private:
    str16 m_TravelingAudioGuid;

    bool m_TimeBasedMovement;
};

}