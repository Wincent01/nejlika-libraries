#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiGeometryData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Wireframe geometry data.
 *         
 */
class NiLinesData : public NiGeometryData
{
protected:
    /**
     * Is vertex connected to other (next?) vertex?
     */
    std::vector<bool> m_Lines;

public:
    const std::vector<bool>& GetLines() const { return m_Lines; }
    std::vector<bool>& GetLines() { return m_Lines; }
    void SetLines(const std::vector<bool>& value) { m_Lines = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
