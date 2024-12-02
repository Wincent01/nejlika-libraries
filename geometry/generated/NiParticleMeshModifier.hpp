#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiAVObject.hpp"
#include "NiParticleModifier.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown.
 *         
 */
class NiParticleMeshModifier : public NiParticleModifier
{
protected:
    /**
     * The number of particle mesh references that follow.
     */
    uint m_NumParticleMeshes;
    /**
     * Links to nodes of particle meshes?
     */
    std::vector<Pointer<class NiAVObject*>> m_ParticleMeshes;

public:
    const uint& GetNumParticleMeshes() const { return m_NumParticleMeshes; }
    uint& GetNumParticleMeshes() { return m_NumParticleMeshes; }
    void SetNumParticleMeshes(const uint& value) { m_NumParticleMeshes = value; }

    const std::vector<Pointer<class NiAVObject*>>& GetParticleMeshes() const { return m_ParticleMeshes; }
    std::vector<Pointer<class NiAVObject*>>& GetParticleMeshes() { return m_ParticleMeshes; }
    void SetParticleMeshes(const std::vector<Pointer<class NiAVObject*>>& value) { m_ParticleMeshes = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
