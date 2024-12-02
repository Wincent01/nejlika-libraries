#pragma once

#include <string>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"

namespace nejlika::world
{

class RacingWaypointData : public WorldSerialize
{
public:
    RacingWaypointData(nejlika::Reader& io, version version);

    RacingWaypointData();

    void Save(nejlika::Writer& io, version version) const override;

    const vector4& GetRotation() const;

    bool IsResetNode() const;

    bool IsNonHorizontalCamera() const;

    float GetPlaneWidth() const;

    float GetPlaneHeight() const;

    float GetShortestDistanceToEnd() const;

    ~RacingWaypointData();

private:
    vector4 m_Rotation;

    bool m_IsResetNode;

    bool m_IsNonHorizontalCamera;

    float m_PlaneWidth;

    float m_PlaneHeight;

    float m_ShortestDistanceToEnd;
};

}