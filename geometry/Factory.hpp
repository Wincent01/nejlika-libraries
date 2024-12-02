#pragma once

#include "Construct.hpp"

namespace nejlika::geometry {

class Factory
{
public:
    static Construct* Create(const std::string& name);
};

}