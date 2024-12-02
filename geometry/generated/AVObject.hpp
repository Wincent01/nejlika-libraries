#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "SizedString.hpp"
#include "NiAVObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Used in NiDefaultAVObjectPalette.
 *         
 */
class AVObject : public Construct
{
protected:
    /**
     * Object name.
     */
    SizedString m_Name;
    /**
     * Object reference.
     */
    Pointer<class NiAVObject*> m_AVObject;

public:
    const SizedString& GetName() const { return m_Name; }
    SizedString& GetName() { return m_Name; }
    void SetName(const SizedString& value) { m_Name = value; }

    const Pointer<class NiAVObject*>& GetAVObject() const { return m_AVObject; }
    Pointer<class NiAVObject*>& GetAVObject() { return m_AVObject; }
    void SetAVObject(const Pointer<class NiAVObject*>& value) { m_AVObject = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
