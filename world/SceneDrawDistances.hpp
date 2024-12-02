#pragma once

#include <string>
#include <vector>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"
#include "WritePointer.hpp"

namespace nejlika::world
{

class SceneDrawDistances
{
public:
    SceneDrawDistances() = default;

    SceneDrawDistances(nejlika::Reader& io);

    void Save(nejlika::Writer& io) const;
    
    float GetFogNear() const;

    float GetFogFar() const;

    float GetPostFogSolid() const;

    float GetPostFogFade() const;

    float GetStaticObjectDistance() const;

    float GetDynamicObjectDistance() const;

    ~SceneDrawDistances();

private:
    float m_FogNear;
    float m_FogFar;
    float m_PostFogSolid;
    float m_PostFogFade;
    float m_StaticObjectDistance;
    float m_DynamicObjectDistance;
};


}