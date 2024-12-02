#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector4.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Voxel data object.
 *         
 */
class NiBinaryVoxelData : public NiObject
{
protected:
    /**
     * Unknown.
     */
    ushort m_UnknownShort1;
    /**
     * Unknown.
     */
    ushort m_UnknownShort2;
    /**
     * Unknown. Is this^3 the Unknown Bytes 1 size?
     */
    ushort m_UnknownShort3;
    /**
     * Unknown.
     */
    std::vector<float> m_Unknown7Floats;
    /**
     * Unknown. Always a multiple of 7.
     */
    std::vector<std::vector<byte>> m_UnknownBytes1;
    /**
     * Unknown.
     */
    uint m_NumUnknownVectors;
    /**
     * Vectors on the unit sphere.
     */
    std::vector<Vector4> m_UnknownVectors;
    /**
     * Unknown.
     */
    uint m_NumUnknownBytes2;
    /**
     * Unknown.
     */
    std::vector<byte> m_UnknownBytes2;
    /**
     * Unknown.
     */
    std::vector<uint> m_Unknown5Ints;

public:
    const ushort& GetUnknownShort1() const { return m_UnknownShort1; }
    ushort& GetUnknownShort1() { return m_UnknownShort1; }
    void SetUnknownShort1(const ushort& value) { m_UnknownShort1 = value; }

    const ushort& GetUnknownShort2() const { return m_UnknownShort2; }
    ushort& GetUnknownShort2() { return m_UnknownShort2; }
    void SetUnknownShort2(const ushort& value) { m_UnknownShort2 = value; }

    const ushort& GetUnknownShort3() const { return m_UnknownShort3; }
    ushort& GetUnknownShort3() { return m_UnknownShort3; }
    void SetUnknownShort3(const ushort& value) { m_UnknownShort3 = value; }

    const std::vector<float>& GetUnknown7Floats() const { return m_Unknown7Floats; }
    std::vector<float>& GetUnknown7Floats() { return m_Unknown7Floats; }
    void SetUnknown7Floats(const std::vector<float>& value) { m_Unknown7Floats = value; }

    const std::vector<std::vector<byte>>& GetUnknownBytes1() const { return m_UnknownBytes1; }
    std::vector<std::vector<byte>>& GetUnknownBytes1() { return m_UnknownBytes1; }
    void SetUnknownBytes1(const std::vector<std::vector<byte>>& value) { m_UnknownBytes1 = value; }

    const uint& GetNumUnknownVectors() const { return m_NumUnknownVectors; }
    uint& GetNumUnknownVectors() { return m_NumUnknownVectors; }
    void SetNumUnknownVectors(const uint& value) { m_NumUnknownVectors = value; }

    const std::vector<Vector4>& GetUnknownVectors() const { return m_UnknownVectors; }
    std::vector<Vector4>& GetUnknownVectors() { return m_UnknownVectors; }
    void SetUnknownVectors(const std::vector<Vector4>& value) { m_UnknownVectors = value; }

    const uint& GetNumUnknownBytes2() const { return m_NumUnknownBytes2; }
    uint& GetNumUnknownBytes2() { return m_NumUnknownBytes2; }
    void SetNumUnknownBytes2(const uint& value) { m_NumUnknownBytes2 = value; }

    const std::vector<byte>& GetUnknownBytes2() const { return m_UnknownBytes2; }
    std::vector<byte>& GetUnknownBytes2() { return m_UnknownBytes2; }
    void SetUnknownBytes2(const std::vector<byte>& value) { m_UnknownBytes2 = value; }

    const std::vector<uint>& GetUnknown5Ints() const { return m_Unknown5Ints; }
    std::vector<uint>& GetUnknown5Ints() { return m_Unknown5Ints; }
    void SetUnknown5Ints(const std::vector<uint>& value) { m_Unknown5Ints = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
