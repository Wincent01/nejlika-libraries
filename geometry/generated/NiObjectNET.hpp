#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "BSLightingShaderPropertyShaderType.hpp"
#include "string.hpp"
#include "string.hpp"
#include "string.hpp"
#include "NiExtraData.hpp"
#include "NiExtraData.hpp"
#include "NiTimeController.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         An object that can be controlled by a controller.
 *         
 */
class NiObjectNET : public NiObject
{
protected:
    /**
     * Configures the main shader path
     */
    BSLightingShaderPropertyShaderType m_SkyrimShaderType;
    /**
     * Name of this controllable object, used to refer to the object in .kf files.
     */
    string m_Name;
    /**
     * Extra data for pre-3.0 versions.
     */
    bool m_HasOldExtraData;
    /**
     * (=NiStringExtraData)
     */
    string m_OldExtraPropName;
    /**
     * ref
     */
    uint m_OldExtraInternalId;
    /**
     * Extra string data.
     */
    string m_OldExtraString;
    /**
     * Always 0.
     */
    byte m_UnknownByte;
    /**
     * Extra data object index. (The first in a chain)
     */
    Pointer<class NiExtraData*> m_ExtraData;
    /**
     * The number of Extra Data objects referenced through the list.
     */
    uint m_NumExtraDataList;
    /**
     * List of extra data indices.
     */
    std::vector<Pointer<class NiExtraData*>> m_ExtraDataList;
    /**
     * Controller object index. (The first in a chain)
     */
    Pointer<class NiTimeController*> m_Controller;

public:
    const BSLightingShaderPropertyShaderType& GetSkyrimShaderType() const { return m_SkyrimShaderType; }
    BSLightingShaderPropertyShaderType& GetSkyrimShaderType() { return m_SkyrimShaderType; }
    void SetSkyrimShaderType(const BSLightingShaderPropertyShaderType& value) { m_SkyrimShaderType = value; }

    const string& GetName() const { return m_Name; }
    string& GetName() { return m_Name; }
    void SetName(const string& value) { m_Name = value; }

    const bool& GetHasOldExtraData() const { return m_HasOldExtraData; }
    bool& GetHasOldExtraData() { return m_HasOldExtraData; }
    void SetHasOldExtraData(const bool& value) { m_HasOldExtraData = value; }

    const string& GetOldExtraPropName() const { return m_OldExtraPropName; }
    string& GetOldExtraPropName() { return m_OldExtraPropName; }
    void SetOldExtraPropName(const string& value) { m_OldExtraPropName = value; }

    const uint& GetOldExtraInternalId() const { return m_OldExtraInternalId; }
    uint& GetOldExtraInternalId() { return m_OldExtraInternalId; }
    void SetOldExtraInternalId(const uint& value) { m_OldExtraInternalId = value; }

    const string& GetOldExtraString() const { return m_OldExtraString; }
    string& GetOldExtraString() { return m_OldExtraString; }
    void SetOldExtraString(const string& value) { m_OldExtraString = value; }

    const byte& GetUnknownByte() const { return m_UnknownByte; }
    byte& GetUnknownByte() { return m_UnknownByte; }
    void SetUnknownByte(const byte& value) { m_UnknownByte = value; }

    const Pointer<class NiExtraData*>& GetExtraData() const { return m_ExtraData; }
    Pointer<class NiExtraData*>& GetExtraData() { return m_ExtraData; }
    void SetExtraData(const Pointer<class NiExtraData*>& value) { m_ExtraData = value; }

    const uint& GetNumExtraDataList() const { return m_NumExtraDataList; }
    uint& GetNumExtraDataList() { return m_NumExtraDataList; }
    void SetNumExtraDataList(const uint& value) { m_NumExtraDataList = value; }

    const std::vector<Pointer<class NiExtraData*>>& GetExtraDataList() const { return m_ExtraDataList; }
    std::vector<Pointer<class NiExtraData*>>& GetExtraDataList() { return m_ExtraDataList; }
    void SetExtraDataList(const std::vector<Pointer<class NiExtraData*>>& value) { m_ExtraDataList = value; }

    const Pointer<class NiTimeController*>& GetController() const { return m_Controller; }
    Pointer<class NiTimeController*>& GetController() { return m_Controller; }
    void SetController(const Pointer<class NiTimeController*>& value) { m_Controller = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
