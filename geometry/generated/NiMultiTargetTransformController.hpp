#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiAVObject.hpp"
#include "NiInterpController.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown.
 *         
 */
class NiMultiTargetTransformController : public NiInterpController
{
protected:
    /**
     * The number of target pointers that follow.
     */
    ushort m_NumExtraTargets;
    /**
     * NiNode Targets to be controlled.
     */
    std::vector<Pointer<class NiAVObject*>> m_ExtraTargets;

public:
    const ushort& GetNumExtraTargets() const { return m_NumExtraTargets; }
    ushort& GetNumExtraTargets() { return m_NumExtraTargets; }
    void SetNumExtraTargets(const ushort& value) { m_NumExtraTargets = value; }

    const std::vector<Pointer<class NiAVObject*>>& GetExtraTargets() const { return m_ExtraTargets; }
    std::vector<Pointer<class NiAVObject*>>& GetExtraTargets() { return m_ExtraTargets; }
    void SetExtraTargets(const std::vector<Pointer<class NiAVObject*>>& value) { m_ExtraTargets = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
