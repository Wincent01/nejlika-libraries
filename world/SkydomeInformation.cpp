#include "SkydomeInformation.hpp"

nejlika::world::SkydomeInformation::SkydomeInformation(nejlika::Reader &io, uint32_t version)
{
    m_Filename = io.ReadString<uint32_t>();

    if (version >= 34) {
        m_SkyLayerFilename = io.ReadString<uint32_t>();
        m_RingLayer0Filename = io.ReadString<uint32_t>();
        m_RingLayer1Filename = io.ReadString<uint32_t>();
        m_RingLayer2Filename = io.ReadString<uint32_t>();
        m_RingLayer3Filename = io.ReadString<uint32_t>();
    }
}

void nejlika::world::SkydomeInformation::Save(nejlika::Writer &io, uint32_t version) const
{
    io.WriteString<uint32_t>(m_Filename);

    if (version >= 34) {
        io.WriteString<uint32_t>(m_SkyLayerFilename);
        io.WriteString<uint32_t>(m_RingLayer0Filename);
        io.WriteString<uint32_t>(m_RingLayer1Filename);
        io.WriteString<uint32_t>(m_RingLayer2Filename);
        io.WriteString<uint32_t>(m_RingLayer3Filename);
    }
}

const std::string &nejlika::world::SkydomeInformation::GetFilename() const
{
    return m_Filename;
}

const std::string &nejlika::world::SkydomeInformation::GetSkyLayerFilename() const
{
    return m_SkyLayerFilename;
}

const std::string &nejlika::world::SkydomeInformation::GetRingLayer0Filename() const
{
    return m_RingLayer0Filename;
}

const std::string &nejlika::world::SkydomeInformation::GetRingLayer1Filename() const
{
    return m_RingLayer1Filename;
}

const std::string &nejlika::world::SkydomeInformation::GetRingLayer2Filename() const
{
    return m_RingLayer2Filename;
}

const std::string &nejlika::world::SkydomeInformation::GetRingLayer3Filename() const
{
    return m_RingLayer3Filename;
}

void nejlika::world::SkydomeInformation::SetFilename(const std::string &filename)
{
    m_Filename = filename;
}

void nejlika::world::SkydomeInformation::SetSkyLayerFilename(const std::string &filename)
{
    m_SkyLayerFilename = filename;
}

void nejlika::world::SkydomeInformation::SetRingLayer0Filename(const std::string &filename)
{
    m_RingLayer0Filename = filename;
}

void nejlika::world::SkydomeInformation::SetRingLayer1Filename(const std::string &filename)
{
    m_RingLayer1Filename = filename;
}

void nejlika::world::SkydomeInformation::SetRingLayer2Filename(const std::string &filename)
{
    m_RingLayer2Filename = filename;
}

void nejlika::world::SkydomeInformation::SetRingLayer3Filename(const std::string &filename)
{
    m_RingLayer3Filename = filename;
}

nejlika::world::SkydomeInformation::~SkydomeInformation()
{
}
