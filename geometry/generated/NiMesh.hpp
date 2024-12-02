#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "MeshPrimitiveType.hpp"
#include "SphereBV.hpp"
#include "MeshData.hpp"
#include "NiMeshModifier.hpp"
#include "ExtraMeshDataEpicMickey.hpp"
#include "ExtraMeshDataEpicMickey2.hpp"
#include "NiRenderObject.hpp"
namespace nejlika::geometry {


class NiMesh : public NiRenderObject
{
protected:
    /**
     * The primitive type of the mesh, such as triangles or lines.
     */
    MeshPrimitiveType m_PrimitiveType;
    int m_Unknown51;
    int m_Unknown52;
    int m_Unknown53;
    int m_Unknown54;
    float m_Unknown55;
    int m_Unknown56;
    /**
     * The number of submeshes contained in this mesh.
     */
    ushort m_NumSubmeshes;
    /**
     * Sets whether hardware instancing is being used.
     */
    bool m_InstancingEnabled;
    /**
     * The combined bounding volume of all submeshes.
     */
    SphereBV m_Bound;
    uint m_NumDatas;
    std::vector<MeshData> m_Datas;
    uint m_NumModifiers;
    std::vector<Pointer<class NiMeshModifier*>> m_Modifiers;
    /**
     * Unknown.
     */
    byte m_Unknown100;
    /**
     * Unknown.
     */
    int m_Unknown101;
    /**
     * Size of additional data.
     */
    uint m_Unknown102;
    std::vector<float> m_Unknown103;
    int m_Unknown200;
    std::vector<ExtraMeshDataEpicMickey> m_Unknown201;
    int m_Unknown250;
    std::vector<int> m_Unknown251;
    int m_Unknown300;
    short m_Unknown301;
    int m_Unknown302;
    std::vector<byte> m_Unknown303;
    int m_Unknown350;
    std::vector<ExtraMeshDataEpicMickey2> m_Unknown351;
    int m_Unknown400;

public:
    const MeshPrimitiveType& GetPrimitiveType() const { return m_PrimitiveType; }
    MeshPrimitiveType& GetPrimitiveType() { return m_PrimitiveType; }
    void SetPrimitiveType(const MeshPrimitiveType& value) { m_PrimitiveType = value; }

    const int& GetUnknown51() const { return m_Unknown51; }
    int& GetUnknown51() { return m_Unknown51; }
    void SetUnknown51(const int& value) { m_Unknown51 = value; }

    const int& GetUnknown52() const { return m_Unknown52; }
    int& GetUnknown52() { return m_Unknown52; }
    void SetUnknown52(const int& value) { m_Unknown52 = value; }

    const int& GetUnknown53() const { return m_Unknown53; }
    int& GetUnknown53() { return m_Unknown53; }
    void SetUnknown53(const int& value) { m_Unknown53 = value; }

    const int& GetUnknown54() const { return m_Unknown54; }
    int& GetUnknown54() { return m_Unknown54; }
    void SetUnknown54(const int& value) { m_Unknown54 = value; }

    const float& GetUnknown55() const { return m_Unknown55; }
    float& GetUnknown55() { return m_Unknown55; }
    void SetUnknown55(const float& value) { m_Unknown55 = value; }

    const int& GetUnknown56() const { return m_Unknown56; }
    int& GetUnknown56() { return m_Unknown56; }
    void SetUnknown56(const int& value) { m_Unknown56 = value; }

    const ushort& GetNumSubmeshes() const { return m_NumSubmeshes; }
    ushort& GetNumSubmeshes() { return m_NumSubmeshes; }
    void SetNumSubmeshes(const ushort& value) { m_NumSubmeshes = value; }

    const bool& GetInstancingEnabled() const { return m_InstancingEnabled; }
    bool& GetInstancingEnabled() { return m_InstancingEnabled; }
    void SetInstancingEnabled(const bool& value) { m_InstancingEnabled = value; }

    const SphereBV& GetBound() const { return m_Bound; }
    SphereBV& GetBound() { return m_Bound; }
    void SetBound(const SphereBV& value) { m_Bound = value; }

    const uint& GetNumDatas() const { return m_NumDatas; }
    uint& GetNumDatas() { return m_NumDatas; }
    void SetNumDatas(const uint& value) { m_NumDatas = value; }

    const std::vector<MeshData>& GetDatas() const { return m_Datas; }
    std::vector<MeshData>& GetDatas() { return m_Datas; }
    void SetDatas(const std::vector<MeshData>& value) { m_Datas = value; }

    const uint& GetNumModifiers() const { return m_NumModifiers; }
    uint& GetNumModifiers() { return m_NumModifiers; }
    void SetNumModifiers(const uint& value) { m_NumModifiers = value; }

    const std::vector<Pointer<class NiMeshModifier*>>& GetModifiers() const { return m_Modifiers; }
    std::vector<Pointer<class NiMeshModifier*>>& GetModifiers() { return m_Modifiers; }
    void SetModifiers(const std::vector<Pointer<class NiMeshModifier*>>& value) { m_Modifiers = value; }

    const byte& GetUnknown100() const { return m_Unknown100; }
    byte& GetUnknown100() { return m_Unknown100; }
    void SetUnknown100(const byte& value) { m_Unknown100 = value; }

    const int& GetUnknown101() const { return m_Unknown101; }
    int& GetUnknown101() { return m_Unknown101; }
    void SetUnknown101(const int& value) { m_Unknown101 = value; }

    const uint& GetUnknown102() const { return m_Unknown102; }
    uint& GetUnknown102() { return m_Unknown102; }
    void SetUnknown102(const uint& value) { m_Unknown102 = value; }

    const std::vector<float>& GetUnknown103() const { return m_Unknown103; }
    std::vector<float>& GetUnknown103() { return m_Unknown103; }
    void SetUnknown103(const std::vector<float>& value) { m_Unknown103 = value; }

    const int& GetUnknown200() const { return m_Unknown200; }
    int& GetUnknown200() { return m_Unknown200; }
    void SetUnknown200(const int& value) { m_Unknown200 = value; }

    const std::vector<ExtraMeshDataEpicMickey>& GetUnknown201() const { return m_Unknown201; }
    std::vector<ExtraMeshDataEpicMickey>& GetUnknown201() { return m_Unknown201; }
    void SetUnknown201(const std::vector<ExtraMeshDataEpicMickey>& value) { m_Unknown201 = value; }

    const int& GetUnknown250() const { return m_Unknown250; }
    int& GetUnknown250() { return m_Unknown250; }
    void SetUnknown250(const int& value) { m_Unknown250 = value; }

    const std::vector<int>& GetUnknown251() const { return m_Unknown251; }
    std::vector<int>& GetUnknown251() { return m_Unknown251; }
    void SetUnknown251(const std::vector<int>& value) { m_Unknown251 = value; }

    const int& GetUnknown300() const { return m_Unknown300; }
    int& GetUnknown300() { return m_Unknown300; }
    void SetUnknown300(const int& value) { m_Unknown300 = value; }

    const short& GetUnknown301() const { return m_Unknown301; }
    short& GetUnknown301() { return m_Unknown301; }
    void SetUnknown301(const short& value) { m_Unknown301 = value; }

    const int& GetUnknown302() const { return m_Unknown302; }
    int& GetUnknown302() { return m_Unknown302; }
    void SetUnknown302(const int& value) { m_Unknown302 = value; }

    const std::vector<byte>& GetUnknown303() const { return m_Unknown303; }
    std::vector<byte>& GetUnknown303() { return m_Unknown303; }
    void SetUnknown303(const std::vector<byte>& value) { m_Unknown303 = value; }

    const int& GetUnknown350() const { return m_Unknown350; }
    int& GetUnknown350() { return m_Unknown350; }
    void SetUnknown350(const int& value) { m_Unknown350 = value; }

    const std::vector<ExtraMeshDataEpicMickey2>& GetUnknown351() const { return m_Unknown351; }
    std::vector<ExtraMeshDataEpicMickey2>& GetUnknown351() { return m_Unknown351; }
    void SetUnknown351(const std::vector<ExtraMeshDataEpicMickey2>& value) { m_Unknown351 = value; }

    const int& GetUnknown400() const { return m_Unknown400; }
    int& GetUnknown400() { return m_Unknown400; }
    void SetUnknown400(const int& value) { m_Unknown400 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
