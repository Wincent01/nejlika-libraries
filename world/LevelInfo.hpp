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

    ~LevelInfo();

private:
    uint32_t m_HeaderVersion;

    uint32_t m_Version;
    uint32_t m_Revision;

    uint32_t m_EnvironmentInformationReadPointer;
    uint32_t m_ObjectsReadPointer;
    uint32_t m_ParticleInformationReadPointer;
    
    WritePointer m_EnvironmentInformationPointer;
    WritePointer m_ObjectsPointer;
    WritePointer m_ParticleInformationPointer;
};

}