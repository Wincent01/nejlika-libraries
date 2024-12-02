#pragma once

#include <string>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"

namespace nejlika::world
{

class CameraWaypointData : public WorldSerialize
{
public:
    CameraWaypointData(nejlika::Reader& io, version version);

    CameraWaypointData();

    void Save(nejlika::Writer& io, version version) const override;

    const vector4& GetRotation() const;

    float GetTime() const;

    float GetFov() const;

    float GetTension() const;

    float GetContinuity() const;

    float GetBias() const;

    void SetRotation(const vector4& rotation);

    void SetTime(float time);

    void SetFov(float fov);

    void SetTension(float tension);

    void SetContinuity(float continuity);

    void SetBias(float bias);

    ~CameraWaypointData();

private:
    vector4 m_Rotation;

    float m_Time;

    float m_Fov;

    float m_Tension;

    float m_Continuity;

    float m_Bias;
};

}