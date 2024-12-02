#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiAVObject.hpp"
#include "NiNode.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-Specific node.
 *         
 */
class BSMasterParticleSystem : public NiNode
{
protected:
    /**
     * Unknown
     */
    ushort m_MaxEmitterObjects;
    /**
     * Unknown
     */
    int m_NumParticleSystems;
    /**
     * Unknown
     */
    std::vector<Pointer<class NiAVObject*>> m_ParticleSystems;

public:
    const ushort& GetMaxEmitterObjects() const { return m_MaxEmitterObjects; }
    ushort& GetMaxEmitterObjects() { return m_MaxEmitterObjects; }
    void SetMaxEmitterObjects(const ushort& value) { m_MaxEmitterObjects = value; }

    const int& GetNumParticleSystems() const { return m_NumParticleSystems; }
    int& GetNumParticleSystems() { return m_NumParticleSystems; }
    void SetNumParticleSystems(const int& value) { m_NumParticleSystems = value; }

    const std::vector<Pointer<class NiAVObject*>>& GetParticleSystems() const { return m_ParticleSystems; }
    std::vector<Pointer<class NiAVObject*>>& GetParticleSystems() { return m_ParticleSystems; }
    void SetParticleSystems(const std::vector<Pointer<class NiAVObject*>>& value) { m_ParticleSystems = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
