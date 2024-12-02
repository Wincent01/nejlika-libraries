#include "Footer.hpp"

using namespace nejlika::geometry;

void Footer::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    if (version >= VERSION_NUMBER(3, 3, 0, 13))
    {
        m_NumRoots = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(3, 3, 0, 13))
    {
        m_Roots.resize(m_NumRoots);
        for (uint32_t i = 0; i < m_Roots.size(); i++)
        {
            m_Roots[i].Read(reader, version, user, 0);
        }
    }

}

void Footer::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    if (version >= VERSION_NUMBER(3, 3, 0, 13))
    {
        writer.Write(m_NumRoots);
    }

    if (version >= VERSION_NUMBER(3, 3, 0, 13))
    {
        for (uint32_t i = 0; i < m_Roots.size(); i++)
        {
            m_Roots[i].Write(writer, version, user, 0);
        }
    }

}
