#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "Vector3.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Array of Vectors for Decal placement in BSDecalPlacementVectorExtraData.
 *         
 */
class DecalVectorArray : public Construct
{
protected:
    /**
     * Number of sets
     */
    short m_NumVectors;
    /**
     * Vector XYZ coords
     */
    std::vector<Vector3> m_Points;
    /**
     * Vector Normals
     */
    std::vector<Vector3> m_Normals;

public:
    const short& GetNumVectors() const { return m_NumVectors; }
    short& GetNumVectors() { return m_NumVectors; }
    void SetNumVectors(const short& value) { m_NumVectors = value; }

    const std::vector<Vector3>& GetPoints() const { return m_Points; }
    std::vector<Vector3>& GetPoints() { return m_Points; }
    void SetPoints(const std::vector<Vector3>& value) { m_Points = value; }

    const std::vector<Vector3>& GetNormals() const { return m_Normals; }
    std::vector<Vector3>& GetNormals() { return m_Normals; }
    void SetNormals(const std::vector<Vector3>& value) { m_Normals = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
