#include "Transition.hpp"


nejlika::world::Transition::Transition(nejlika::Reader &io, version version)
{
    m_Name = version < 40 ? io.ReadString<uint8_t>() : "";

    m_Unknown1 = version < 40 ? io.Read<float>() : 0.0f;

    uint32_t transitionPointCount = ((version <= 33 || version >= 39 ) ? 2 : 5);

    m_TransitionPoints.reserve(transitionPointCount);

    for (int i = 0; i < transitionPointCount; i++)
    {
        m_TransitionPoints.push_back(TransitionPoint(io, version));
    }
}

void nejlika::world::Transition::Save(nejlika::Writer &io, version version) const
{
    if (version < 40)
    {
        io.WriteString<uint8_t>(m_Name);
    }

    if (version < 40)
    {
        io.Write(m_Unknown1);
    }

    if (m_TransitionPoints.size() != ((version <= 33 || version >= 39) ? 2 : 5))
    {
        throw std::runtime_error("TransitionPoint size mismatch");
    }

    for (int i = 0; i < m_TransitionPoints.size(); i++)
    {
        m_TransitionPoints[i].Save(io, version);
    }
}

const std::string &nejlika::world::Transition::GetName() const
{
    return m_Name;
}

float nejlika::world::Transition::GetUnknown1() const
{
    return m_Unknown1;
}

const std::vector<nejlika::world::TransitionPoint> &nejlika::world::Transition::GetTransitionPoints() const
{
    return m_TransitionPoints;
}

nejlika::world::Transition::~Transition()
{
}

