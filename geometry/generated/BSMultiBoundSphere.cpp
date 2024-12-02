#include "BSMultiBoundSphere.hpp"

using namespace nejlika::geometry;

void BSMultiBoundSphere::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    BSMultiBoundData::Read(reader, version, user, arg);

    m_UnknownInt1 = reader.Read<int>();

    m_UnknownInt2 = reader.Read<int>();

    m_UnknownInt3 = reader.Read<int>();

    m_Radius = reader.Read<float>();

}

void BSMultiBoundSphere::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    BSMultiBoundData::Write(writer, version, user, arg);

    writer.Write(m_UnknownInt1);

    writer.Write(m_UnknownInt2);

    writer.Write(m_UnknownInt3);

    writer.Write(m_Radius);

}
