#include "PathInformation.hpp"

nejlika::world::PathInformation::PathInformation(nejlika::Reader &io, version version)
{
    m_PathVersion = io.Read<::version>();
    
    uint32_t pathCount = io.Read<uint32_t>();

    m_Paths.reserve(pathCount);

    for (int i = 0; i < pathCount; i++)
    {
        m_Paths.push_back(Path(io, m_PathVersion));
    }
}

void nejlika::world::PathInformation::Save(nejlika::Writer &io, version version) const
{
    io.Write(m_PathVersion);

    io.Write(static_cast<uint32_t>(m_Paths.size()));

    for (int i = 0; i < m_Paths.size(); i++)
    {
        m_Paths[i].Save(io, m_PathVersion);
    }
}

version nejlika::world::PathInformation::GetPathVersion() const
{
    return m_PathVersion;
}

std::vector<nejlika::world::Path> &nejlika::world::PathInformation::GetPaths()
{
    return m_Paths;
}

nejlika::world::PathInformation::~PathInformation()
{
}

