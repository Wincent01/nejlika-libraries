#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


/**
 * 
 *     Triangle indices used in pair with "Big Verts" in a bhkCompressedMeshShapeData.
 *         
 */
class bhkCMSDBigTris : public Construct
{
protected:
    ushort m_Triangle1;
    ushort m_Triangle2;
    ushort m_Triangle3;
    /**
     * Always 0?
     */
    uint m_UnknownInt1;
    ushort m_UnknownShort1;

public:
    const ushort& GetTriangle1() const { return m_Triangle1; }
    ushort& GetTriangle1() { return m_Triangle1; }
    void SetTriangle1(const ushort& value) { m_Triangle1 = value; }

    const ushort& GetTriangle2() const { return m_Triangle2; }
    ushort& GetTriangle2() { return m_Triangle2; }
    void SetTriangle2(const ushort& value) { m_Triangle2 = value; }

    const ushort& GetTriangle3() const { return m_Triangle3; }
    ushort& GetTriangle3() { return m_Triangle3; }
    void SetTriangle3(const ushort& value) { m_Triangle3 = value; }

    const uint& GetUnknownInt1() const { return m_UnknownInt1; }
    uint& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const uint& value) { m_UnknownInt1 = value; }

    const ushort& GetUnknownShort1() const { return m_UnknownShort1; }
    ushort& GetUnknownShort1() { return m_UnknownShort1; }
    void SetUnknownShort1(const ushort& value) { m_UnknownShort1 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
