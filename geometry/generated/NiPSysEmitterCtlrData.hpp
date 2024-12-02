#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "KeyGroup.hpp"
#include "Key.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Particle system emitter controller data.
 *         
 */
class NiPSysEmitterCtlrData : public NiObject
{
protected:
    /**
     * Unknown.
     */
    KeyGroup<float> m_FloatKeys;
    /**
     * Number of keys.
     */
    uint m_NumVisibilityKeys;
    /**
     * Unknown.
     */
    std::vector<Key<byte>> m_VisibilityKeys;

public:
    const KeyGroup<float>& GetFloatKeys() const { return m_FloatKeys; }
    KeyGroup<float>& GetFloatKeys() { return m_FloatKeys; }
    void SetFloatKeys(const KeyGroup<float>& value) { m_FloatKeys = value; }

    const uint& GetNumVisibilityKeys() const { return m_NumVisibilityKeys; }
    uint& GetNumVisibilityKeys() { return m_NumVisibilityKeys; }
    void SetNumVisibilityKeys(const uint& value) { m_NumVisibilityKeys = value; }

    const std::vector<Key<byte>>& GetVisibilityKeys() const { return m_VisibilityKeys; }
    std::vector<Key<byte>>& GetVisibilityKeys() { return m_VisibilityKeys; }
    void SetVisibilityKeys(const std::vector<Key<byte>>& value) { m_VisibilityKeys = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
