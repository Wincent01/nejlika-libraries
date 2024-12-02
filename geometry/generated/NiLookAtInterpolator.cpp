#include "NiLookAtInterpolator.hpp"

using namespace nejlika::geometry;

void NiLookAtInterpolator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiInterpolator::Read(reader, version, user, arg);

    m_UnknownShort = reader.Read<ushort>();

    m_LookAt.Read(reader, version, user, 0);

    m_Target.Read(reader, version, user, 0);

    if (version <= VERSION_NUMBER(20, 5, 0, 0))
    {
        m_Translation.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 5, 0, 0))
    {
        m_Rotation.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 5, 0, 0))
    {
        m_Scale = reader.Read<float>();
    }

    m_UnknownLink1.Read(reader, version, user, 0);

    m_UnknownLink2.Read(reader, version, user, 0);

    m_UnknownLink3.Read(reader, version, user, 0);

}

void NiLookAtInterpolator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiInterpolator::Write(writer, version, user, arg);

    writer.Write(m_UnknownShort);

    m_LookAt.Write(writer, version, user, 0);

    m_Target.Write(writer, version, user, 0);

    if (version <= VERSION_NUMBER(20, 5, 0, 0))
    {
        m_Translation.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 5, 0, 0))
    {
        m_Rotation.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(20, 5, 0, 0))
    {
        writer.Write(m_Scale);
    }

    m_UnknownLink1.Write(writer, version, user, 0);

    m_UnknownLink2.Write(writer, version, user, 0);

    m_UnknownLink3.Write(writer, version, user, 0);

}
