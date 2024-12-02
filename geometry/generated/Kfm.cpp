#include "Kfm.hpp"

using namespace nejlika::geometry;

void Kfm::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_HeaderString = "";
    // Read until 0x0A
    while (true)
    {
        char c = reader.Read<char>();
        if (c == 0x0A)
        {
            break;
        }
        m_HeaderString += c;
    }

    // Header String in the format like this: ";Gamebryo KFM File Version 2.2.0.0b"
    // Parse the 2.2.0.0b part to get the version number
    std::string versionString = m_HeaderString.substr(m_HeaderString.find("Version") + 8);
    std::string major = versionString.substr(0, versionString.find("."));
    versionString = versionString.substr(versionString.find(".") + 1);
    std::string minor = versionString.substr(0, versionString.find("."));
    versionString = versionString.substr(versionString.find(".") + 1);
    std::string build = versionString.substr(0, versionString.find("."));
    versionString = versionString.substr(versionString.find(".") + 1);
    std::string revision = versionString.substr(0, versionString.find("b") == std::string::npos ? versionString.size() : versionString.find("b"));

    version = VERSION_NUMBER(std::stoi(major), std::stoi(minor), std::stoi(build), std::stoi(revision));

    if (version >= VERSION_NUMBER(0, 0, 0, 33554432))
    {
        m_EndianType = reader.Read<EndianType>();
    }

    if (version >= VERSION_NUMBER(0, 0, 0, 16909312))
    {
        m_NIFFileName.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(0, 0, 0, 16909312))
    {
        m_Master.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(0, 0, 0, 16909312))
    {
        m_UnknownInt1 = reader.Read<int>();
    }

    if (version >= VERSION_NUMBER(0, 0, 0, 16909312))
    {
        m_UnknownInt2 = reader.Read<int>();
    }

    if (version >= VERSION_NUMBER(0, 0, 0, 16909312))
    {
        m_UnknownFloat1 = reader.Read<float>();
    }

    if (version >= VERSION_NUMBER(0, 0, 0, 16909312))
    {
        m_UnknownFloat2 = reader.Read<float>();
    }

    if (version >= VERSION_NUMBER(0, 0, 0, 16909312))
    {
        m_NumAnimations = reader.Read<int>();
    }

    if (version >= VERSION_NUMBER(0, 0, 0, 16909312))
    {
        m_Animations.resize(m_NumAnimations);
        for (uint32_t i = 0; i < m_Animations.size(); i++)
        {
            m_Animations[i].Read(reader, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(0, 0, 0, 16909312))
    {
        m_UnknownInt3 = reader.Read<int>();
    }

}

void Kfm::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_HeaderString);

    if (version >= VERSION_NUMBER(0, 0, 0, 33554432))
    {
        writer.Write(m_EndianType);
    }

    if (version >= VERSION_NUMBER(0, 0, 0, 16909312))
    {
        m_NIFFileName.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(0, 0, 0, 16909312))
    {
        m_Master.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(0, 0, 0, 16909312))
    {
        writer.Write(m_UnknownInt1);
    }

    if (version >= VERSION_NUMBER(0, 0, 0, 16909312))
    {
        writer.Write(m_UnknownInt2);
    }

    if (version >= VERSION_NUMBER(0, 0, 0, 16909312))
    {
        writer.Write(m_UnknownFloat1);
    }

    if (version >= VERSION_NUMBER(0, 0, 0, 16909312))
    {
        writer.Write(m_UnknownFloat2);
    }

    if (version >= VERSION_NUMBER(0, 0, 0, 16909312))
    {
        writer.Write(m_NumAnimations);
    }

    if (version >= VERSION_NUMBER(0, 0, 0, 16909312))
    {
        for (uint32_t i = 0; i < m_Animations.size(); i++)
        {
            m_Animations[i].Write(writer, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(0, 0, 0, 16909312))
    {
        writer.Write(m_UnknownInt3);
    }

}
