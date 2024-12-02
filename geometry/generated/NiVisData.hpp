#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Key.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Visibility data for a controller.
 *         
 */
class NiVisData : public NiObject
{
protected:
    /**
     * The number of visibility keys that follow.
     */
    uint m_NumKeys;
    /**
     * The visibility keys.
     */
    std::vector<Key<byte>> m_Keys;

public:
    const uint& GetNumKeys() const { return m_NumKeys; }
    uint& GetNumKeys() { return m_NumKeys; }
    void SetNumKeys(const uint& value) { m_NumKeys = value; }

    const std::vector<Key<byte>>& GetKeys() const { return m_Keys; }
    std::vector<Key<byte>>& GetKeys() { return m_Keys; }
    void SetKeys(const std::vector<Key<byte>>& value) { m_Keys = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
