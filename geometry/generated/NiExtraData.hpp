#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "string.hpp"
#include "NiExtraData.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         A generic extra data object.
 *         
 */
class NiExtraData : public NiObject
{
protected:
    /**
     * Name of this object.
     */
    string m_Name;
    /**
     * Block number of the next extra data object.
     */
    Pointer<class NiExtraData*> m_NextExtraData;

public:
    const string& GetName() const { return m_Name; }
    string& GetName() { return m_Name; }
    void SetName(const string& value) { m_Name = value; }

    const Pointer<class NiExtraData*>& GetNextExtraData() const { return m_NextExtraData; }
    Pointer<class NiExtraData*>& GetNextExtraData() { return m_NextExtraData; }
    void SetNextExtraData(const Pointer<class NiExtraData*>& value) { m_NextExtraData = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
