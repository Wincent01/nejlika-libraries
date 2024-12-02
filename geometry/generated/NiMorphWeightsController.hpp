#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiObject.hpp"
#include "string.hpp"
#include "NiInterpController.hpp"
namespace nejlika::geometry {


class NiMorphWeightsController : public NiInterpController
{
protected:
    int m_Unknown2;
    uint m_NumInterpolators;
    std::vector<Pointer<class NiObject*>> m_Interpolators;
    /**
     * The number of morph targets.
     */
    uint m_NumTargets;
    /**
     * Name of each morph target.
     */
    std::vector<string> m_TargetNames;

public:
    const int& GetUnknown2() const { return m_Unknown2; }
    int& GetUnknown2() { return m_Unknown2; }
    void SetUnknown2(const int& value) { m_Unknown2 = value; }

    const uint& GetNumInterpolators() const { return m_NumInterpolators; }
    uint& GetNumInterpolators() { return m_NumInterpolators; }
    void SetNumInterpolators(const uint& value) { m_NumInterpolators = value; }

    const std::vector<Pointer<class NiObject*>>& GetInterpolators() const { return m_Interpolators; }
    std::vector<Pointer<class NiObject*>>& GetInterpolators() { return m_Interpolators; }
    void SetInterpolators(const std::vector<Pointer<class NiObject*>>& value) { m_Interpolators = value; }

    const uint& GetNumTargets() const { return m_NumTargets; }
    uint& GetNumTargets() { return m_NumTargets; }
    void SetNumTargets(const uint& value) { m_NumTargets = value; }

    const std::vector<string>& GetTargetNames() const { return m_TargetNames; }
    std::vector<string>& GetTargetNames() { return m_TargetNames; }
    void SetTargetNames(const std::vector<string>& value) { m_TargetNames = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
