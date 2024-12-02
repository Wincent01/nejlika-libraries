#include "ObjectInformation.hpp"

using namespace nejlika::world;

nejlika::world::ObjectInformation::ObjectInformation(nejlika::Reader &io, uint32_t version)
{
    m_TemplateId = io.Read<uint32_t>();

    if (version >= 38) {
        m_NodeType = static_cast<NodeType>(io.Read<uint32_t>());
    } else {
        m_NodeType = NodeType::EnvironmentObject;
    }

    if (version >= 32) {
        m_GlomId = io.Read<uint32_t>();
    }

    m_Position = io.Read<vector3>();

    m_Rotation = io.Read<vector4>();

    m_Scale = io.Read<float>();

    m_Properties = Properties(io);

    if (version >= 7) {
        m_RenderTechnique = RenderTechnique(io);
    }
}

void nejlika::world::ObjectInformation::Save(nejlika::Writer &io, uint32_t version) const
{
    io.Write(m_ObjectId);

    io.Write(m_TemplateId);

    if (version >= 38) {
        io.Write(static_cast<uint32_t>(m_NodeType));
    }

    if (version >= 32) {
        io.Write(m_GlomId);
    }

    io.Write(m_Position);

    io.Write(m_Rotation);

    io.Write(m_Scale);

    m_Properties.Save(io);

    if (version >= 7) {
        m_RenderTechnique.Save(io);
    }
}

uint64_t nejlika::world::ObjectInformation::GetObjectId() const
{
    return m_ObjectId;
}

uint32_t nejlika::world::ObjectInformation::GetTemplateId() const
{
    return m_TemplateId;
}

NodeType nejlika::world::ObjectInformation::GetNodeType() const
{
    return m_NodeType;
}

uint32_t nejlika::world::ObjectInformation::GetGlomId() const
{
    return m_GlomId;
}

const vector3 &nejlika::world::ObjectInformation::GetPosition() const
{
    return m_Position;
}

const vector4 &nejlika::world::ObjectInformation::GetRotation() const
{
    return m_Rotation;
}

float nejlika::world::ObjectInformation::GetScale() const
{
    return m_Scale;
}

Properties &nejlika::world::ObjectInformation::GetProperties()
{
    return m_Properties;
}

const Properties &nejlika::world::ObjectInformation::GetProperties() const
{
    return m_Properties;
}

RenderTechnique &nejlika::world::ObjectInformation::GetRenderTechnique()
{
    return m_RenderTechnique;
}

void nejlika::world::ObjectInformation::SetObjectId(uint64_t objectId)
{
    m_ObjectId = objectId;
}

void nejlika::world::ObjectInformation::SetTemplateId(uint32_t templateId)
{
    m_TemplateId = templateId;
}

void nejlika::world::ObjectInformation::SetNodeType(NodeType nodeType)
{
    m_NodeType = nodeType;
}

void nejlika::world::ObjectInformation::SetGlomId(uint32_t glomId)
{
    m_GlomId = glomId;
}

void nejlika::world::ObjectInformation::SetPosition(const vector3 &position)
{
    m_Position = position;
}

void nejlika::world::ObjectInformation::SetRotation(const vector4 &rotation)
{
    m_Rotation = rotation;
}

void nejlika::world::ObjectInformation::SetScale(float scale)
{
    m_Scale = scale;
}

nejlika::world::ObjectInformation::~ObjectInformation()
{
}

