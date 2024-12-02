#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "BSMultiBoundData.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-specific node.
 *         
 */
class BSMultiBound : public NiObject
{
protected:
    /**
     * Unknown.
     */
    Pointer<class BSMultiBoundData*> m_Data;

public:
    const Pointer<class BSMultiBoundData*>& GetData() const { return m_Data; }
    Pointer<class BSMultiBoundData*>& GetData() { return m_Data; }
    void SetData(const Pointer<class BSMultiBoundData*>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
