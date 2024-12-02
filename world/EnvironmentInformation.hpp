#pragma once

#include <string>
#include <vector>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"
#include "WritePointer.hpp"
#include "LightingInformation.hpp"
#include "SkydomeInformation.hpp"
#include "EditorSettings.hpp"

namespace nejlika::world
{

class EnvironmentInformation
{
public:
    EnvironmentInformation() = default;

    EnvironmentInformation(nejlika::Reader& io, version version);

    void Save(nejlika::Writer& io, version version) const;

    LightingInformation& GetLightingInformation();

    SkydomeInformation& GetSkydomeInformation();

    EditorSettings& GetEditorSettings();

    ~EnvironmentInformation();

private:
    LightingInformation m_LightingInformation;
    SkydomeInformation m_SkydomeInformation;
    EditorSettings m_EditorSettings;
};

}