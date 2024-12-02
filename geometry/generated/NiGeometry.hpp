#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiGeometryData.hpp"
#include "NiSkinInstance.hpp"
#include "string.hpp"
#include "string.hpp"
#include "NiProperty.hpp"
#include "NiAVObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Describes a visible scene element with vertices like a mesh, a particle system, lines, etc.
 *         
 */
class NiGeometry : public NiAVObject
{
protected:
    /**
     * Data index (NiTriShapeData/NiTriStripData).
     */
    Pointer<class NiGeometryData*> m_Data;
    /**
     * Skin instance index.
     */
    Pointer<class NiSkinInstance*> m_SkinInstance;
    /**
     * Num Materials
     */
    uint m_NumMaterials;
    /**
     * Unknown string.  Shader?
     */
    std::vector<string> m_MaterialName;
    /**
     * Unknown integer; often -1. (Is this a link, array index?)
     */
    std::vector<int> m_MaterialExtraData;
    /**
     * Active Material; often -1. (Is this a link, array index?)
     */
    int m_ActiveMaterial;
    /**
     * Shader.
     */
    bool m_HasShader;
    /**
     * The shader name.
     */
    string m_ShaderName;
    /**
     * Unknown value, usually -1. (Not a link)
     */
    int m_UnknownInteger;
    /**
     * Cyanide extension (only in version 10.2.0.0?).
     */
    byte m_UnknownByte;
    /**
     * Unknown.
     */
    int m_UnknownInteger2;
    /**
     * Dirty Flag?
     */
    bool m_DirtyFlag;
    /**
     * Two property links, used by Bethesda.
     */
    std::vector<Pointer<class NiProperty*>> m_BSProperties;

public:
    const Pointer<class NiGeometryData*>& GetData() const { return m_Data; }
    Pointer<class NiGeometryData*>& GetData() { return m_Data; }
    void SetData(const Pointer<class NiGeometryData*>& value) { m_Data = value; }

    const Pointer<class NiSkinInstance*>& GetSkinInstance() const { return m_SkinInstance; }
    Pointer<class NiSkinInstance*>& GetSkinInstance() { return m_SkinInstance; }
    void SetSkinInstance(const Pointer<class NiSkinInstance*>& value) { m_SkinInstance = value; }

    const uint& GetNumMaterials() const { return m_NumMaterials; }
    uint& GetNumMaterials() { return m_NumMaterials; }
    void SetNumMaterials(const uint& value) { m_NumMaterials = value; }

    const std::vector<string>& GetMaterialName() const { return m_MaterialName; }
    std::vector<string>& GetMaterialName() { return m_MaterialName; }
    void SetMaterialName(const std::vector<string>& value) { m_MaterialName = value; }

    const std::vector<int>& GetMaterialExtraData() const { return m_MaterialExtraData; }
    std::vector<int>& GetMaterialExtraData() { return m_MaterialExtraData; }
    void SetMaterialExtraData(const std::vector<int>& value) { m_MaterialExtraData = value; }

    const int& GetActiveMaterial() const { return m_ActiveMaterial; }
    int& GetActiveMaterial() { return m_ActiveMaterial; }
    void SetActiveMaterial(const int& value) { m_ActiveMaterial = value; }

    const bool& GetHasShader() const { return m_HasShader; }
    bool& GetHasShader() { return m_HasShader; }
    void SetHasShader(const bool& value) { m_HasShader = value; }

    const string& GetShaderName() const { return m_ShaderName; }
    string& GetShaderName() { return m_ShaderName; }
    void SetShaderName(const string& value) { m_ShaderName = value; }

    const int& GetUnknownInteger() const { return m_UnknownInteger; }
    int& GetUnknownInteger() { return m_UnknownInteger; }
    void SetUnknownInteger(const int& value) { m_UnknownInteger = value; }

    const byte& GetUnknownByte() const { return m_UnknownByte; }
    byte& GetUnknownByte() { return m_UnknownByte; }
    void SetUnknownByte(const byte& value) { m_UnknownByte = value; }

    const int& GetUnknownInteger2() const { return m_UnknownInteger2; }
    int& GetUnknownInteger2() { return m_UnknownInteger2; }
    void SetUnknownInteger2(const int& value) { m_UnknownInteger2 = value; }

    const bool& GetDirtyFlag() const { return m_DirtyFlag; }
    bool& GetDirtyFlag() { return m_DirtyFlag; }
    void SetDirtyFlag(const bool& value) { m_DirtyFlag = value; }

    const std::vector<Pointer<class NiProperty*>>& GetBSProperties() const { return m_BSProperties; }
    std::vector<Pointer<class NiProperty*>>& GetBSProperties() { return m_BSProperties; }
    void SetBSProperties(const std::vector<Pointer<class NiProperty*>>& value) { m_BSProperties = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
