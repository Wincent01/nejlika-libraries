#pragma once

#include <string>
#include <vector>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"
#include "WritePointer.hpp"

#include "OldLevelInfo.hpp"
#include "LevelInfo.hpp"
#include "EnvironmentInformation.hpp"
#include "LevelObjects.hpp"
#include "ParticleInformation.hpp"

namespace nejlika::world
{

class Level
{
public:
    Level() = default;

    /**
     * @brief Reads the level data from the input stream.
     * 
     * @param io The input stream.
     *
     * @throw If the data was not in the format that was expected.
     * @note A lot of checks are done to ensure that the data is in the correct format.
     *       Some formats which might be okay for the game to load will still throw exceptions.
     */
    Level(nejlika::Reader& io);

    void Save(nejlika::Writer& io);

    OldLevelInfo& GetOldInfo();

    LevelInfo& GetInfo();

    EnvironmentInformation& GetEnvironmentInformation();

    LevelObjects& GetObjects();

    ParticleInformation& GetParticleInformation();

    bool IsOld() const;

    bool HasEnvironmentInformation() const;

    bool HasObjects() const;

    bool HasParticleInformation() const;

    version GetVersion() const;

    void SetVersion(version version);

    void SetEnvironmentInformation(EnvironmentInformation& environmentInformation);

    void SetObjects(LevelObjects& objects);

    void SetParticleInformation(ParticleInformation& particleInformation);

    void SetOldInfo(OldLevelInfo& oldInfo);

    void SetHasEnvironmentInformation(bool hasEnvironmentInformation);

    void SetHasObjects(bool hasObjects);

    void SetHasParticleInformation(bool hasParticleInformation);

    ~Level();

    /**
     * @brief Peeks at the next four bytes in the input stream to determine if the level data is (very) old.
     * 
     * @param io The input stream.
     * @return true If the level data is (very) old.
     */
    static bool IsOld(nejlika::Reader& io);

private:
    void WriteHeader(nejlika::Writer& io, uint32_t chunkType, uint32_t headerVersion, uint32_t dataVersion);

    void Align(nejlika::Writer& io);

    OldLevelInfo m_OldInfo;
    LevelInfo m_Info;
    EnvironmentInformation m_EnvironmentInformation;
    LevelObjects m_Objects;
    ParticleInformation m_ParticleInformation;
    bool m_HasEnvironmentInformation = false;
    bool m_HasObjects = false;
    bool m_HasParticleInformation = false;
};

}