#include "NiBSplineData.hpp"

using namespace nejlika::geometry;

void NiBSplineData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_NumFloatControlPoints = reader.Read<uint>();

    m_FloatControlPoints.resize(m_NumFloatControlPoints);
    for (uint32_t i = 0; i < m_FloatControlPoints.size(); i++)
    {
        m_FloatControlPoints[i] = reader.Read<float>();
    }

    m_NumShortControlPoints = reader.Read<uint>();

    m_ShortControlPoints.resize(m_NumShortControlPoints);
    for (uint32_t i = 0; i < m_ShortControlPoints.size(); i++)
    {
        m_ShortControlPoints[i] = reader.Read<short>();
    }

}

void NiBSplineData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    writer.Write(m_NumFloatControlPoints);

    for (uint32_t i = 0; i < m_FloatControlPoints.size(); i++)
    {
        writer.Write(m_FloatControlPoints[i]);
    }

    writer.Write(m_NumShortControlPoints);

    for (uint32_t i = 0; i < m_ShortControlPoints.size(); i++)
    {
        writer.Write(m_ShortControlPoints[i]);
    }

}
