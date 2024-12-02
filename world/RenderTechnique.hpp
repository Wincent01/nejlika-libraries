#pragma once

#include <string>
#include <vector>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"
#include "WritePointer.hpp"
#include "RenderAttribute.hpp"

namespace nejlika::world
{

class RenderTechnique
{
public:
    RenderTechnique() = default;

    RenderTechnique(nejlika::Reader& io);

    void Save(nejlika::Writer& io) const;

    const std::string& GetName() const;

    const std::vector<RenderAttribute>& GetAttributes() const;

    ~RenderTechnique();

private:
    std::string m_Name;
    std::vector<RenderAttribute> m_Attributes;
};


}