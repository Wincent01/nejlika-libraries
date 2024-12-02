#include "NiDynamicEffect.hpp"

using namespace nejlika::geometry;

void NiDynamicEffect::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiAVObject::Read(reader, version, user, arg);

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_SwitchState = reader.Read<bool>();
    }

    if (version <= VERSION_NUMBER(4, 0, 0, 2))
    {
        m_NumAffectedNodeListPointers = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_NumAffectedNodes = reader.Read<uint>();
    }

    if (version <= VERSION_NUMBER(4, 0, 0, 2))
    {
        m_AffectedNodeListPointers.resize(m_NumAffectedNodeListPointers);
        for (uint32_t i = 0; i < m_AffectedNodeListPointers.size(); i++)
        {
            m_AffectedNodeListPointers[i] = reader.Read<uint>();
        }
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_AffectedNodes.resize(m_NumAffectedNodes);
        for (uint32_t i = 0; i < m_AffectedNodes.size(); i++)
        {
            m_AffectedNodes[i].Read(reader, version, user, 0);
        }
    }

}

void NiDynamicEffect::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiAVObject::Write(writer, version, user, arg);

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        writer.Write(m_SwitchState);
    }

    if (version <= VERSION_NUMBER(4, 0, 0, 2))
    {
        writer.Write(m_NumAffectedNodeListPointers);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_NumAffectedNodes);
    }

    if (version <= VERSION_NUMBER(4, 0, 0, 2))
    {
        for (uint32_t i = 0; i < m_AffectedNodeListPointers.size(); i++)
        {
            writer.Write(m_AffectedNodeListPointers[i]);
        }
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 0))
    {
        for (uint32_t i = 0; i < m_AffectedNodes.size(); i++)
        {
            m_AffectedNodes[i].Write(writer, version, user, 0);
        }
    }

}
