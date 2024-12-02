#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiAVObject.hpp"
#include "NiRotatingParticlesData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle meshes data.
 *         
 */
class NiParticleMeshesData : public NiRotatingParticlesData
{
protected:
    /**
     * Refers to the mesh that makes up a particle?
     */
    Pointer<class NiAVObject*> m_UnknownLink2;

public:
    const Pointer<class NiAVObject*>& GetUnknownLink2() const { return m_UnknownLink2; }
    Pointer<class NiAVObject*>& GetUnknownLink2() { return m_UnknownLink2; }
    void SetUnknownLink2(const Pointer<class NiAVObject*>& value) { m_UnknownLink2 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
