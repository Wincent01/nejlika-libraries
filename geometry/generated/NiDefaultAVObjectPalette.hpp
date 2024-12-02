#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "AVObject.hpp"
#include "NiAVObjectPalette.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown. Refers to a list of objects. Used by NiControllerManager.
 *         
 */
class NiDefaultAVObjectPalette : public NiAVObjectPalette
{
protected:
    /**
     * Unknown.
     */
    uint m_UnknownInt;
    /**
     * Number of objects.
     */
    uint m_NumObjs;
    /**
     * The objects.
     */
    std::vector<AVObject> m_Objs;

public:
    const uint& GetUnknownInt() const { return m_UnknownInt; }
    uint& GetUnknownInt() { return m_UnknownInt; }
    void SetUnknownInt(const uint& value) { m_UnknownInt = value; }

    const uint& GetNumObjs() const { return m_NumObjs; }
    uint& GetNumObjs() { return m_NumObjs; }
    void SetNumObjs(const uint& value) { m_NumObjs = value; }

    const std::vector<AVObject>& GetObjs() const { return m_Objs; }
    std::vector<AVObject>& GetObjs() { return m_Objs; }
    void SetObjs(const std::vector<AVObject>& value) { m_Objs = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
