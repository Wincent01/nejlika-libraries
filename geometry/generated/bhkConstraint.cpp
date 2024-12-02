#include "bhkConstraint.hpp"

using namespace nejlika::geometry;

void bhkConstraint::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkSerializable::Read(reader, version, user, arg);

    m_NumEntities = reader.Read<uint>();

    m_Entities.resize(m_NumEntities);
    for (uint32_t i = 0; i < m_Entities.size(); i++)
    {
        m_Entities[i].Read(reader, version, user, 0);
    }

    m_Priority = reader.Read<uint>();

}

void bhkConstraint::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkSerializable::Write(writer, version, user, arg);

    writer.Write(m_NumEntities);

    for (uint32_t i = 0; i < m_Entities.size(); i++)
    {
        m_Entities[i].Write(writer, version, user, 0);
    }

    writer.Write(m_Priority);

}
