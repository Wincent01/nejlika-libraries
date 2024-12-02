#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "ShortString.hpp"
#include "ShortString.hpp"
#include "ShortString.hpp"
namespace nejlika::geometry {


/**
 * 
 *     	Information about how the file was exported
 *         
 */
class ExportInfo : public Construct
{
protected:
    /**
     * Probably the number of strings that follow.
     */
    uint m_Unknown;
    /**
     * Could be the name of the creator of the NIF file?
     */
    ShortString m_Creator;
    /**
     * Unknown. Can be something like 'TriStrip Process Script'.
     */
    ShortString m_ExportInfo1;
    /**
     * Unknown. Possibly the selected option of the export script. Can be something like 'Default Export Script'.
     */
    ShortString m_ExportInfo2;

public:
    const uint& GetUnknown() const { return m_Unknown; }
    uint& GetUnknown() { return m_Unknown; }
    void SetUnknown(const uint& value) { m_Unknown = value; }

    const ShortString& GetCreator() const { return m_Creator; }
    ShortString& GetCreator() { return m_Creator; }
    void SetCreator(const ShortString& value) { m_Creator = value; }

    const ShortString& GetExportInfo1() const { return m_ExportInfo1; }
    ShortString& GetExportInfo1() { return m_ExportInfo1; }
    void SetExportInfo1(const ShortString& value) { m_ExportInfo1 = value; }

    const ShortString& GetExportInfo2() const { return m_ExportInfo2; }
    ShortString& GetExportInfo2() { return m_ExportInfo2; }
    void SetExportInfo2(const ShortString& value) { m_ExportInfo2 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
