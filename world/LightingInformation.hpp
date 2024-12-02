#pragma once

#include <string>
#include <vector>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"
#include "WritePointer.hpp"

#include "CullData.hpp"
#include "SceneDrawDistances.hpp"

namespace nejlika::world
{

class LightingInformation
{
public:
    LightingInformation() = default;

    LightingInformation(nejlika::Reader& io, uint32_t version);

    void Save(nejlika::Writer& io, uint32_t version) const;

    float GetBlendTime() const;

    const vector3& GetAmbient() const;

    const vector3& GetSpecular() const;

    const vector3& GetUpperHemi() const;

    const vector3& GetPosition() const;

    const SceneDrawDistances& GetMinDrawDistances() const;

    const SceneDrawDistances& GetMaxDrawDistances() const;

    const std::vector<CullData>& GetCullData() const;

    float GetFogNear() const;

    float GetFogFar() const;

    const vector3& GetFogColor() const;

    const vector3& GetDirectionalLightColor() const;

    const vector3& GetStartPosition() const;

    const vector4& GetStartRotation() const;

    ~LightingInformation();

private:
    float m_BlendTime;
    vector3 m_Ambient;
    vector3 m_Specular;
    vector3 m_UpperHemi;
    vector3 m_Position;
    SceneDrawDistances m_MinDrawDistances;
    SceneDrawDistances m_MaxDrawDistances;
    std::vector<CullData> m_CullData;
    float m_FogNear;
    float m_FogFar;
    vector3 m_FogColor;
    vector3 m_DirectionalLightColor;
    vector3 m_StartPosition;
    vector4 m_StartRotation;
};

}