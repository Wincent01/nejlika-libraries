#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "string.hpp"
#include "string.hpp"
#include "NiTextKeyExtraData.hpp"
#include "ControllerLink.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Root node used in some Empire Earth II .kf files (version 4.2.2.0).
 *         
 */
class NiSequence : public NiObject
{
protected:
    /**
     * Name of this object. This is also the name of the action associated with this file. For instance, if the original NIF file is called "demon.nif" and this animation file contains an attack sequence, then the file would be called "demon_attack1.kf" and this field would contain the string "attack1".
     */
    string m_Name;
    /**
     * Name of following referenced NiTextKeyExtraData class.
     */
    string m_TextKeysName;
    /**
     * Link to NiTextKeyExtraData.
     */
    Pointer<class NiTextKeyExtraData*> m_TextKeys;
    /**
     * Unknown
     */
    int m_UnknownInt4;
    /**
     * Unknown
     */
    int m_UnknownInt5;
    /**
     * Number of controlled objects.
     */
    uint m_NumControlledBlocks;
    /**
     * Unknown.
     */
    uint m_UnknownInt1;
    /**
     * Refers to controlled objects.
     */
    std::vector<ControllerLink> m_ControlledBlocks;

public:
    const string& GetName() const { return m_Name; }
    string& GetName() { return m_Name; }
    void SetName(const string& value) { m_Name = value; }

    const string& GetTextKeysName() const { return m_TextKeysName; }
    string& GetTextKeysName() { return m_TextKeysName; }
    void SetTextKeysName(const string& value) { m_TextKeysName = value; }

    const Pointer<class NiTextKeyExtraData*>& GetTextKeys() const { return m_TextKeys; }
    Pointer<class NiTextKeyExtraData*>& GetTextKeys() { return m_TextKeys; }
    void SetTextKeys(const Pointer<class NiTextKeyExtraData*>& value) { m_TextKeys = value; }

    const int& GetUnknownInt4() const { return m_UnknownInt4; }
    int& GetUnknownInt4() { return m_UnknownInt4; }
    void SetUnknownInt4(const int& value) { m_UnknownInt4 = value; }

    const int& GetUnknownInt5() const { return m_UnknownInt5; }
    int& GetUnknownInt5() { return m_UnknownInt5; }
    void SetUnknownInt5(const int& value) { m_UnknownInt5 = value; }

    const uint& GetNumControlledBlocks() const { return m_NumControlledBlocks; }
    uint& GetNumControlledBlocks() { return m_NumControlledBlocks; }
    void SetNumControlledBlocks(const uint& value) { m_NumControlledBlocks = value; }

    const uint& GetUnknownInt1() const { return m_UnknownInt1; }
    uint& GetUnknownInt1() { return m_UnknownInt1; }
    void SetUnknownInt1(const uint& value) { m_UnknownInt1 = value; }

    const std::vector<ControllerLink>& GetControlledBlocks() const { return m_ControlledBlocks; }
    std::vector<ControllerLink>& GetControlledBlocks() { return m_ControlledBlocks; }
    void SetControlledBlocks(const std::vector<ControllerLink>& value) { m_ControlledBlocks = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
