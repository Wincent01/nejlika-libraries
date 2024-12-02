#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "string.hpp"
#include "NiTimeController.hpp"
#include "NiInterpolator.hpp"
#include "NiTimeController.hpp"
#include "NiObject.hpp"
#include "NiStringPalette.hpp"
#include "string.hpp"
#include "string.hpp"
#include "string.hpp"
#include "string.hpp"
#include "string.hpp"
#include "string.hpp"
#include "string.hpp"
#include "string.hpp"
#include "string.hpp"
#include "string.hpp"
namespace nejlika::geometry {


/**
 * 
 *         In a .kf file, this links to a controllable object, via its name (or for version 10.2.0.0 and up, a link and offset to a NiStringPalette that contains the name), and a sequence of interpolators that apply to this controllable object, via links.
 *         
 */
class ControllerLink : public Construct
{
protected:
    /**
     * Name of a controllable object in another NIF file.
     */
    string m_TargetName;
    /**
     * Link to a controller.
     */
    Pointer<class NiTimeController*> m_Controller;
    /**
     * Link to an interpolator.
     */
    Pointer<class NiInterpolator*> m_Interpolator;
    /**
     * Unknown.
     */
    Pointer<class NiObject*> m_UnknownLink2;
    /**
     * Unknown.
     */
    ushort m_UnknownShort0;
    /**
     * Idle animations tend to have low values for this, and NIF objects that have high values tend to correspond with the important parts of the animation.
     */
    byte m_Priority;
    /**
     * Refers to the NiStringPalette which contains the name of the controlled NIF object.
     */
    Pointer<class NiStringPalette*> m_StringPalette;
    /**
     * The name of the animated node.
     */
    string m_NodeName;
    /**
     * Offset in the string palette where the name of the controlled node (NiNode, NiTriShape, ...) starts.
     */
    StringOffset m_NodeNameOffset;
    /**
     * Name of the property (NiMaterialProperty, ...), if this controller controls a property.
     */
    string m_PropertyType;
    /**
     * Offset in the string palette where the property (NiMaterialProperty, ...) starts, if this controller controls a property. Otherwise, -1.
     */
    StringOffset m_PropertyTypeOffset;
    /**
     * Probably the object type name of the controller in the NIF file that is child of the controlled object.
     */
    string m_ControllerType;
    /**
     * Apparently the offset in the string palette of some type of controller related to Interpolator (for example, a 'NiTransformInterpolator' will have here a 'NiTransformController', etc.). Sometimes the type of controller that links to the interpolator. Probably it refers to the controller in the NIF file that is child of the controlled object, via its type name.
     */
    StringOffset m_ControllerTypeOffset;
    /**
     * Some variable string (such as 'SELF_ILLUM', '0-0-TT_TRANSLATE_U', 'tongue_out', etc.).
     */
    string m_Variable1;
    /**
     * Offset in the string palette where some variable string starts (such as 'SELF_ILLUM', '0-0-TT_TRANSLATE_U', 'tongue_out', etc.). Usually, -1.
     */
    StringOffset m_Variable1Offset;
    /**
     * Another variable string, apparently used for particle system controllers.
     */
    string m_Variable2;
    /**
     * Offset in the string palette where some variable string starts (so far only 'EmitterActive' and 'BirthRate' have been observed in official files, used for particle system controllers). Usually, -1.
     */
    StringOffset m_Variable2Offset;

public:
    const string& GetTargetName() const { return m_TargetName; }
    string& GetTargetName() { return m_TargetName; }
    void SetTargetName(const string& value) { m_TargetName = value; }

    const Pointer<class NiTimeController*>& GetController() const { return m_Controller; }
    Pointer<class NiTimeController*>& GetController() { return m_Controller; }
    void SetController(const Pointer<class NiTimeController*>& value) { m_Controller = value; }

    const Pointer<class NiInterpolator*>& GetInterpolator() const { return m_Interpolator; }
    Pointer<class NiInterpolator*>& GetInterpolator() { return m_Interpolator; }
    void SetInterpolator(const Pointer<class NiInterpolator*>& value) { m_Interpolator = value; }

    const Pointer<class NiObject*>& GetUnknownLink2() const { return m_UnknownLink2; }
    Pointer<class NiObject*>& GetUnknownLink2() { return m_UnknownLink2; }
    void SetUnknownLink2(const Pointer<class NiObject*>& value) { m_UnknownLink2 = value; }

    const ushort& GetUnknownShort0() const { return m_UnknownShort0; }
    ushort& GetUnknownShort0() { return m_UnknownShort0; }
    void SetUnknownShort0(const ushort& value) { m_UnknownShort0 = value; }

    const byte& GetPriority() const { return m_Priority; }
    byte& GetPriority() { return m_Priority; }
    void SetPriority(const byte& value) { m_Priority = value; }

    const Pointer<class NiStringPalette*>& GetStringPalette() const { return m_StringPalette; }
    Pointer<class NiStringPalette*>& GetStringPalette() { return m_StringPalette; }
    void SetStringPalette(const Pointer<class NiStringPalette*>& value) { m_StringPalette = value; }

    const string& GetNodeName() const { return m_NodeName; }
    string& GetNodeName() { return m_NodeName; }
    void SetNodeName(const string& value) { m_NodeName = value; }

    const StringOffset& GetNodeNameOffset() const { return m_NodeNameOffset; }
    StringOffset& GetNodeNameOffset() { return m_NodeNameOffset; }
    void SetNodeNameOffset(const StringOffset& value) { m_NodeNameOffset = value; }

    const string& GetPropertyType() const { return m_PropertyType; }
    string& GetPropertyType() { return m_PropertyType; }
    void SetPropertyType(const string& value) { m_PropertyType = value; }

    const StringOffset& GetPropertyTypeOffset() const { return m_PropertyTypeOffset; }
    StringOffset& GetPropertyTypeOffset() { return m_PropertyTypeOffset; }
    void SetPropertyTypeOffset(const StringOffset& value) { m_PropertyTypeOffset = value; }

    const string& GetControllerType() const { return m_ControllerType; }
    string& GetControllerType() { return m_ControllerType; }
    void SetControllerType(const string& value) { m_ControllerType = value; }

    const StringOffset& GetControllerTypeOffset() const { return m_ControllerTypeOffset; }
    StringOffset& GetControllerTypeOffset() { return m_ControllerTypeOffset; }
    void SetControllerTypeOffset(const StringOffset& value) { m_ControllerTypeOffset = value; }

    const string& GetVariable1() const { return m_Variable1; }
    string& GetVariable1() { return m_Variable1; }
    void SetVariable1(const string& value) { m_Variable1 = value; }

    const StringOffset& GetVariable1Offset() const { return m_Variable1Offset; }
    StringOffset& GetVariable1Offset() { return m_Variable1Offset; }
    void SetVariable1Offset(const StringOffset& value) { m_Variable1Offset = value; }

    const string& GetVariable2() const { return m_Variable2; }
    string& GetVariable2() { return m_Variable2; }
    void SetVariable2(const string& value) { m_Variable2 = value; }

    const StringOffset& GetVariable2Offset() const { return m_Variable2Offset; }
    StringOffset& GetVariable2Offset() { return m_Variable2Offset; }
    void SetVariable2Offset(const StringOffset& value) { m_Variable2Offset = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
