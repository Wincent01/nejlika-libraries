#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiTriBasedGeom.hpp"
#include "VelocityType.hpp"
#include "EmitFrom.hpp"
#include "Vector3.hpp"
#include "NiPSysEmitter.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle emitter that uses points on a specified mesh to emit from.
 *         
 */
class NiPSysMeshEmitter : public NiPSysEmitter
{
protected:
    /**
     * The number of references to emitter meshes that follow.
     */
    uint m_NumEmitterMeshes;
    /**
     * Links to meshes used for emitting.
     */
    std::vector<Pointer<class NiTriBasedGeom*>> m_EmitterMeshes;
    /**
     * The way the particles get their initial direction and speed.
     */
    VelocityType m_InitialVelocityType;
    /**
     * The parts of the mesh that the particles emit from.
     */
    EmitFrom m_EmissionType;
    /**
     * The emission axis.
     */
    Vector3 m_EmissionAxis;

public:
    const uint& GetNumEmitterMeshes() const { return m_NumEmitterMeshes; }
    uint& GetNumEmitterMeshes() { return m_NumEmitterMeshes; }
    void SetNumEmitterMeshes(const uint& value) { m_NumEmitterMeshes = value; }

    const std::vector<Pointer<class NiTriBasedGeom*>>& GetEmitterMeshes() const { return m_EmitterMeshes; }
    std::vector<Pointer<class NiTriBasedGeom*>>& GetEmitterMeshes() { return m_EmitterMeshes; }
    void SetEmitterMeshes(const std::vector<Pointer<class NiTriBasedGeom*>>& value) { m_EmitterMeshes = value; }

    const VelocityType& GetInitialVelocityType() const { return m_InitialVelocityType; }
    VelocityType& GetInitialVelocityType() { return m_InitialVelocityType; }
    void SetInitialVelocityType(const VelocityType& value) { m_InitialVelocityType = value; }

    const EmitFrom& GetEmissionType() const { return m_EmissionType; }
    EmitFrom& GetEmissionType() { return m_EmissionType; }
    void SetEmissionType(const EmitFrom& value) { m_EmissionType = value; }

    const Vector3& GetEmissionAxis() const { return m_EmissionAxis; }
    Vector3& GetEmissionAxis() { return m_EmissionAxis; }
    void SetEmissionAxis(const Vector3& value) { m_EmissionAxis = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
