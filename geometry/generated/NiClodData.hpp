#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiTriBasedGeomData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Holds mesh data for continuous level of detail shapes.
 *         Pesumably a progressive mesh with triangles specified by edge splits.
 *         Seems to be specific to Freedom Force.
 *         The structure of this is uncertain and highly experimental at this point.
 *         No file with this data can currently be read properly.
 *         
 */
class NiClodData : public NiTriBasedGeomData
{
protected:
    ushort m_UnknownShorts;
    ushort m_UnknownCount1;
    ushort m_UnknownCount2;
    ushort m_UnknownCount3;
    float m_UnknownFloat;
    ushort m_UnknownShort;
    std::vector<std::vector<ushort>> m_UnknownClodShorts1;
    std::vector<ushort> m_UnknownClodShorts2;
    std::vector<std::vector<ushort>> m_UnknownClodShorts3;

public:
    const ushort& GetUnknownShorts() const { return m_UnknownShorts; }
    ushort& GetUnknownShorts() { return m_UnknownShorts; }
    void SetUnknownShorts(const ushort& value) { m_UnknownShorts = value; }

    const ushort& GetUnknownCount1() const { return m_UnknownCount1; }
    ushort& GetUnknownCount1() { return m_UnknownCount1; }
    void SetUnknownCount1(const ushort& value) { m_UnknownCount1 = value; }

    const ushort& GetUnknownCount2() const { return m_UnknownCount2; }
    ushort& GetUnknownCount2() { return m_UnknownCount2; }
    void SetUnknownCount2(const ushort& value) { m_UnknownCount2 = value; }

    const ushort& GetUnknownCount3() const { return m_UnknownCount3; }
    ushort& GetUnknownCount3() { return m_UnknownCount3; }
    void SetUnknownCount3(const ushort& value) { m_UnknownCount3 = value; }

    const float& GetUnknownFloat() const { return m_UnknownFloat; }
    float& GetUnknownFloat() { return m_UnknownFloat; }
    void SetUnknownFloat(const float& value) { m_UnknownFloat = value; }

    const ushort& GetUnknownShort() const { return m_UnknownShort; }
    ushort& GetUnknownShort() { return m_UnknownShort; }
    void SetUnknownShort(const ushort& value) { m_UnknownShort = value; }

    const std::vector<std::vector<ushort>>& GetUnknownClodShorts1() const { return m_UnknownClodShorts1; }
    std::vector<std::vector<ushort>>& GetUnknownClodShorts1() { return m_UnknownClodShorts1; }
    void SetUnknownClodShorts1(const std::vector<std::vector<ushort>>& value) { m_UnknownClodShorts1 = value; }

    const std::vector<ushort>& GetUnknownClodShorts2() const { return m_UnknownClodShorts2; }
    std::vector<ushort>& GetUnknownClodShorts2() { return m_UnknownClodShorts2; }
    void SetUnknownClodShorts2(const std::vector<ushort>& value) { m_UnknownClodShorts2 = value; }

    const std::vector<std::vector<ushort>>& GetUnknownClodShorts3() const { return m_UnknownClodShorts3; }
    std::vector<std::vector<ushort>>& GetUnknownClodShorts3() { return m_UnknownClodShorts3; }
    void SetUnknownClodShorts3(const std::vector<std::vector<ushort>>& value) { m_UnknownClodShorts3 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
