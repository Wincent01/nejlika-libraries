#include "Level.hpp"

#include <iostream>

using namespace nejlika::world;

nejlika::world::Level::Level(nejlika::Reader &io)
{
    uint32_t index = 1;

    bool hasInfo = false;

    while (io.GetSize() > io.GetReadHead())
    {
        const auto startPointer = io.GetReadHead();

        if ((io.GetReadHead() % 16) != 0)
        {
            throw std::runtime_error("Invalid chunk alignment");
        }

        // Read the first four bytes of the file
        uint32_t magic = io.Read<uint32_t>();

        // Make sure it's "CHNK"
        if (magic != ('C' | ('H' << 8) | ('N' << 16) | ('K' << 24)))
        {
            if (io.GetReadHead() != sizeof(uint32_t))
            {
                throw std::runtime_error("Invalid chunk format");
            }

            // Set the write head to the beginning of the file
            io.SetReadHead(0);

            m_OldInfo = OldLevelInfo(io);

            m_Objects = LevelObjects(io, m_OldInfo.GetVersion());

            return;
        }

        uint32_t chunkType = io.Read<uint32_t>();

        if (chunkType != 1000 && !hasInfo)
        {
            throw std::runtime_error("Missing level info or invalid chunk order");
        }

        uint16_t headerVersion = io.Read<uint16_t>();
        uint16_t dataVersion = io.Read<uint16_t>();

        if (headerVersion != 1)
        {
            throw std::runtime_error("Invalid header version");
        }

        if (dataVersion > 3)
        {
            throw std::runtime_error("Invalid data version");
        }

        uint32_t chunkSize = io.Read<uint32_t>();

        uint32_t pointer = io.Read<uint32_t>();

        if ((pointer % 16) != 0)
        {
            throw std::runtime_error("Invalid chunk alignment");
        }

        io.SetReadHead(pointer);

        switch (chunkType)
        {
        case 1000:
            m_Info = LevelInfo(io, headerVersion);

            hasInfo = true;
            break;
        case 2000:
            if (startPointer != m_Info.GetEnvironmentInformationReadPointer())
            {
                throw std::runtime_error("Invalid chunk start pointer for environment information");
            }

            m_EnvironmentInformation = EnvironmentInformation(io, GetVersion());

            m_HasEnvironmentInformation = true;
            break;
        case 2001:
            if (startPointer != m_Info.GetObjectsReadPointer())
            {
                throw std::runtime_error("Invalid chunk start pointer for level objects");
            }

            m_Objects = LevelObjects(io, GetVersion());

            m_HasObjects = true;
            break;
        case 2002:
            if (startPointer != m_Info.GetParticleInformationReadPointer())
            {
                throw std::runtime_error("Invalid chunk start pointer for particle information");
            }

            m_ParticleInformation = ParticleInformation(io, GetVersion());

            m_HasParticleInformation = true;
            break;
        default:
            break;
        }

        // Align the read head to the next 16 byte boundary
        while (io.GetReadHead() % 16 != 0)
        {
            uint8_t alignByte = io.Read<uint8_t>();

            if (alignByte != 0xCD)
            {
                throw std::runtime_error("Invalid chunk alignment byte");
            }
        }

        if (io.GetReadHead() != (startPointer + chunkSize))
        {
            // Check that every byte until the end of the chunk is 0xCD
            for (uint32_t i = io.GetReadHead(); i < (startPointer + chunkSize); ++i)
            {
                uint8_t alignByte = io.Read<uint8_t>();

                if (alignByte != 0xCD)
                {
                    throw std::runtime_error("Invalid chunk alignment byte");
                }
            }
        }

        io.SetReadHead(startPointer + chunkSize);

        ++index;
    }

    if (!hasInfo)
    {
        throw std::runtime_error("Missing level info");
    }
}

void nejlika::world::Level::Save(nejlika::Writer &io)
{
    if (IsOld())
    {
        m_OldInfo.Save(io);

        m_Objects.Save(io, GetVersion());

        io.Write<uint64_t>(0);

        return;
    }

    WriteHeader(io, 1000, 1, 1);

    auto sizePointer = WritePointer(io);
    auto infoPointer = WritePointer(io);

    Align(io);
    infoPointer.WriteAddress(io);

    m_Info.Save(io);

    Align(io);
    sizePointer.WriteAddress(io);

    if (!m_HasEnvironmentInformation)
        m_Info.GetEnvironmentInformationPointer().WriteZero(io);
    if (!m_HasObjects)
        m_Info.GetObjectsPointer().WriteZero(io);
    if (!m_HasParticleInformation)
        m_Info.GetParticleInformationPointer().WriteZero(io);

    if (m_HasEnvironmentInformation)
    {
        m_Info.GetEnvironmentInformationPointer().WriteAddress(io);

        auto sizeReference = io.GetWriteHead();

        WriteHeader(io, 2000, 1, 2);

        auto sizeAddress = io.GetWriteHead();
        io.Write<uint32_t>(0);

        auto environmentInformationPointer = WritePointer(io);

        Align(io);
        environmentInformationPointer.WriteAddress(io);

        m_EnvironmentInformation.Save(io, GetVersion());

        Align(io);

        auto endAddress = io.GetWriteHead();
        io.SetWriteHead(sizeAddress);
        io.Write<uint32_t>(endAddress - sizeReference);
        io.SetWriteHead(endAddress);
    }

    if (m_HasObjects)
    {
        m_Info.GetObjectsPointer().WriteAddress(io);

        auto sizeReference = io.GetWriteHead();

        WriteHeader(io, 2001, 1, 1);

        auto sizeAddress = io.GetWriteHead();
        io.Write<uint32_t>(0);

        auto objectsPointer = WritePointer(io);

        Align(io);
        objectsPointer.WriteAddress(io);

        m_Objects.Save(io, GetVersion());

        Align(io);

        auto endAddress = io.GetWriteHead();
        io.SetWriteHead(sizeAddress);
        io.Write<uint32_t>(endAddress - sizeReference);
        io.SetWriteHead(endAddress);
    }

    if (m_HasParticleInformation)
    {
        m_Info.GetParticleInformationPointer().WriteAddress(io);

        auto sizeReference = io.GetWriteHead();

        WriteHeader(io, 2002, 1, 1);

        auto sizeAddress = io.GetWriteHead();
        io.Write<uint32_t>(0);

        auto particleInformationPointer = WritePointer(io);

        Align(io);
        particleInformationPointer.WriteAddress(io);

        m_ParticleInformation.Save(io, GetVersion());

        Align(io);

        auto endAddress = io.GetWriteHead();
        io.SetWriteHead(sizeAddress);
        io.Write<uint32_t>(endAddress - sizeReference);
        io.SetWriteHead(endAddress);
    }
}

OldLevelInfo &nejlika::world::Level::GetOldInfo()
{
    return m_OldInfo;
}

LevelInfo &nejlika::world::Level::GetInfo()
{
    return m_Info;
}

EnvironmentInformation &nejlika::world::Level::GetEnvironmentInformation()
{
    return m_EnvironmentInformation;
}

LevelObjects &nejlika::world::Level::GetObjects()
{
    return m_Objects;
}

ParticleInformation &nejlika::world::Level::GetParticleInformation()
{
    return m_ParticleInformation;
}

bool nejlika::world::Level::IsOld() const
{
    return m_OldInfo.GetVersion() != 0;
}

bool nejlika::world::Level::HasEnvironmentInformation() const
{
    return m_HasEnvironmentInformation;
}

bool nejlika::world::Level::HasObjects() const
{
    return m_HasObjects;
}

bool nejlika::world::Level::HasParticleInformation() const
{
    return m_HasParticleInformation;
}

version nejlika::world::Level::GetVersion() const
{
    return IsOld() ? m_OldInfo.GetVersion() : m_Info.GetVersion();
}

void nejlika::world::Level::SetVersion(version version)
{
    if (IsOld())
    {
        m_OldInfo.SetVersion(version);
    }
    else
    {
        m_Info.SetVersion(version);
    }
}

void nejlika::world::Level::SetEnvironmentInformation(EnvironmentInformation &environmentInformation)
{
    m_EnvironmentInformation = environmentInformation;

    m_HasEnvironmentInformation = true;
}

void nejlika::world::Level::SetObjects(LevelObjects &objects)
{
    m_Objects = objects;

    m_HasObjects = true;
}

void nejlika::world::Level::SetParticleInformation(ParticleInformation &particleInformation)
{
    m_ParticleInformation = particleInformation;

    m_HasParticleInformation = true;
}

void nejlika::world::Level::SetOldInfo(OldLevelInfo &oldInfo)
{
    m_OldInfo = oldInfo;
}

void nejlika::world::Level::SetHasEnvironmentInformation(bool hasEnvironmentInformation)
{
    m_HasEnvironmentInformation = hasEnvironmentInformation;
}

void nejlika::world::Level::SetHasObjects(bool hasObjects)
{
    m_HasObjects = hasObjects;
}

void nejlika::world::Level::SetHasParticleInformation(bool hasParticleInformation)
{
    m_HasParticleInformation = hasParticleInformation;
}

nejlika::world::Level::~Level()
{
}

bool nejlika::world::Level::IsOld(nejlika::Reader &io)
{
    if (io.GetSize() < sizeof(uint32_t))
        return true;

    const auto position = io.GetReadHead();

    uint32_t magic = io.Read<uint32_t>();

    io.SetReadHead(position);

    return magic != ('C' | ('H' << 8) | ('N' << 16) | ('K' << 24));
}

void nejlika::world::Level::WriteHeader(nejlika::Writer &io, uint32_t chunkType, uint32_t headerVersion, uint32_t dataVersion)
{
    const static uint32_t magic = ('C' | ('H' << 8) | ('N' << 16) | ('K' << 24));

    io.Write(magic);

    io.Write<uint32_t>(chunkType);
    io.Write<uint16_t>(headerVersion);
    io.Write<uint16_t>(dataVersion);
}

void nejlika::world::Level::Align(nejlika::Writer &io)
{
    while (io.GetWriteHead() % 16 != 0)
    {
        io.Write<uint8_t>(0xCD);
    }
}
