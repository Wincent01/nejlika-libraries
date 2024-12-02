#include "LightingInformation.hpp"

using namespace nejlika::world;

nejlika::world::LightingInformation::LightingInformation(nejlika::Reader &io, uint32_t version)
{
    if (version >= 45) {
        m_BlendTime = io.Read<float>();
    }

    m_Ambient = io.Read<vector3>();

    m_Specular = io.Read<vector3>();

    m_UpperHemi = io.Read<vector3>();

    m_Position = io.Read<vector3>();

    if (version >= 39) {
        m_MinDrawDistances = SceneDrawDistances(io);

        m_MaxDrawDistances = SceneDrawDistances(io);
    }

    if (version >= 40) {
        uint32_t cullDataSize = io.Read<uint32_t>();

        for (uint32_t i = 0; i < cullDataSize; i++) {
            m_CullData.push_back(CullData(io));
        }
    }

    if (version >= 31 && version < 39) {
        m_FogNear = io.Read<float>();

        m_FogFar = io.Read<float>();
    }

    if (version >= 31) {
        m_FogColor = io.Read<vector3>();
    }

    if (version >= 36) {
        m_DirectionalLightColor = io.Read<vector3>();
    }

    if (version < 42) {
        m_StartPosition = io.Read<vector3>();
    }

    if (version >= 33 && version < 42) {
        m_StartRotation = io.Read<vector4>();
    }
}

void nejlika::world::LightingInformation::Save(nejlika::Writer &io, uint32_t version) const
{
    if (version >= 45) {
        io.Write(m_BlendTime);
    }

    io.Write(m_Ambient);

    io.Write(m_Specular);

    io.Write(m_UpperHemi);

    io.Write(m_Position);

    if (version >= 39) {
        m_MinDrawDistances.Save(io);
        m_MaxDrawDistances.Save(io);
    }

    if (version >= 40) {
        io.Write(static_cast<uint32_t>(m_CullData.size()));

        for (const CullData &cullData : m_CullData) {
            cullData.Save(io);
        }
    }

    if (version >= 31 && version < 39) {
        io.Write(m_FogNear);

        io.Write(m_FogFar);
    }

    if (version >= 31) {
        io.Write(m_FogColor);
    }

    if (version >= 36) {
        io.Write(m_DirectionalLightColor);
    }

    if (version < 42) {
        io.Write(m_StartPosition);
    }

    if (version >= 33 && version < 42) {
        io.Write(m_StartRotation);
    }
}

float nejlika::world::LightingInformation::GetBlendTime() const
{
    return m_BlendTime;
}

const vector3 &nejlika::world::LightingInformation::GetAmbient() const
{
    return m_Ambient;
}

const vector3 &nejlika::world::LightingInformation::GetSpecular() const
{
    return m_Specular;
}

const vector3 &nejlika::world::LightingInformation::GetUpperHemi() const
{
    return m_UpperHemi;
}

const vector3 &nejlika::world::LightingInformation::GetPosition() const
{
    return m_Position;
}

const SceneDrawDistances &nejlika::world::LightingInformation::GetMinDrawDistances() const
{
    return m_MinDrawDistances;
}

const SceneDrawDistances &nejlika::world::LightingInformation::GetMaxDrawDistances() const
{
    return m_MaxDrawDistances;
}

const std::vector<CullData> &nejlika::world::LightingInformation::GetCullData() const
{
    return m_CullData;
}

float nejlika::world::LightingInformation::GetFogNear() const
{
    return m_FogNear;
}

float nejlika::world::LightingInformation::GetFogFar() const
{
    return m_FogFar;
}

const vector3 &nejlika::world::LightingInformation::GetFogColor() const
{
    return m_FogColor;
}

const vector3 &nejlika::world::LightingInformation::GetDirectionalLightColor() const
{
    return m_DirectionalLightColor;
}

const vector3 &nejlika::world::LightingInformation::GetStartPosition() const
{
    return m_StartPosition;
}

const vector4 &nejlika::world::LightingInformation::GetStartRotation() const
{
    return m_StartRotation;
}

nejlika::world::LightingInformation::~LightingInformation()
{
}

