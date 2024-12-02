#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiBezierTriangle4.hpp"
#include "Vector3.hpp"
#include "NiAVObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown
 *         
 */
class NiBezierMesh : public NiAVObject
{
protected:
    /**
     * references.
     */
    uint m_NumBezierTriangles;
    /**
     * unknown
     */
    std::vector<Pointer<class NiBezierTriangle4*>> m_BezierTriangle;
    /**
     * Unknown.
     */
    uint m_Unknown3;
    /**
     * Data count.
     */
    ushort m_Count1;
    /**
     * Unknown.
     */
    ushort m_Unknown4;
    /**
     * data.
     */
    std::vector<Vector3> m_Points1;
    /**
     * Unknown (illegal link?).
     */
    uint m_Unknown5;
    /**
     * data.
     */
    std::vector<std::vector<float>> m_Points2;
    /**
     * unknown
     */
    uint m_Unknown6;
    /**
     * data count 2.
     */
    ushort m_Count2;
    /**
     * data count.
     */
    std::vector<std::vector<ushort>> m_Data2;

public:
    const uint& GetNumBezierTriangles() const { return m_NumBezierTriangles; }
    uint& GetNumBezierTriangles() { return m_NumBezierTriangles; }
    void SetNumBezierTriangles(const uint& value) { m_NumBezierTriangles = value; }

    const std::vector<Pointer<class NiBezierTriangle4*>>& GetBezierTriangle() const { return m_BezierTriangle; }
    std::vector<Pointer<class NiBezierTriangle4*>>& GetBezierTriangle() { return m_BezierTriangle; }
    void SetBezierTriangle(const std::vector<Pointer<class NiBezierTriangle4*>>& value) { m_BezierTriangle = value; }

    const uint& GetUnknown3() const { return m_Unknown3; }
    uint& GetUnknown3() { return m_Unknown3; }
    void SetUnknown3(const uint& value) { m_Unknown3 = value; }

    const ushort& GetCount1() const { return m_Count1; }
    ushort& GetCount1() { return m_Count1; }
    void SetCount1(const ushort& value) { m_Count1 = value; }

    const ushort& GetUnknown4() const { return m_Unknown4; }
    ushort& GetUnknown4() { return m_Unknown4; }
    void SetUnknown4(const ushort& value) { m_Unknown4 = value; }

    const std::vector<Vector3>& GetPoints1() const { return m_Points1; }
    std::vector<Vector3>& GetPoints1() { return m_Points1; }
    void SetPoints1(const std::vector<Vector3>& value) { m_Points1 = value; }

    const uint& GetUnknown5() const { return m_Unknown5; }
    uint& GetUnknown5() { return m_Unknown5; }
    void SetUnknown5(const uint& value) { m_Unknown5 = value; }

    const std::vector<std::vector<float>>& GetPoints2() const { return m_Points2; }
    std::vector<std::vector<float>>& GetPoints2() { return m_Points2; }
    void SetPoints2(const std::vector<std::vector<float>>& value) { m_Points2 = value; }

    const uint& GetUnknown6() const { return m_Unknown6; }
    uint& GetUnknown6() { return m_Unknown6; }
    void SetUnknown6(const uint& value) { m_Unknown6 = value; }

    const ushort& GetCount2() const { return m_Count2; }
    ushort& GetCount2() { return m_Count2; }
    void SetCount2(const ushort& value) { m_Count2 = value; }

    const std::vector<std::vector<ushort>>& GetData2() const { return m_Data2; }
    std::vector<std::vector<ushort>>& GetData2() { return m_Data2; }
    void SetData2(const std::vector<std::vector<ushort>>& value) { m_Data2 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
