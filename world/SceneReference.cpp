#include "SceneReference.hpp"


nejlika::world::SceneReference::SceneReference(nejlika::Reader &io, version version)
{
    m_SceneFilename = io.ReadString<uint8_t>();

    m_SceneID = (version >= 33 || version < 30) ? io.Read<uint32_t>() : 0;

    m_LayerID = version >= 33 ? io.Read<uint32_t>() : 0;

    m_SceneName = version >= 33 ? io.ReadString<uint8_t>() : "";

    m_Unknown1 = version == 33 ? io.Read<vector3>() : vector3();

    m_Unknown2 = version == 33 ? io.Read<float>() : 0.0f;

    m_Color = version >= 33 ? io.Read<color>() : color();
}

void nejlika::world::SceneReference::Save(nejlika::Writer &io, version version) const
{
    io.WriteString<uint8_t>(m_SceneFilename);

    if (version >= 33 || version < 30)
    {
        io.Write(m_SceneID);
    }

    if (version >= 33)
    {
        io.Write(m_LayerID);
    }

    if (version >= 33)
    {
        io.WriteString<uint8_t>(m_SceneName);
    }

    if (version == 33)
    {
        io.Write(m_Unknown1);
    }

    if (version == 33)
    {
        io.Write(m_Unknown2);
    }

    if (version >= 33)
    {
        io.Write(m_Color);
    }
}

const std::string &nejlika::world::SceneReference::GetSceneFilename() const
{
    return m_SceneFilename;
}

uint32_t nejlika::world::SceneReference::GetSceneID() const
{
    return m_SceneID;
}

uint32_t nejlika::world::SceneReference::GetLayerID() const
{
    return m_LayerID;
}

const std::string &nejlika::world::SceneReference::GetSceneName() const
{
    return m_SceneName;
}

const vector3 &nejlika::world::SceneReference::GetUnknown1() const
{
    return m_Unknown1;
}

float nejlika::world::SceneReference::GetUnknown2() const
{
    return m_Unknown2;
}

const color &nejlika::world::SceneReference::GetColor() const
{
    return m_Color;
}

void nejlika::world::SceneReference::SetSceneFilename(const std::string &sceneFilename)
{
    m_SceneFilename = sceneFilename;
}

nejlika::world::SceneReference::~SceneReference()
{
}
