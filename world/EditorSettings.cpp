#include "EditorSettings.hpp"

nejlika::world::EditorSettings::EditorSettings(nejlika::Reader &io)
{
    const uint32_t chunkSize = io.Read<uint32_t>();

    const uint32_t currentPointer = io.GetReadHead();

    const uint32_t numberOfColors = io.Read<uint32_t>();

    m_SavedColors.reserve(numberOfColors);

    for (uint32_t i = 0; i < numberOfColors; ++i) {
        m_SavedColors.push_back(io.Read<vector3>());
    }

    // Make sure we read the entire chunk
    if (io.GetReadHead() != (currentPointer + chunkSize)) {
        throw std::runtime_error("Invalid editior settings chunk size");
    }
}

void nejlika::world::EditorSettings::Save(nejlika::Writer &io) const
{
    const uint32_t startPointer = io.GetWriteHead();

    io.Write<uint32_t>(0);

    const uint32_t currentPointer = io.GetWriteHead();

    io.Write<uint32_t>(m_SavedColors.size());

    for (const vector3& color : m_SavedColors) {
        io.Write(color);
    }

    const uint32_t chunkSize = io.GetWriteHead() - currentPointer;

    io.SetWriteHead(startPointer);

    io.Write(chunkSize);

    io.SetWriteHead(currentPointer + chunkSize);
}

const std::vector<vector3>& nejlika::world::EditorSettings::GetSavedColors() const
{
    return m_SavedColors;
}

nejlika::world::EditorSettings::~EditorSettings()
{
}
