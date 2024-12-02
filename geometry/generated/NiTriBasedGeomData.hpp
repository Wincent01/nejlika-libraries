#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiGeometryData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Describes a mesh, built from triangles.
 *         
 */
class NiTriBasedGeomData : public NiGeometryData
{
protected:
    /**
     * Number of triangles.
     */
    ushort m_NumTriangles;

public:
    const ushort& GetNumTriangles() const { return m_NumTriangles; }
    ushort& GetNumTriangles() { return m_NumTriangles; }
    void SetNumTriangles(const ushort& value) { m_NumTriangles = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
