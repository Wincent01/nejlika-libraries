#pragma once

#include <string>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"

namespace nejlika::world
{

class SceneReference
{
public:
    SceneReference() = default;

    SceneReference(nejlika::Reader& io, version version);

    void Save(nejlika::Writer& io, version version) const;

    const std::string& GetSceneFilename() const;

    uint32_t GetSceneID() const;

    uint32_t GetLayerID() const;

    const std::string& GetSceneName() const;

    const vector3& GetUnknown1() const;

    float GetUnknown2() const;

    const color& GetColor() const;

    void SetSceneFilename(const std::string& sceneFilename);

    void SetSceneID(uint32_t sceneID);

    void SetLayerID(uint32_t layerID);

    void SetSceneName(const std::string& sceneName);

    void SetUnknown1(const vector3& unknown1);

    void SetUnknown2(float unknown2);

    void SetColor(const color& color);

    ~SceneReference();

private:
    std::string m_SceneFilename;

    uint32_t m_SceneID;

    uint32_t m_LayerID;

    std::string m_SceneName;

    vector3 m_Unknown1;

    float m_Unknown2;

    color m_Color;
};

}