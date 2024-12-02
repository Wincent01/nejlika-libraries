#include "NiPSSimulatorGeneralStep.hpp"

using namespace nejlika::geometry;

void NiPSSimulatorGeneralStep::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSSimulatorStep::Read(reader, version, user, arg);

    m_NumSizeKeys = reader.Read<byte>();

    m_SizeKeys.resize(m_NumSizeKeys);
    for (uint32_t i = 0; i < m_SizeKeys.size(); i++)
    {
        m_SizeKeys[i].Read(reader, version, user, 1);
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_SizeLoopBehavior = reader.Read<PSLoopBehavior>();
    }

    if (version <= VERSION_NUMBER(20, 6, 0, 0))
    {
        m_Unknown1 = reader.Read<float>();
    }

    if (version <= VERSION_NUMBER(20, 6, 0, 0))
    {
        m_Unknown2 = reader.Read<float>();
    }

    if (version <= VERSION_NUMBER(20, 6, 0, 0))
    {
        m_Unknown3 = reader.Read<float>();
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_NumColorKeys = reader.Read<byte>();
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_ColorKeys.resize(m_NumColorKeys);
        for (uint32_t i = 0; i < m_ColorKeys.size(); i++)
        {
            m_ColorKeys[i].Read(reader, version, user, 1);
        }
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_ColorLoopBehavior = reader.Read<PSLoopBehavior>();
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_NumRotationKeys = reader.Read<byte>();
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_RotationKeys.resize(m_NumRotationKeys);
        for (uint32_t i = 0; i < m_RotationKeys.size(); i++)
        {
            m_RotationKeys[i].Read(reader, version, user, 1);
        }
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_RotationLoopBehavior = reader.Read<PSLoopBehavior>();
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_GrowTime = reader.Read<float>();
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_ShrinkTime = reader.Read<float>();
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_GrowGeneration = reader.Read<ushort>();
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        m_ShrinkGeneration = reader.Read<ushort>();
    }

}

void NiPSSimulatorGeneralStep::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSSimulatorStep::Write(writer, version, user, arg);

    writer.Write(m_NumSizeKeys);

    for (uint32_t i = 0; i < m_SizeKeys.size(); i++)
    {
        m_SizeKeys[i].Write(writer, version, user, 1);
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        writer.Write(m_SizeLoopBehavior);
    }

    if (version <= VERSION_NUMBER(20, 6, 0, 0))
    {
        writer.Write(m_Unknown1);
    }

    if (version <= VERSION_NUMBER(20, 6, 0, 0))
    {
        writer.Write(m_Unknown2);
    }

    if (version <= VERSION_NUMBER(20, 6, 0, 0))
    {
        writer.Write(m_Unknown3);
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        writer.Write(m_NumColorKeys);
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        for (uint32_t i = 0; i < m_ColorKeys.size(); i++)
        {
            m_ColorKeys[i].Write(writer, version, user, 1);
        }
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        writer.Write(m_ColorLoopBehavior);
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        writer.Write(m_NumRotationKeys);
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        for (uint32_t i = 0; i < m_RotationKeys.size(); i++)
        {
            m_RotationKeys[i].Write(writer, version, user, 1);
        }
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        writer.Write(m_RotationLoopBehavior);
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        writer.Write(m_GrowTime);
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        writer.Write(m_ShrinkTime);
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        writer.Write(m_GrowGeneration);
    }

    if (version >= VERSION_NUMBER(30, 0, 0, 2))
    {
        writer.Write(m_ShrinkGeneration);
    }

}
