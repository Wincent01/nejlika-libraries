#include "bhkMultiSphereShape.hpp"

using namespace nejlika::geometry;

void bhkMultiSphereShape::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkSphereRepShape::Read(reader, version, user, arg);

    m_UnknownFloat1 = reader.Read<float>();

    m_UnknownFloat2 = reader.Read<float>();

    m_NumSpheres = reader.Read<uint>();

    m_Spheres.resize(m_NumSpheres);
    for (uint32_t i = 0; i < m_Spheres.size(); i++)
    {
        m_Spheres[i].Read(reader, version, user, 0);
    }

}

void bhkMultiSphereShape::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkSphereRepShape::Write(writer, version, user, arg);

    writer.Write(m_UnknownFloat1);

    writer.Write(m_UnknownFloat2);

    writer.Write(m_NumSpheres);

    for (uint32_t i = 0; i < m_Spheres.size(); i++)
    {
        m_Spheres[i].Write(writer, version, user, 0);
    }

}
