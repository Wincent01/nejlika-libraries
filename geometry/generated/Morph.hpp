#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "string.hpp"
#include "KeyType.hpp"
#include "Key.hpp"
#include "Vector3.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Geometry morphing data component.
 *         
 */
class Morph : public Construct
{
protected:
    /**
     * Name of the frame.
     */
    string m_FrameName;
    /**
     * The number of morph keys that follow.
     */
    uint m_NumKeys;
    /**
     * Unlike most objects, the presense of this value is not conditional on there being keys.
     */
    KeyType m_Interpolation;
    /**
     * The morph key frames.
     */
    std::vector<Key<float>> m_Keys;
    /**
     * Unknown.
     */
    uint m_UnknownInt;
    /**
     * Morph vectors.
     */
    std::vector<Vector3> m_Vectors;

public:
    const string& GetFrameName() const { return m_FrameName; }
    string& GetFrameName() { return m_FrameName; }
    void SetFrameName(const string& value) { m_FrameName = value; }

    const uint& GetNumKeys() const { return m_NumKeys; }
    uint& GetNumKeys() { return m_NumKeys; }
    void SetNumKeys(const uint& value) { m_NumKeys = value; }

    const KeyType& GetInterpolation() const { return m_Interpolation; }
    KeyType& GetInterpolation() { return m_Interpolation; }
    void SetInterpolation(const KeyType& value) { m_Interpolation = value; }

    const std::vector<Key<float>>& GetKeys() const { return m_Keys; }
    std::vector<Key<float>>& GetKeys() { return m_Keys; }
    void SetKeys(const std::vector<Key<float>>& value) { m_Keys = value; }

    const uint& GetUnknownInt() const { return m_UnknownInt; }
    uint& GetUnknownInt() { return m_UnknownInt; }
    void SetUnknownInt(const uint& value) { m_UnknownInt = value; }

    const std::vector<Vector3>& GetVectors() const { return m_Vectors; }
    std::vector<Vector3>& GetVectors() { return m_Vectors; }
    void SetVectors(const std::vector<Vector3>& value) { m_Vectors = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
