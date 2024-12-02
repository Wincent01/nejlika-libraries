#include "SceneDrawDistances.hpp"

using namespace nejlika::world;

nejlika::world::SceneDrawDistances::SceneDrawDistances(nejlika::Reader &io)
{
    m_FogNear = io.Read<float>();
    m_FogFar = io.Read<float>();
    m_PostFogSolid = io.Read<float>();
    m_PostFogFade = io.Read<float>();
    m_StaticObjectDistance = io.Read<float>();
    m_DynamicObjectDistance = io.Read<float>();
}

void nejlika::world::SceneDrawDistances::Save(nejlika::Writer &io) const
{
    io.Write(m_FogNear);
    io.Write(m_FogFar);
    io.Write(m_PostFogSolid);
    io.Write(m_PostFogFade);
    io.Write(m_StaticObjectDistance);
    io.Write(m_DynamicObjectDistance);
}

float nejlika::world::SceneDrawDistances::GetFogNear() const
{
    return m_FogNear;
}

float nejlika::world::SceneDrawDistances::GetFogFar() const
{
    return m_FogFar;
}

float nejlika::world::SceneDrawDistances::GetPostFogSolid() const
{
    return m_PostFogSolid;
}

float nejlika::world::SceneDrawDistances::GetPostFogFade() const
{
    return m_PostFogFade;
}

float nejlika::world::SceneDrawDistances::GetStaticObjectDistance() const
{
    return m_StaticObjectDistance;
}

float nejlika::world::SceneDrawDistances::GetDynamicObjectDistance() const
{
    return m_DynamicObjectDistance;
}

nejlika::world::SceneDrawDistances::~SceneDrawDistances()
{
}

