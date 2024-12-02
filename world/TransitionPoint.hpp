#pragma once

#include <string>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"

namespace nejlika::world
{

class TransitionPoint
{
public:
    TransitionPoint(nejlika::Reader& io, version version);

    void Save(nejlika::Writer& io, version version) const;

    uint32_t GetSceneID() const;

    uint32_t GetLayerID() const;

    const vector3& GetPoint() const;

    ~TransitionPoint();

private:
    uint32_t m_SceneID;

    uint32_t m_LayerID;

    vector3 m_Point;
};

}