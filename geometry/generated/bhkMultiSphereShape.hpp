#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "SphereBV.hpp"
#include "bhkSphereRepShape.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown.
 *         
 */
class bhkMultiSphereShape : public bhkSphereRepShape
{
protected:
    /**
     * Unknown.
     */
    float m_UnknownFloat1;
    /**
     * Unknown.
     */
    float m_UnknownFloat2;
    /**
     * The number of spheres in this multi sphere shape.
     */
    uint m_NumSpheres;
    /**
     * This array holds the spheres which make up the multi sphere shape.
     */
    std::vector<SphereBV> m_Spheres;

public:
    const float& GetUnknownFloat1() const { return m_UnknownFloat1; }
    float& GetUnknownFloat1() { return m_UnknownFloat1; }
    void SetUnknownFloat1(const float& value) { m_UnknownFloat1 = value; }

    const float& GetUnknownFloat2() const { return m_UnknownFloat2; }
    float& GetUnknownFloat2() { return m_UnknownFloat2; }
    void SetUnknownFloat2(const float& value) { m_UnknownFloat2 = value; }

    const uint& GetNumSpheres() const { return m_NumSpheres; }
    uint& GetNumSpheres() { return m_NumSpheres; }
    void SetNumSpheres(const uint& value) { m_NumSpheres = value; }

    const std::vector<SphereBV>& GetSpheres() const { return m_Spheres; }
    std::vector<SphereBV>& GetSpheres() { return m_Spheres; }
    void SetSpheres(const std::vector<SphereBV>& value) { m_Spheres = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
