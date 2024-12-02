#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiTriBasedGeom.hpp"
namespace nejlika::geometry {


/**
 * 
 *     A variation on NiTriShape, for visibility control over vertex groups.
 * 		
 */
class BSLODTriShape : public NiTriBasedGeom
{
protected:
    /**
     * Unknown
     */
    uint m_Level0Size;
    /**
     * Unknown
     */
    uint m_Level1Size;
    /**
     * Unknown
     */
    uint m_Level2Size;

public:
    const uint& GetLevel0Size() const { return m_Level0Size; }
    uint& GetLevel0Size() { return m_Level0Size; }
    void SetLevel0Size(const uint& value) { m_Level0Size = value; }

    const uint& GetLevel1Size() const { return m_Level1Size; }
    uint& GetLevel1Size() { return m_Level1Size; }
    void SetLevel1Size(const uint& value) { m_Level1Size = value; }

    const uint& GetLevel2Size() const { return m_Level2Size; }
    uint& GetLevel2Size() { return m_Level2Size; }
    void SetLevel2Size(const uint& value) { m_Level2Size = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
