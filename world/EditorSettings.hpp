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

class EditorSettings
{
public:
    EditorSettings() = default;

    EditorSettings(nejlika::Reader& io);

    void Save(nejlika::Writer& io) const;

    const std::vector<vector3>& GetSavedColors() const;

    ~EditorSettings();

private:
    std::vector<vector3> m_SavedColors;
};

}