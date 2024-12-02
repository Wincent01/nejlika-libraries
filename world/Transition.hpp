#pragma once

#include <string>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "TransitionPoint.hpp"

namespace nejlika::world
{

class Transition
{
public:
    Transition(nejlika::Reader& io, version version);

    void Save(nejlika::Writer& io, version version) const;

    const std::string& GetName() const;

    float GetUnknown1() const;

    const std::vector<TransitionPoint>& GetTransitionPoints() const;

    ~Transition();

private:
    std::string m_Name;

    float m_Unknown1;

    std::vector<TransitionPoint> m_TransitionPoints;
};

}