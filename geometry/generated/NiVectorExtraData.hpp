#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "NiExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Extra vector data.
 *         
 */
class NiVectorExtraData : public NiExtraData
{
protected:
    /**
     * The vector data.
     */
    Vector3 m_VectorData;
    /**
     * Not sure whether this comes before or after the vector data.
     */
    float m_UnknownFloat;

public:
    const Vector3& GetVectorData() const { return m_VectorData; }
    Vector3& GetVectorData() { return m_VectorData; }
    void SetVectorData(const Vector3& value) { m_VectorData = value; }

    const float& GetUnknownFloat() const { return m_UnknownFloat; }
    float& GetUnknownFloat() { return m_UnknownFloat; }
    void SetUnknownFloat(const float& value) { m_UnknownFloat = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
