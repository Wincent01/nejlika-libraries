#pragma once

#include <string>
#include <vector>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"
#include "WritePointer.hpp"

#include "CullData.hpp"

namespace nejlika::world
{

class OldLevelInfo
{
public:
    OldLevelInfo() = default;

    OldLevelInfo(nejlika::Reader& io);

    void Save(nejlika::Writer& io) const;

    uint16_t GetVersion() const;

    uint32_t GetRevision() const;

    uint8_t GetUnknown0() const;

    float GetUnknown1() const;

    const std::vector<CullData>& GetCullData() const;

    const std::vector<float>& GetUnknownArray1() const;
    const std::vector<float>& GetUnknownArray2() const;
    const std::vector<float>& GetUnknownArray3() const;
    const std::vector<float>& GetUnknownArray4() const;
    const std::vector<float>& GetUnknownArray5() const;
    const std::vector<float>& GetUnknownArray6() const;

    const vector3& GetUnknownVector1() const;

    const std::vector<std::string>& GetSkybox() const;

    const uint32_t& GetUnknown3() const;

    const uint32_t& GetUnknown4() const;

    const std::vector<vector3>& GetUnknownVectorArray1() const;

    void SetVersion(uint16_t version);

    void SetRevision(uint32_t revision);

    ~OldLevelInfo();

private:
    uint16_t m_Version = 0;
    uint32_t m_Revision = 0;
    uint8_t m_Unknown0 = 0;
    float m_Unknown1 = 0;
    std::vector<CullData> m_CullData;
    std::vector<float> m_UnknownArray1;
    std::vector<float> m_UnknownArray2;
    std::vector<float> m_UnknownArray3;
    std::vector<float> m_UnknownArray4;
    std::vector<float> m_UnknownArray5;
    std::vector<float> m_UnknownArray6;
    vector3 m_UnknownVector1;
    std::vector<std::string> m_Skybox;
    uint32_t m_Unknown3 = 0;
    uint32_t m_Unknown4 = 0;
    std::vector<vector3> m_UnknownVectorArray1;
};


}