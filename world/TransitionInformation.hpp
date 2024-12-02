#pragma once

#include <string>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "Transition.hpp"

namespace nejlika::world
{

class TransitionInformation
{
public:
    TransitionInformation() = default;

    TransitionInformation(nejlika::Reader& io, version version);

    void Save(nejlika::Writer& io, version version) const;

    const std::vector<Transition>& GetTransitions() const;

    ~TransitionInformation();

private:
    std::vector<Transition> m_Transitions;
};

}