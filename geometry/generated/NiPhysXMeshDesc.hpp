#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector3.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown PhysX node.
 *         
 */
class NiPhysXMeshDesc : public NiObject
{
protected:
    /**
     * Unknown
     */
    short m_UnknownShort1;
    /**
     * Unknown
     */
    float m_UnknownFloat1;
    /**
     * Unknown
     */
    short m_UnknownShort2;
    /**
     * NXS
     */
    std::vector<byte> m_UnknownBytes0;
    /**
     * Unknown
     */
    byte m_UnknownByte1;
    /**
     * MESH
     */
    std::vector<byte> m_UnknownBytes1;
    /**
     * Unknown
     */
    std::vector<byte> m_UnknownBytes2;
    /**
     * Unknown
     */
    float m_UnknownFloat2;
    /**
     * Unknown
     */
    int m_UnknownInt1;
    /**
     * Unknown
     */
    int m_UnknownInt2;
    /**
     * Number of mesh vertices
     */
    int m_NumVertices;
    /**
     * Unknown
     */
    int m_UnknownInt4;
    /**
     * Vertices
     */
    std::vector<Vector3> m_Vertices;
    /**
     * Unknown
     */
    std::vector<byte> m_UnknownBytes3;
    /**
     * Unknown
     */
    std::vector<short> m_UnknownShorts1;
    /**
     * Unknown
     */
    std::vector<uint> m_UnknownInts1;
    /**
     * Unknown
     */
    byte m_UnknownByte2;

public:
    const short& GetUnknownShort1() const { return m_UnknownShort1; }
    short& GetUnknownShort1() { return m_UnknownShort1; }
    void SetUnknownShort1(const short& value) { m_UnknownShort1 = value; }

    const float& GetUnknownFloat1() const { return m_UnknownFloat1; }
    float& GetUnknownFloat1() { return m_UnknownFloat1; }
    void SetUnknownFloat1(const float& value) { m_UnknownFloat1 = value; }

    const short& GetUnknownShort2() const { return m_UnknownShort2; }
    short& GetUnknownShort2() { return m_UnknownShort2; }
    void SetUnknownShort2(const short& value) { m_UnknownShort2 = value; }

    const std::vector<byte>& GetUnknownBytes0() const { return m_UnknownBytes0; }
    std::vector<byte>& GetUnknownBytes0() { return m_UnknownBytes0; }
    void SetUnknownBytes0(const std::vector<byte>& value) { m_UnknownBytes0 = value; }

    const byte& GetUnknownByte1() const { return m_UnknownByte1; }
    byte& GetUnknownByte1() { return m_UnknownByte1; }
    void SetUnknownByte1(const byte& value) { m_UnknownByte1 = value; }

    const std::vector<byte>& GetUnknownBytes1() const { return m_UnknownBytes1; }
    std::vector<byte>& GetUnknownBytes1() { return m_UnknownBytes1; }
    void SetUnknownBytes1(const std::vector<byte>& value) { m_UnknownBytes1 = value; }

    const std::vector<byte>& GetUnknownBytes2() const { return m_UnknownBytes2; }
    std::vector<byte>& GetUnknownBytes2() { return m_UnknownBytes2; }
    void SetUnknownBytes2(const std::vector<byte>& value) { m_UnknownBytes2 = value; }

    const float& GetUnknownFloat2() const { return m_UnknownFloat2; }
    float& GetUnknownFloat2() { return m_UnknownFloat2; }
    void SetUnknownFloat2(const float& value) { m_UnknownFloat2 = value; }

    const int& GetUnknownInt1() const { return m_UnknownInt1; }
    int& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const int& value) { m_UnknownInt1 = value; }

    const int& GetUnknownInt2() const { return m_UnknownInt2; }
    int& GetUnknownInt2() { return m_UnknownInt2; }
    void SetUnknownInt2(const int& value) { m_UnknownInt2 = value; }

    const int& GetNumVertices() const { return m_NumVertices; }
    int& GetNumVertices() { return m_NumVertices; }
    void SetNumVertices(const int& value) { m_NumVertices = value; }

    const int& GetUnknownInt4() const { return m_UnknownInt4; }
    int& GetUnknownInt4() { return m_UnknownInt4; }
    void SetUnknownInt4(const int& value) { m_UnknownInt4 = value; }

    const std::vector<Vector3>& GetVertices() const { return m_Vertices; }
    std::vector<Vector3>& GetVertices() { return m_Vertices; }
    void SetVertices(const std::vector<Vector3>& value) { m_Vertices = value; }

    const std::vector<byte>& GetUnknownBytes3() const { return m_UnknownBytes3; }
    std::vector<byte>& GetUnknownBytes3() { return m_UnknownBytes3; }
    void SetUnknownBytes3(const std::vector<byte>& value) { m_UnknownBytes3 = value; }

    const std::vector<short>& GetUnknownShorts1() const { return m_UnknownShorts1; }
    std::vector<short>& GetUnknownShorts1() { return m_UnknownShorts1; }
    void SetUnknownShorts1(const std::vector<short>& value) { m_UnknownShorts1 = value; }

    const std::vector<uint>& GetUnknownInts1() const { return m_UnknownInts1; }
    std::vector<uint>& GetUnknownInts1() { return m_UnknownInts1; }
    void SetUnknownInts1(const std::vector<uint>& value) { m_UnknownInts1 = value; }

    const byte& GetUnknownByte2() const { return m_UnknownByte2; }
    byte& GetUnknownByte2() { return m_UnknownByte2; }
    void SetUnknownByte2(const byte& value) { m_UnknownByte2 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
