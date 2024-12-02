#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiNode.hpp"
#include "NiPSysEmitter.hpp"
namespace nejlika::geometry {


/**
 * 
 *         An emitter that emits meshes?
 *         
 */
class NiPSysVolumeEmitter : public NiPSysEmitter
{
protected:
    /**
     * Node parent of this modifier?
     */
    Pointer<class NiNode*> m_EmitterObject;

public:
    const Pointer<class NiNode*>& GetEmitterObject() const { return m_EmitterObject; }
    Pointer<class NiNode*>& GetEmitterObject() { return m_EmitterObject; }
    void SetEmitterObject(const Pointer<class NiNode*>& value) { m_EmitterObject = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
