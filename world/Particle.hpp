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

class Particle
{
public:
    Particle() = default;

    Particle(nejlika::Reader& io, uint32_t version);

    void Save(nejlika::Writer& io, uint32_t version) const;

    uint16_t GetPriority() const;

    const vector3& GetPosition() const;

    const vector4& GetRotation() const;

    const std::u16string& GetEffectNames() const;

    const std::u16string& GetConfigData() const;

    void SetPriority(uint16_t priority);

    void SetPosition(const vector3& position);

    void SetRotation(const vector4& rotation);

    void SetEffectNames(const std::u16string& effectNames);

    void SetConfigData(const std::u16string& configData);

    ~Particle();

private:
    uint16_t m_Priority;
    vector3 m_Position;
    vector4 m_Rotation;
    std::u16string m_EffectNames;
    std::u16string m_ConfigData;
};

}