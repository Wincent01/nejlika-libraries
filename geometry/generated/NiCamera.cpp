#include "NiCamera.hpp"

using namespace nejlika::geometry;

void NiCamera::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiAVObject::Read(reader, version, user, arg);

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_UnknownShort = reader.Read<ushort>();
    }

    m_FrustumLeft = reader.Read<float>();

    m_FrustumRight = reader.Read<float>();

    m_FrustumTop = reader.Read<float>();

    m_FrustumBottom = reader.Read<float>();

    m_FrustumNear = reader.Read<float>();

    m_FrustumFar = reader.Read<float>();

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_UseOrthographicProjection = reader.Read<bool>();
    }

    m_ViewportLeft = reader.Read<float>();

    m_ViewportRight = reader.Read<float>();

    m_ViewportTop = reader.Read<float>();

    m_ViewportBottom = reader.Read<float>();

    m_LODAdjust = reader.Read<float>();

    m_UnknownLink.Read(reader, version, user, 0);

    m_UnknownInt = reader.Read<uint>();

    if (version >= VERSION_NUMBER(4, 2, 1, 0))
    {
        m_UnknownInt2 = reader.Read<uint>();
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_UnknownInt3 = reader.Read<uint>();
    }

}

void NiCamera::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiAVObject::Write(writer, version, user, arg);

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_UnknownShort);
    }

    writer.Write(m_FrustumLeft);

    writer.Write(m_FrustumRight);

    writer.Write(m_FrustumTop);

    writer.Write(m_FrustumBottom);

    writer.Write(m_FrustumNear);

    writer.Write(m_FrustumFar);

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_UseOrthographicProjection);
    }

    writer.Write(m_ViewportLeft);

    writer.Write(m_ViewportRight);

    writer.Write(m_ViewportTop);

    writer.Write(m_ViewportBottom);

    writer.Write(m_LODAdjust);

    m_UnknownLink.Write(writer, version, user, 0);

    writer.Write(m_UnknownInt);

    if (version >= VERSION_NUMBER(4, 2, 1, 0))
    {
        writer.Write(m_UnknownInt2);
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        writer.Write(m_UnknownInt3);
    }

}
