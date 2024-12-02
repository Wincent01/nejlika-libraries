#include "Particle.hpp"

nejlika::world::Particle::Particle(nejlika::Reader &io, uint32_t version)
{
    if (version >= 43)
    {
        m_Priority = io.Read<uint16_t>();
    }
    else
    {
        m_Priority = 0;
    }

    m_Position = io.Read<vector3>();

    m_Rotation = io.Read<vector4>();

    m_EffectNames = io.ReadString16<uint32_t>();

    if (version < 46)
    {
        const uint16_t nullTerminator = io.Read<uint16_t>();

        if (nullTerminator != 0)
        {
            throw std::runtime_error("Invalid null terminator");
        }
    }

    if (version > 45)
    {
        m_ConfigData = io.ReadString16<uint32_t>();
    }
}

void nejlika::world::Particle::Save(nejlika::Writer &io, uint32_t version) const
{
    if (version >= 43)
    {
        io.Write<uint16_t>(m_Priority);
    }

    io.Write(m_Position);

    io.Write(m_Rotation);

    io.WriteString16<uint32_t>(m_EffectNames);

    if (version < 46)
    {
        io.Write<uint16_t>(0);
    }

    if (version > 45)
    {
        io.WriteString16<uint32_t>(m_ConfigData);
    }
}

uint16_t nejlika::world::Particle::GetPriority() const
{
    return m_Priority;
}

const vector3 &nejlika::world::Particle::GetPosition() const
{
    return m_Position;
}

const vector4 &nejlika::world::Particle::GetRotation() const
{
    return m_Rotation;
}

const std::u16string &nejlika::world::Particle::GetEffectNames() const
{
    return m_EffectNames;
}

const std::u16string &nejlika::world::Particle::GetConfigData() const
{
    return m_ConfigData;
}

void nejlika::world::Particle::SetPriority(uint16_t priority)
{
    m_Priority = priority;
}

void nejlika::world::Particle::SetPosition(const vector3 &position)
{
    m_Position = position;
}

void nejlika::world::Particle::SetRotation(const vector4 &rotation)
{
    m_Rotation = rotation;
}

void nejlika::world::Particle::SetEffectNames(const std::u16string &effectNames)
{
    m_EffectNames = effectNames;
}

void nejlika::world::Particle::SetConfigData(const std::u16string &configData)
{
    m_ConfigData = configData;
}

nejlika::world::Particle::~Particle()
{
}
