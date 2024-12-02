#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "KeyType.hpp"
#include "Key.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Array of vector keys (anything that can be interpolated, except rotations).
 *         
 */
template <typename TEMPLATE>
class KeyGroup : public Construct
{
protected:
    /**
     * Number of keys in the array.
     */
    uint m_NumKeys;
    /**
     * The key type.
     */
    KeyType m_Interpolation;
    /**
     * The keys.
     */
    std::vector<Key<TEMPLATE>> m_Keys;

public:
    const uint& GetNumKeys() const { return m_NumKeys; }
    uint& GetNumKeys() { return m_NumKeys; }
    void SetNumKeys(const uint& value) { m_NumKeys = value; }

    const KeyType& GetInterpolation() const { return m_Interpolation; }
    KeyType& GetInterpolation() { return m_Interpolation; }
    void SetInterpolation(const KeyType& value) { m_Interpolation = value; }

    const std::vector<Key<TEMPLATE>>& GetKeys() const { return m_Keys; }
    std::vector<Key<TEMPLATE>>& GetKeys() { return m_Keys; }
    void SetKeys(const std::vector<Key<TEMPLATE>>& value) { m_Keys = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

template <typename TEMPLATE>
void KeyGroup<TEMPLATE>::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_NumKeys = reader.Read<uint>();

    if (m_NumKeys!= 0)
    {
        m_Interpolation = reader.Read<KeyType>();
    }

    m_Keys.resize(m_NumKeys);
    for (uint32_t i = 0; i < m_Keys.size(); i++)
    {
        m_Keys[i].Read(reader, version, user, m_Interpolation);
    }

}

template <typename TEMPLATE>
void KeyGroup<TEMPLATE>::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_NumKeys);

    if (m_NumKeys!= 0)
    {
        writer.Write(m_Interpolation);
    }

    for (uint32_t i = 0; i < m_Keys.size(); i++)
    {
        m_Keys[i].Write(writer, version, user, m_Interpolation);
    }

}
}
