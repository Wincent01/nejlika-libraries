#pragma once

#include <string>
#include <vector>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"
#include "WritePointer.hpp"

namespace nejlika::world
{

class SkydomeInformation
{
public:
    SkydomeInformation() = default;

    SkydomeInformation(nejlika::Reader& io, uint32_t version);

    void Save(nejlika::Writer& io, uint32_t version) const;

    const std::string& GetFilename() const;

    const std::string& GetSkyLayerFilename() const;

    const std::string& GetRingLayer0Filename() const;

    const std::string& GetRingLayer1Filename() const;

    const std::string& GetRingLayer2Filename() const;

    const std::string& GetRingLayer3Filename() const;

    void SetFilename(const std::string& filename);

    void SetSkyLayerFilename(const std::string& filename);

    void SetRingLayer0Filename(const std::string& filename);

    void SetRingLayer1Filename(const std::string& filename);

    void SetRingLayer2Filename(const std::string& filename);

    void SetRingLayer3Filename(const std::string& filename);

    ~SkydomeInformation();

private:
    std::string m_Filename;
    std::string m_SkyLayerFilename;
    std::string m_RingLayer0Filename;
    std::string m_RingLayer1Filename;
    std::string m_RingLayer2Filename;
    std::string m_RingLayer3Filename;
};


}