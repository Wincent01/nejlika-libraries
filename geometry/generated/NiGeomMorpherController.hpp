#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiMorphData.hpp"
#include "NiInterpolator.hpp"
#include "MorphWeight.hpp"
#include "NiInterpController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Time controller for geometry morphing.
 *         
 */
class NiGeomMorpherController : public NiInterpController
{
protected:
    /**
     * Unknown.
     */
    Flags m_ExtraFlags;
    /**
     * Unknown.
     */
    byte m_Unknown2;
    /**
     * Geometry morphing data index.
     */
    Pointer<class NiMorphData*> m_Data;
    /**
     * Always Update
     */
    byte m_AlwaysUpdate;
    /**
     * The number of interpolator objects.
     */
    uint m_NumInterpolators;
    /**
     * List of interpolators.
     */
    std::vector<Pointer<class NiInterpolator*>> m_Interpolators;
    /**
     * Weighted Interpolators?
     */
    std::vector<MorphWeight> m_InterpolatorWeights;
    /**
     * A count.
     */
    uint m_NumUnknownInts;
    /**
     * Unknown.
     */
    std::vector<uint> m_UnknownInts;

public:
    const Flags& GetExtraFlags() const { return m_ExtraFlags; }
    Flags& GetExtraFlags() { return m_ExtraFlags; }
    void SetExtraFlags(const Flags& value) { m_ExtraFlags = value; }

    const byte& GetUnknown2() const { return m_Unknown2; }
    byte& GetUnknown2() { return m_Unknown2; }
    void SetUnknown2(const byte& value) { m_Unknown2 = value; }

    const Pointer<class NiMorphData*>& GetData() const { return m_Data; }
    Pointer<class NiMorphData*>& GetData() { return m_Data; }
    void SetData(const Pointer<class NiMorphData*>& value) { m_Data = value; }

    const byte& GetAlwaysUpdate() const { return m_AlwaysUpdate; }
    byte& GetAlwaysUpdate() { return m_AlwaysUpdate; }
    void SetAlwaysUpdate(const byte& value) { m_AlwaysUpdate = value; }

    const uint& GetNumInterpolators() const { return m_NumInterpolators; }
    uint& GetNumInterpolators() { return m_NumInterpolators; }
    void SetNumInterpolators(const uint& value) { m_NumInterpolators = value; }

    const std::vector<Pointer<class NiInterpolator*>>& GetInterpolators() const { return m_Interpolators; }
    std::vector<Pointer<class NiInterpolator*>>& GetInterpolators() { return m_Interpolators; }
    void SetInterpolators(const std::vector<Pointer<class NiInterpolator*>>& value) { m_Interpolators = value; }

    const std::vector<MorphWeight>& GetInterpolatorWeights() const { return m_InterpolatorWeights; }
    std::vector<MorphWeight>& GetInterpolatorWeights() { return m_InterpolatorWeights; }
    void SetInterpolatorWeights(const std::vector<MorphWeight>& value) { m_InterpolatorWeights = value; }

    const uint& GetNumUnknownInts() const { return m_NumUnknownInts; }
    uint& GetNumUnknownInts() { return m_NumUnknownInts; }
    void SetNumUnknownInts(const uint& value) { m_NumUnknownInts = value; }

    const std::vector<uint>& GetUnknownInts() const { return m_UnknownInts; }
    std::vector<uint>& GetUnknownInts() { return m_UnknownInts; }
    void SetUnknownInts(const std::vector<uint>& value) { m_UnknownInts = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
