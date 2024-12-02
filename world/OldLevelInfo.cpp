#include "OldLevelInfo.hpp"

using namespace nejlika::world;

nejlika::world::OldLevelInfo::OldLevelInfo(nejlika::Reader &io)
{
    m_Version = io.Read<uint16_t>();

    const uint32_t chunkVersion = io.Read<uint16_t>();

    if (m_Version != chunkVersion) {
        throw std::runtime_error("Version mismatch");
    }

    m_Unknown0 = io.Read<uint8_t>();

    if (m_Version >= 37) {
        m_Revision = io.Read<uint32_t>();
    }

    if (m_Version >= 45) {
        m_Unknown1 = io.Read<float>();
    }

    for (uint32_t i = 0; i < 12; i++) {
        m_UnknownArray1.push_back(io.Read<float>());
    }

    if (m_Version >= 31)
    {
        if (m_Version >= 39)
        {
            for (uint32_t i = 0; i < 12; i++)
            {
                m_UnknownArray2.push_back(io.Read<float>());
            }

            if (m_Version >= 40)
            {
                const auto cullDataSize = io.Read<uint32_t>();

                m_CullData.reserve(cullDataSize);

                for (uint32_t i = 0; i < cullDataSize; i++)
                {
                    m_CullData.push_back(CullData(io));
                }
            }
        }
        else
        {
            for (uint32_t i = 0; i < 2; i++)
            {
                m_UnknownArray3.push_back(io.Read<float>());
            }
        }

        for (uint32_t i = 0; i < 3; i++)
        {
            m_UnknownArray4.push_back(io.Read<float>());
        }
    }

    if (m_Version >= 36)
    {
        for (uint32_t i = 0; i < 3; i++)
        {
            m_UnknownArray5.push_back(io.Read<float>());
        }
    }

    if (m_Version < 42)
    {
        m_UnknownVector1 = io.Read<vector3>();

        if (m_Version >= 33)
        {
            for (uint32_t i = 0; i < 4; i++)
            {
                m_UnknownArray6.push_back(io.Read<float>());
            }
        }
    }

    for (uint32_t i = 0; i < 6; i++)
    {
        m_Skybox.push_back(io.ReadString<uint32_t>());
    }

    m_Unknown3 = io.Read<uint32_t>();

    if (m_Version > 36)
    {
        const auto unknownVectorArray1Size = io.Read<uint32_t>();

        m_UnknownVectorArray1.reserve(unknownVectorArray1Size);

        for (uint32_t i = 0; i < unknownVectorArray1Size; i++)
        {
            m_UnknownVectorArray1.push_back(io.Read<vector3>());
        }
    }
    else
    {
        m_Unknown4 = io.Read<uint32_t>();
    }
}

void nejlika::world::OldLevelInfo::Save(nejlika::Writer &io) const
{
    io.Write(m_Version);

    io.Write(m_Version);

    io.Write(m_Unknown0);

    if (m_Version >= 37) {
        io.Write(m_Revision);
    }

    if (m_Version >= 45) {
        io.Write(m_Unknown1);
    }

    for (const float &value : m_UnknownArray1) {
        io.Write(value);
    }

    if (m_Version >= 31)
    {
        if (m_Version >= 39)
        {
            for (const float &value : m_UnknownArray2)
            {
                io.Write(value);
            }

            if (m_Version >= 40)
            {
                io.Write<uint32_t>(m_CullData.size());

                for (const CullData &cullData : m_CullData)
                {
                    cullData.Save(io);
                }
            }
        }
        else
        {
            for (const float &value : m_UnknownArray3)
            {
                io.Write(value);
            }
        }

        for (const float &value : m_UnknownArray4)
        {
            io.Write(value);
        }
    }

    if (m_Version >= 36)
    {
        for (const float &value : m_UnknownArray5)
        {
            io.Write(value);
        }
    }

    if (m_Version < 42)
    {
        io.Write(m_UnknownVector1);

        if (m_Version >= 33)
        {
            for (const float &value : m_UnknownArray6)
            {
                io.Write(value);
            }
        }
    }

    for (const std::string &value : m_Skybox) {
        io.WriteString<uint32_t>(value);
    }

    io.Write(m_Unknown3);

    if (m_Version > 36)
    {
        io.Write<uint32_t>(m_UnknownVectorArray1.size());

        for (const vector3 &value : m_UnknownVectorArray1)
        {
            io.Write(value);
        }
    }
    else
    {
        io.Write(m_Unknown4);
    }
}

uint16_t nejlika::world::OldLevelInfo::GetVersion() const
{
    return m_Version;
}

uint32_t nejlika::world::OldLevelInfo::GetRevision() const
{
    return m_Revision;
}

uint8_t nejlika::world::OldLevelInfo::GetUnknown0() const
{
    return m_Unknown0;
}

float nejlika::world::OldLevelInfo::GetUnknown1() const
{
    return m_Unknown1;
}

const std::vector<nejlika::world::CullData> &nejlika::world::OldLevelInfo::GetCullData() const
{
    return m_CullData;
}

const std::vector<float> &nejlika::world::OldLevelInfo::GetUnknownArray1() const
{
    return m_UnknownArray1;
}

const std::vector<float> &nejlika::world::OldLevelInfo::GetUnknownArray2() const
{
    return m_UnknownArray2;
}

const std::vector<float> &nejlika::world::OldLevelInfo::GetUnknownArray3() const
{
    return m_UnknownArray3;
}

const std::vector<float> &nejlika::world::OldLevelInfo::GetUnknownArray4() const
{
    return m_UnknownArray4;
}

const std::vector<float> &nejlika::world::OldLevelInfo::GetUnknownArray5() const
{
    return m_UnknownArray5;
}

const std::vector<float> &nejlika::world::OldLevelInfo::GetUnknownArray6() const
{
    return m_UnknownArray6;
}

const vector3 &nejlika::world::OldLevelInfo::GetUnknownVector1() const
{
    return m_UnknownVector1;
}

const std::vector<std::string> &nejlika::world::OldLevelInfo::GetSkybox() const
{
    return m_Skybox;
}

const uint32_t &nejlika::world::OldLevelInfo::GetUnknown3() const
{
    return m_Unknown3;
}

const uint32_t &nejlika::world::OldLevelInfo::GetUnknown4() const
{
    return m_Unknown4;
}

const std::vector<vector3> &nejlika::world::OldLevelInfo::GetUnknownVectorArray1() const
{
    return m_UnknownVectorArray1;
}

nejlika::world::OldLevelInfo::~OldLevelInfo()
{
}
