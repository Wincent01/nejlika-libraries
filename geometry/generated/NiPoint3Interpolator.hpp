#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "NiPosData.hpp"
#include "NiKeyBasedInterpolator.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown.
 *         
 */
class NiPoint3Interpolator : public NiKeyBasedInterpolator
{
protected:
    /**
     * Value when posed?  Value at time 0?
     */
    Vector3 m_Point3Value;
    /**
     * Reference to NiPosData.
     */
    Pointer<class NiPosData*> m_Data;

public:
    const Vector3& GetPoint3Value() const { return m_Point3Value; }
    Vector3& GetPoint3Value() { return m_Point3Value; }
    void SetPoint3Value(const Vector3& value) { m_Point3Value = value; }

    const Pointer<class NiPosData*>& GetData() const { return m_Data; }
    Pointer<class NiPosData*>& GetData() { return m_Data; }
    void SetData(const Pointer<class NiPosData*>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
