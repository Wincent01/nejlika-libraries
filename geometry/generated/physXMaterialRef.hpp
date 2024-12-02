#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiPhysXMaterialDesc.hpp"
namespace nejlika::geometry {


class physXMaterialRef : public Construct
{
protected:
    /**
     * Unknown
     */
    byte m_Number;
    /**
     * Unknown
     */
    byte m_UnknownByte1;
    /**
     * PhysX Material Description
     */
    Pointer<class NiPhysXMaterialDesc*> m_MaterialDesc;

public:
    const byte& GetNumber() const { return m_Number; }
    byte& GetNumber() { return m_Number; }
    void SetNumber(const byte& value) { m_Number = value; }

    const byte& GetUnknownByte1() const { return m_UnknownByte1; }
    byte& GetUnknownByte1() { return m_UnknownByte1; }
    void SetUnknownByte1(const byte& value) { m_UnknownByte1 = value; }

    const Pointer<class NiPhysXMaterialDesc*>& GetMaterialDesc() const { return m_MaterialDesc; }
    Pointer<class NiPhysXMaterialDesc*>& GetMaterialDesc() { return m_MaterialDesc; }
    void SetMaterialDesc(const Pointer<class NiPhysXMaterialDesc*>& value) { m_MaterialDesc = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
