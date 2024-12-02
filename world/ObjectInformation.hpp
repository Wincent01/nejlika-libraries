#pragma once

#include <string>
#include <vector>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"
#include "WritePointer.hpp"
#include "Properties.hpp"
#include "RenderTechnique.hpp"

namespace nejlika::world
{

class ObjectInformation
{
public:
    ObjectInformation() = default;

    ObjectInformation(nejlika::Reader& io, uint32_t version);

    void Save(nejlika::Writer& io, uint32_t version) const;

    uint64_t GetObjectId() const;

    uint32_t GetTemplateId() const;

    NodeType GetNodeType() const;

    uint32_t GetGlomId() const;

    const vector3& GetPosition() const;

    const vector4& GetRotation() const;

    float GetScale() const;

    Properties& GetProperties();

    const Properties& GetProperties() const;

    RenderTechnique& GetRenderTechnique();

    void SetObjectId(uint64_t objectId);

    void SetTemplateId(uint32_t templateId);

    void SetNodeType(NodeType nodeType);

    void SetGlomId(uint32_t glomId);

    void SetPosition(const vector3& position);

    void SetRotation(const vector4& rotation);

    void SetScale(float scale);

    ~ObjectInformation();

private:
    uint64_t m_ObjectId;
    uint32_t m_TemplateId;
    NodeType m_NodeType = NodeType::EnvironmentObject;
    uint32_t m_GlomId = 0;
    vector3 m_Position;
    vector4 m_Rotation;
    float m_Scale = 1.0f;
    Properties m_Properties;
    RenderTechnique m_RenderTechnique;
};


}