#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "EndianType.hpp"
#include "ExportInfo.hpp"
#include "ExportInfo.hpp"
#include "SizedString.hpp"
#include "SizedString.hpp"
namespace nejlika::geometry {


/**
 * 
 *         The NIF file header.
 *         
 */
class Header : public Construct
{
protected:
    /**
     * 'NetImmerse File Format x.x.x.x' (versions <= 10.0.1.2) or 'Gamebryo File Format x.x.x.x' (versions >= 10.1.0.0), with x.x.x.x the version written out. Ends with a newline character (0x0A).
     */
    HeaderString m_HeaderString;
    std::vector<LineString> m_Copyright;
    /**
     * The NIF version, in hexadecimal notation: 0x04000002, 0x0401000C, 0x04020002, 0x04020100, 0x04020200, 0x0A000100, 0x0A010000, 0x0A020000, 0x14000004, ...
     */
    FileVersion m_Version;
    /**
     * Determines the endianness of the data in the file.
     */
    EndianType m_EndianType;
    /**
     * An extra version number, for companies that decide to modify the file format.
     */
    ulittle32 m_UserVersion;
    /**
     * Number of file objects.
     */
    ulittle32 m_NumBlocks;
    /**
     * This also appears to be the extra user version number and must be set in some circumstances. Probably used by Bethesda to denote the Havok version.
     */
    ulittle32 m_UserVersion2;
    /**
     * Unknown. Possibly User Version 2?
     */
    uint m_UnknownInt3;
    ExportInfo m_ExportInfo;
    /**
     * Number of object types in this NIF file.
     */
    ushort m_NumBlockTypes;
    /**
     * List of all object types used in this NIF file.
     */
    std::vector<SizedString> m_BlockTypes;
    /**
     * Maps file objects on their corresponding type: first file object is of type object_types[object_type_index[0]], the second of object_types[object_type_index[1]], etc.
     */
    std::vector<BlockTypeIndex> m_BlockTypeIndex;
    /**
     * Array of block sizes?
     */
    std::vector<uint> m_BlockSize;
    /**
     * Number of strings.
     */
    uint m_NumStrings;
    /**
     * Maximum string length.
     */
    uint m_MaxStringLength;
    /**
     * Strings.
     */
    std::vector<SizedString> m_Strings;
    /**
     * Unknown.
     */
    uint m_UnknownInt2;

public:
    const HeaderString& GetHeaderString() const { return m_HeaderString; }
    HeaderString& GetHeaderString() { return m_HeaderString; }
    void SetHeaderString(const HeaderString& value) { m_HeaderString = value; }

    const std::vector<LineString>& GetCopyright() const { return m_Copyright; }
    std::vector<LineString>& GetCopyright() { return m_Copyright; }
    void SetCopyright(const std::vector<LineString>& value) { m_Copyright = value; }

    const FileVersion& GetVersion() const { return m_Version; }
    FileVersion& GetVersion() { return m_Version; }
    void SetVersion(const FileVersion& value) { m_Version = value; }

    const EndianType& GetEndianType() const { return m_EndianType; }
    EndianType& GetEndianType() { return m_EndianType; }
    void SetEndianType(const EndianType& value) { m_EndianType = value; }

    const ulittle32& GetUserVersion() const { return m_UserVersion; }
    ulittle32& GetUserVersion() { return m_UserVersion; }
    void SetUserVersion(const ulittle32& value) { m_UserVersion = value; }

    const ulittle32& GetNumBlocks() const { return m_NumBlocks; }
    ulittle32& GetNumBlocks() { return m_NumBlocks; }
    void SetNumBlocks(const ulittle32& value) { m_NumBlocks = value; }

    const ulittle32& GetUserVersion2() const { return m_UserVersion2; }
    ulittle32& GetUserVersion2() { return m_UserVersion2; }
    void SetUserVersion2(const ulittle32& value) { m_UserVersion2 = value; }

    const uint& GetUnknownInt3() const { return m_UnknownInt3; }
    uint& GetUnknownInt3() { return m_UnknownInt3; }
    void SetUnknownInt3(const uint& value) { m_UnknownInt3 = value; }

    const ExportInfo& GetExportInfo() const { return m_ExportInfo; }
    ExportInfo& GetExportInfo() { return m_ExportInfo; }
    void SetExportInfo(const ExportInfo& value) { m_ExportInfo = value; }

    const ushort& GetNumBlockTypes() const { return m_NumBlockTypes; }
    ushort& GetNumBlockTypes() { return m_NumBlockTypes; }
    void SetNumBlockTypes(const ushort& value) { m_NumBlockTypes = value; }

    const std::vector<SizedString>& GetBlockTypes() const { return m_BlockTypes; }
    std::vector<SizedString>& GetBlockTypes() { return m_BlockTypes; }
    void SetBlockTypes(const std::vector<SizedString>& value) { m_BlockTypes = value; }

    const std::vector<BlockTypeIndex>& GetBlockTypeIndex() const { return m_BlockTypeIndex; }
    std::vector<BlockTypeIndex>& GetBlockTypeIndex() { return m_BlockTypeIndex; }
    void SetBlockTypeIndex(const std::vector<BlockTypeIndex>& value) { m_BlockTypeIndex = value; }

    const std::vector<uint>& GetBlockSize() const { return m_BlockSize; }
    std::vector<uint>& GetBlockSize() { return m_BlockSize; }
    void SetBlockSize(const std::vector<uint>& value) { m_BlockSize = value; }

    const uint& GetNumStrings() const { return m_NumStrings; }
    uint& GetNumStrings() { return m_NumStrings; }
    void SetNumStrings(const uint& value) { m_NumStrings = value; }

    const uint& GetMaxStringLength() const { return m_MaxStringLength; }
    uint& GetMaxStringLength() { return m_MaxStringLength; }
    void SetMaxStringLength(const uint& value) { m_MaxStringLength = value; }

    const std::vector<SizedString>& GetStrings() const { return m_Strings; }
    std::vector<SizedString>& GetStrings() { return m_Strings; }
    void SetStrings(const std::vector<SizedString>& value) { m_Strings = value; }

    const uint& GetUnknownInt2() const { return m_UnknownInt2; }
    uint& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const uint& value) { m_UnknownInt2 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
