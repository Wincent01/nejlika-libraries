#include "bhkSimpleShapePhantom.hpp"

using namespace nejlika::geometry;

void bhkSimpleShapePhantom::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkShapePhantom::Read(reader, version, user, arg);

    m_UnkownFloats.resize(7);
    for (uint32_t i = 0; i < m_UnkownFloats.size(); i++)
    {
        m_UnkownFloats[i] = reader.Read<float>();
    }

    m_UnknownFloats2.resize(3);
    for (uint32_t i = 0; i < m_UnknownFloats2.size(); i++)
    {
        m_UnknownFloats2[i].resize(5);
        for (uint32_t j = 0; j < m_UnknownFloats2[i].size(); j++)
        {
            m_UnknownFloats2[i][j] = reader.Read<float>();
        }
    }

    m_UnknownFloat = reader.Read<float>();

}

void bhkSimpleShapePhantom::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkShapePhantom::Write(writer, version, user, arg);

    for (uint32_t i = 0; i < m_UnkownFloats.size(); i++)
    {
        writer.Write(m_UnkownFloats[i]);
    }

    for (uint32_t i = 0; i < m_UnknownFloats2.size(); i++)
    {
        for (uint32_t j = 0; j < m_UnknownFloats2[i].size(); j++)
        {
            writer.Write(m_UnknownFloats2[i][j]);
        }
    }

    writer.Write(m_UnknownFloat);

}
