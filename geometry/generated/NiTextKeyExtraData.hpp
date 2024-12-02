#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Key.hpp"
#include "string.hpp"
#include "NiExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Extra data, used to name different animation sequences.
 *         
 */
class NiTextKeyExtraData : public NiExtraData
{
protected:
    /**
     * Unknown.  Always equals zero in all official files.
     */
    uint m_UnknownInt1;
    /**
     * The number of text keys that follow.
     */
    uint m_NumTextKeys;
    /**
     * List of textual notes and at which time they take effect. Used for designating the start and stop of animations and the triggering of sounds.
     */
    std::vector<Key<string>> m_TextKeys;

public:
    const uint& GetUnknownInt1() const { return m_UnknownInt1; }
    uint& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const uint& value) { m_UnknownInt1 = value; }

    const uint& GetNumTextKeys() const { return m_NumTextKeys; }
    uint& GetNumTextKeys() { return m_NumTextKeys; }
    void SetNumTextKeys(const uint& value) { m_NumTextKeys = value; }

    const std::vector<Key<string>>& GetTextKeys() const { return m_TextKeys; }
    std::vector<Key<string>>& GetTextKeys() { return m_TextKeys; }
    void SetTextKeys(const std::vector<Key<string>>& value) { m_TextKeys = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
