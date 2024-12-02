#include "NiGeomMorpherController.hpp"

using namespace nejlika::geometry;

void NiGeomMorpherController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiInterpController::Read(reader, version, user, arg);

    if (version >= VERSION_NUMBER(10, 0, 1, 2))
    {
        m_ExtraFlags = reader.Read<Flags>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_Unknown2 = reader.Read<byte>();
    }

    m_Data.Read(reader, version, user, 0);

    m_AlwaysUpdate = reader.Read<byte>();

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        m_NumInterpolators = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_Interpolators.resize(m_NumInterpolators);
        for (uint32_t i = 0; i < m_Interpolators.size(); i++)
        {
            m_Interpolators[i].Read(reader, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        m_InterpolatorWeights.resize(m_NumInterpolators);
        for (uint32_t i = 0; i < m_InterpolatorWeights.size(); i++)
        {
            m_InterpolatorWeights[i].Read(reader, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4) && version <= VERSION_NUMBER(20, 0, 0, 5) && (user>= 10))
    {
        m_NumUnknownInts = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4) && version <= VERSION_NUMBER(20, 0, 0, 5) && (user>= 10))
    {
        m_UnknownInts.resize(m_NumUnknownInts);
        for (uint32_t i = 0; i < m_UnknownInts.size(); i++)
        {
            m_UnknownInts[i] = reader.Read<uint>();
        }
    }

}

void NiGeomMorpherController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiInterpController::Write(writer, version, user, arg);

    if (version >= VERSION_NUMBER(10, 0, 1, 2))
    {
        writer.Write(m_ExtraFlags);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(10, 1, 0, 106))
    {
        writer.Write(m_Unknown2);
    }

    m_Data.Write(writer, version, user, 0);

    writer.Write(m_AlwaysUpdate);

    if (version >= VERSION_NUMBER(10, 1, 0, 106))
    {
        writer.Write(m_NumInterpolators);
    }

    if (version >= VERSION_NUMBER(10, 1, 0, 106) && version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        for (uint32_t i = 0; i < m_Interpolators.size(); i++)
        {
            m_Interpolators[i].Write(writer, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        for (uint32_t i = 0; i < m_InterpolatorWeights.size(); i++)
        {
            m_InterpolatorWeights[i].Write(writer, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4) && version <= VERSION_NUMBER(20, 0, 0, 5) && (user>= 10))
    {
        writer.Write(m_NumUnknownInts);
    }

    if (version >= VERSION_NUMBER(20, 0, 0, 4) && version <= VERSION_NUMBER(20, 0, 0, 5) && (user>= 10))
    {
        for (uint32_t i = 0; i < m_UnknownInts.size(); i++)
        {
            writer.Write(m_UnknownInts[i]);
        }
    }

}
