#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiTriStripsData.hpp"
#include "bhkShape.hpp"
namespace nejlika::geometry {


class bhkMeshShape : public bhkShape
{
protected:
    std::vector<float> m_Unknown1;
    int m_NumUnknownFloats;
    std::vector<std::vector<float>> m_UnknownFloats;
    std::vector<int> m_Unknown2;
    /**
     * The number of strips data objects referenced.
     */
    uint m_NumStripsData;
    /**
     * Refers to a bunch of NiTriStripsData objects that make up this shape.
     */
    std::vector<Pointer<class NiTriStripsData*>> m_StripsData;

public:
    const std::vector<float>& GetUnknown1() const { return m_Unknown1; }
    std::vector<float>& GetUnknown1() { return m_Unknown1; }
    void SetUnknown1(const std::vector<float>& value) { m_Unknown1 = value; }

    const int& GetNumUnknownFloats() const { return m_NumUnknownFloats; }
    int& GetNumUnknownFloats() { return m_NumUnknownFloats; }
    void SetNumUnknownFloats(const int& value) { m_NumUnknownFloats = value; }

    const std::vector<std::vector<float>>& GetUnknownFloats() const { return m_UnknownFloats; }
    std::vector<std::vector<float>>& GetUnknownFloats() { return m_UnknownFloats; }
    void SetUnknownFloats(const std::vector<std::vector<float>>& value) { m_UnknownFloats = value; }

    const std::vector<int>& GetUnknown2() const { return m_Unknown2; }
    std::vector<int>& GetUnknown2() { return m_Unknown2; }
    void SetUnknown2(const std::vector<int>& value) { m_Unknown2 = value; }

    const uint& GetNumStripsData() const { return m_NumStripsData; }
    uint& GetNumStripsData() { return m_NumStripsData; }
    void SetNumStripsData(const uint& value) { m_NumStripsData = value; }

    const std::vector<Pointer<class NiTriStripsData*>>& GetStripsData() const { return m_StripsData; }
    std::vector<Pointer<class NiTriStripsData*>>& GetStripsData() { return m_StripsData; }
    void SetStripsData(const std::vector<Pointer<class NiTriStripsData*>>& value) { m_StripsData = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
