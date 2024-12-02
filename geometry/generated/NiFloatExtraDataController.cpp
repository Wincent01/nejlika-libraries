#include "NiFloatExtraDataController.hpp"

using namespace nejlika::geometry;

void NiFloatExtraDataController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiExtraDataController::Read(reader, version, user, arg);

    if (version >= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_ControllerData.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_NumExtraBytes = reader.Read<byte>();
    }

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_UnknownBytes.resize(7);
        for (uint32_t i = 0; i < m_UnknownBytes.size(); i++)
        {
            m_UnknownBytes[i] = reader.Read<byte>();
        }
    }

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_UnknownExtraBytes.resize(m_NumExtraBytes);
        for (uint32_t i = 0; i < m_UnknownExtraBytes.size(); i++)
        {
            m_UnknownExtraBytes[i] = reader.Read<byte>();
        }
    }

}

void NiFloatExtraDataController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiExtraDataController::Write(writer, version, user, arg);

    if (version >= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_ControllerData.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        writer.Write(m_NumExtraBytes);
    }

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        for (uint32_t i = 0; i < m_UnknownBytes.size(); i++)
        {
            writer.Write(m_UnknownBytes[i]);
        }
    }

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        for (uint32_t i = 0; i < m_UnknownExtraBytes.size(); i++)
        {
            writer.Write(m_UnknownExtraBytes[i]);
        }
    }

}
