#include "TransitionPoint.hpp"

nejlika::world::TransitionPoint::TransitionPoint(nejlika::Reader &io, version version)
{
    m_SceneID = io.Read<uint32_t>();

    m_LayerID = io.Read<uint32_t>();

    m_Point = io.Read<vector3>();
}

void nejlika::world::TransitionPoint::Save(nejlika::Writer &io, version version) const
{
    io.Write(m_SceneID);

    io.Write(m_LayerID);

    io.Write(m_Point);
}

uint32_t nejlika::world::TransitionPoint::GetSceneID() const
{
    return m_SceneID;
}

uint32_t nejlika::world::TransitionPoint::GetLayerID() const
{
    return m_LayerID;
}

const vector3 &nejlika::world::TransitionPoint::GetPoint() const
{
    return m_Point;
}

nejlika::world::TransitionPoint::~TransitionPoint()
{
}

