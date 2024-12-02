#include "NiTransformInterpolator.hpp"

using namespace nejlika::geometry;

void NiTransformInterpolator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiKeyBasedInterpolator::Read(reader, version, user, arg);

    m_Translation.Read(reader, version, user, 0);

    m_Rotation.Read(reader, version, user, 0);

    m_Scale = reader.Read<float>();

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_UnknownBytes.resize(3);
        for (uint32_t i = 0; i < m_UnknownBytes.size(); i++)
        {
            m_UnknownBytes[i] = reader.Read<byte>();
        }
    }

    m_Data.Read(reader, version, user, 0);

}

void NiTransformInterpolator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiKeyBasedInterpolator::Write(writer, version, user, arg);

    m_Translation.Write(writer, version, user, 0);

    m_Rotation.Write(writer, version, user, 0);

    writer.Write(m_Scale);

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(10, 1, 0, 106))
    {
        for (uint32_t i = 0; i < m_UnknownBytes.size(); i++)
        {
            writer.Write(m_UnknownBytes[i]);
        }
    }

    m_Data.Write(writer, version, user, 0);

}
