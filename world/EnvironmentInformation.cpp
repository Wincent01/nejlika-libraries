#include "EnvironmentInformation.hpp"

nejlika::world::EnvironmentInformation::EnvironmentInformation(nejlika::Reader &io, version version)
{
    const uint32_t currentPointer = io.GetReadHead();

    // Read lighting information
    io.SetReadHead(io.Read<uint32_t>());

    m_LightingInformation = LightingInformation(io, version);

    uint32_t finishedPointer = io.GetReadHead();

    io.SetReadHead(currentPointer + sizeof(uint32_t));

    // Read skydome information
    io.SetReadHead(io.Read<uint32_t>());

    // Make sure our current pointer is the finished pointer from the last chunk
    if (io.GetReadHead() != finishedPointer)
    {
        throw std::runtime_error("Invalid lighting information chunk size");
    }

    m_SkydomeInformation = SkydomeInformation(io, version);

    finishedPointer = io.GetReadHead();

    if (version >= 37)
    {
        io.SetReadHead(currentPointer + sizeof(uint32_t) * 2);

        // Read editor settings
        io.SetReadHead(io.Read<uint32_t>());

        // Make sure our current pointer is the finished pointer from the last chunk
        if (io.GetReadHead() != finishedPointer)
        {
            throw std::runtime_error("Invalid skydome information chunk size");
        }

        m_EditorSettings = EditorSettings(io);

        // io.SetReadHead(currentPointer + sizeof(uint32_t) * 3);
    }
}

void nejlika::world::EnvironmentInformation::Save(nejlika::Writer &io, version version) const
{
    auto offsetLighing = WritePointer(io);
    auto offsetSkydome = WritePointer(io);
    WritePointer offsetEditorSettings;
    if (version >= 37)
    {
        offsetEditorSettings = WritePointer(io);
    }

    offsetLighing.WriteAddress(io);
    m_LightingInformation.Save(io, version);

    offsetSkydome.WriteAddress(io);
    m_SkydomeInformation.Save(io, version);

    if (version >= 37)
    {
        offsetEditorSettings.WriteAddress(io);
        m_EditorSettings.Save(io);
    }
}

nejlika::world::LightingInformation &nejlika::world::EnvironmentInformation::GetLightingInformation()
{
    return m_LightingInformation;
}

nejlika::world::SkydomeInformation &nejlika::world::EnvironmentInformation::GetSkydomeInformation()
{
    return m_SkydomeInformation;
}

nejlika::world::EditorSettings &nejlika::world::EnvironmentInformation::GetEditorSettings()
{
    return m_EditorSettings;
}

const nejlika::world::LightingInformation &nejlika::world::EnvironmentInformation::GetLightingInformation() const
{
    return m_LightingInformation;
}

const nejlika::world::SkydomeInformation &nejlika::world::EnvironmentInformation::GetSkydomeInformation() const
{
    return m_SkydomeInformation;
}

const nejlika::world::EditorSettings &nejlika::world::EnvironmentInformation::GetEditorSettings() const
{
    return m_EditorSettings;
}

nejlika::world::EnvironmentInformation::~EnvironmentInformation()
{
}