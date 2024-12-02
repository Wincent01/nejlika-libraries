#include "LevelInfo.hpp"

using namespace nejlika::world;

nejlika::world::LevelInfo::LevelInfo(nejlika::Reader &io, uint32_t headerVersion)
{
    m_HeaderVersion = headerVersion;

    m_Version = io.Read<uint32_t>();
    m_Revision = io.Read<uint32_t>();

    m_EnvironmentInformationReadPointer = io.Read<uint32_t>();
    m_ObjectsReadPointer = io.Read<uint32_t>();
    m_ParticleInformationReadPointer = io.Read<uint32_t>();
}

void nejlika::world::LevelInfo::Save(nejlika::Writer &io)
{
    io.Write(m_Version);
    io.Write(m_Revision);

    m_EnvironmentInformationPointer = WritePointer(io);
    m_ObjectsPointer = WritePointer(io);
    m_ParticleInformationPointer = WritePointer(io);
}

uint32_t nejlika::world::LevelInfo::GetHeaderVersion() const
{
    return m_HeaderVersion;
}

uint32_t nejlika::world::LevelInfo::GetVersion() const
{
    return m_Version;
}

uint32_t nejlika::world::LevelInfo::GetRevision() const
{
    return m_Revision;
}

uint32_t nejlika::world::LevelInfo::GetEnvironmentInformationReadPointer() const
{
    return m_EnvironmentInformationReadPointer;
}

uint32_t nejlika::world::LevelInfo::GetObjectsReadPointer() const
{
    return m_ObjectsReadPointer;
}

uint32_t nejlika::world::LevelInfo::GetParticleInformationReadPointer() const
{
    return m_ParticleInformationReadPointer;
}

WritePointer &nejlika::world::LevelInfo::GetEnvironmentInformationPointer()
{
    return m_EnvironmentInformationPointer;
}

WritePointer &nejlika::world::LevelInfo::GetObjectsPointer()
{
    return m_ObjectsPointer;
}

WritePointer &nejlika::world::LevelInfo::GetParticleInformationPointer()
{
    return m_ParticleInformationPointer;
}

nejlika::world::LevelInfo::~LevelInfo()
{
}
