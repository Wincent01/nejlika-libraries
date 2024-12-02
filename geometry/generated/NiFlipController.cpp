#include "NiFlipController.hpp"

using namespace nejlika::geometry;

void NiFlipController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiFloatInterpController::Read(reader, version, user, arg);

    m_TextureSlot = reader.Read<TexType>();

    if (version >= VERSION_NUMBER(4, 0, 0, 0) && version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_UnknownInt2 = reader.Read<uint>();
    }

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_Delta = reader.Read<float>();
    }

    m_NumSources = reader.Read<uint>();

    if (version >= VERSION_NUMBER(4, 0, 0, 0))
    {
        m_Sources.resize(m_NumSources);
        for (uint32_t i = 0; i < m_Sources.size(); i++)
        {
            m_Sources[i].Read(reader, version, user, 0);
        }
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        m_Images.resize(m_NumSources);
        for (uint32_t i = 0; i < m_Images.size(); i++)
        {
            m_Images[i].Read(reader, version, user, 0);
        }
    }

}

void NiFlipController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiFloatInterpController::Write(writer, version, user, arg);

    writer.Write(m_TextureSlot);

    if (version >= VERSION_NUMBER(4, 0, 0, 0) && version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_UnknownInt2);
    }

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_Delta);
    }

    writer.Write(m_NumSources);

    if (version >= VERSION_NUMBER(4, 0, 0, 0))
    {
        for (uint32_t i = 0; i < m_Sources.size(); i++)
        {
            m_Sources[i].Write(writer, version, user, 0);
        }
    }

    if (version <= VERSION_NUMBER(0, 0, 3, 1))
    {
        for (uint32_t i = 0; i < m_Images.size(); i++)
        {
            m_Images[i].Write(writer, version, user, 0);
        }
    }

}
