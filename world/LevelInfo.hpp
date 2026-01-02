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

class LevelInfo
{
public:
    LevelInfo() = default;

    LevelInfo(nejlika::Reader& io, uint32_t headerVersion);

    void Save(nejlika::Writer& io);

    uint32_t GetHeaderVersion() const;

    uint32_t GetVersion() const;

    uint32_t GetRevision() const;

    uint32_t GetEnvironmentInformationReadPointer() const;

    uint32_t GetObjectsReadPointer() const;

    uint32_t GetParticleInformationReadPointer() const;

    WritePointer& GetEnvironmentInformationPointer();

    WritePointer& GetObjectsPointer();

    WritePointer& GetParticleInformationPointer();

    void SetHeaderVersion(uint32_t headerVersion);

    void SetVersion(uint32_t version);

    void SetRevision(uint32_t revision);

    ~LevelInfo();

private:
    uint32_t m_HeaderVersion = 1;

    uint32_t m_Version = 48;
    uint32_t m_Revision = 0;

    uint32_t m_EnvironmentInformationReadPointer = 0;
    uint32_t m_ObjectsReadPointer = 0;
    uint32_t m_ParticleInformationReadPointer = 0;

    WritePointer m_EnvironmentInformationPointer;
    WritePointer m_ObjectsPointer;
    WritePointer m_ParticleInformationPointer;
};

} // namespace nejlika::world