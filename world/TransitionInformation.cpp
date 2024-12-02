#include "TransitionInformation.hpp"

nejlika::world::TransitionInformation::TransitionInformation(nejlika::Reader &io, version version)
{
    uint32_t transitionCount = io.Read<uint32_t>();

    m_Transitions.reserve(transitionCount);

    for (int i = 0; i < transitionCount; i++)
    {
        m_Transitions.push_back(Transition(io, version));
    }
}

void nejlika::world::TransitionInformation::Save(nejlika::Writer &io, version version) const
{
    io.Write(static_cast<uint32_t>(m_Transitions.size()));

    for (int i = 0; i < m_Transitions.size(); i++)
    {
        m_Transitions[i].Save(io, version);
    }
}

const std::vector<nejlika::world::Transition> &nejlika::world::TransitionInformation::GetTransitions() const
{
    return m_Transitions;
}

nejlika::world::TransitionInformation::~TransitionInformation()
{
}
