#include "NifWrapper.hpp"

#include "Color3.hpp"
#include "Color4.hpp"
#include "Quaternion.hpp"
#include "NiMaterialProperty.hpp"
#include "NiAlphaProperty.hpp"
#include "NiSpecularProperty.hpp"
#include "NiVertexColorProperty.hpp"
#include "NiTexturingProperty.hpp"
#include "NiSourceTexture.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtx/matrix_interpolation.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <iostream>

namespace
{
    glm::vec3 ToGLM(const nejlika::geometry::Vector3& vec)
    {
        return glm::vec3(vec.Getx(), vec.Gety(), vec.Getz());
    }

    nejlika::geometry::Vector3 ToGeometry(const glm::vec3& vec)
    {
        nejlika::geometry::Vector3 v;
        v.Setx(vec.x);
        v.Sety(vec.y);
        v.Setz(vec.z);

        return v;
    }

    nejlika::geometry::Color4 ToGeometryColor4(const glm::vec4& vec)
    {
        nejlika::geometry::Color4 v;
        v.Setr(vec.r);
        v.Setg(vec.g);
        v.Setb(vec.b);
        v.Seta(vec.a);

        return v;
    }

    nejlika::geometry::Color3 ToGeometryColor3(const glm::vec3& vec)
    {
        nejlika::geometry::Color3 v;
        v.Setr(vec.r);
        v.Setg(vec.g);
        v.Setb(vec.b);

        return v;
    }


    glm::vec4 ToGLM(const nejlika::geometry::Quaternion& quat)
    {
        return glm::vec4(quat.Getx(), quat.Gety(), quat.Getz(), quat.Getw());
    }

    nejlika::geometry::Quaternion ToGeometry(const glm::vec4& quat)
    {
        nejlika::geometry::Quaternion q;
        q.Setx(quat.x);
        q.Sety(quat.y);
        q.Setz(quat.z);
        q.Setw(quat.w);

        return q;
    }

    nejlika::geometry::Matrix33 ConvertQuatToRotationMatrix(const glm::quat& quat)
    {
        glm::mat4 rotationMatrix = glm::mat4_cast(quat);

        std::vector<glm::vec3> rows(3);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                rows[i][j] = rotationMatrix[j][i];
            }
        }

        nejlika::geometry::Matrix33 result;
        result.Setm11(rows[0].x); result.Setm12(rows[0].y); result.Setm13(rows[0].z);
        result.Setm21(rows[1].x); result.Setm22(rows[1].y); result.Setm23(rows[1].z);
        result.Setm31(rows[2].x); result.Setm32(rows[2].y); result.Setm33(rows[2].z);

        return result;
    }
}

void NifWrapper::LoadNif(nejlika::Reader& reader)
{
    m_Header.Read(reader, 0, 0, 0);

    const auto& version = m_Header.GetVersion();
    const auto& blockTypes = m_Header.GetBlockTypes();
    const auto& userVersion = m_Header.GetUserVersion();
    const auto& blockTypeIndex = m_Header.GetBlockTypeIndex();
    const auto& numBlocks = m_Header.GetNumBlocks();
    const auto& blockSizes = m_Header.GetBlockSize();

    m_Blocks.clear();
    m_BlockNames.clear();

    m_Blocks.reserve(numBlocks);
    m_BlockNames.reserve(numBlocks);

    for (uint32_t i = 0; i < numBlocks; i++)
    {
        size_t blockTypePos = blockTypeIndex[i];

        if (blockTypePos >= blockTypes.size() || blockTypePos < 0)
        {
            // Increase the read head by the block size
            reader.SetReadHead(reader.GetReadHead() + blockSizes[i]);

            continue;
        }

        const auto& blockType = blockTypes[blockTypePos];
        std::string blockName(blockType.GetValue().begin(), blockType.GetValue().end());
        auto* block = nejlika::geometry::Factory::Create(blockName);

        if (!block)
        {
            throw std::runtime_error("Failed to create block: " + blockName);
        }

        if (i == 16)
        {
            std::cout << "Block: " << blockName << std::endl;
        }

        size_t startHead = reader.GetReadHead();
        block->Read(reader, version, userVersion, 0);
        size_t endHead = reader.GetReadHead();

        uint32_t blockSize = endHead - startHead;
        if (blockSize != blockSizes[i])
        {
            delete block;
            throw std::runtime_error("Block size mismatch");
        }

        m_Blocks.push_back(block);
        m_BlockNames[block] = blockName;
    
        reader.SetReadHead(startHead + blockSizes[i]);
    }

    m_Footer.Read(reader, m_Header.GetVersion(), m_Header.GetUserVersion(), 0);
}

void NifWrapper::ExportNif(nejlika::Writer& writer)
{
    const auto& version = m_Header.GetVersion();
    
    // We have to re-calculate the block sizes
    m_Header.GetBlockSize().clear();

    nejlika::Writer blockWriter;

    int index = 0;

    for (auto* block : m_Blocks)
    {
        if (index == 16)
        {
            std::cout << "Block: " << m_BlockNames[block] << std::endl;
        }

        uint32_t startHead = blockWriter.GetWriteHead();
        block->Write(blockWriter, version, 0, 0);
        uint32_t endHead = blockWriter.GetWriteHead();

        m_Header.GetBlockSize().push_back(endHead - startHead);

        index++;
    }

    m_Header.SetNumBlockTypes(m_Header.GetBlockTypes().size());
    m_Header.SetNumStrings(m_Header.GetStrings().size());
    m_Header.SetNumBlocks(m_Blocks.size());

    m_Header.Write(writer, version, 0, 0);

    const auto& data = blockWriter.GetBuffer();

    for (uint32_t i = 0; i < blockWriter.GetWriteHead(); i++)
    {
        writer.Write(data[i]);
    }

    m_Footer.Write(writer, version, 0, 0);
}

const nejlika::geometry::Header& NifWrapper::GetHeader() const
{
    return m_Header;
}

nejlika::geometry::Header& NifWrapper::GetHeader()
{
    return m_Header;
}

const std::vector<nejlika::geometry::Construct*>& NifWrapper::GetBlocks() const
{
    return m_Blocks;
}

std::vector<nejlika::geometry::Construct*>& NifWrapper::GetBlocks()
{
    return m_Blocks;
}

const std::unordered_map<nejlika::geometry::Construct*, std::string>& NifWrapper::GetBlockNames() const
{
    return m_BlockNames;
}

std::unordered_map<nejlika::geometry::Construct*, std::string>& NifWrapper::GetBlockNames()
{
    return m_BlockNames;
}

nejlika::geometry::Construct* NifWrapper::AddBlock(const std::string& name)
{
    auto* block = nejlika::geometry::Factory::Create(name);

    if (!block)
    {
        throw std::runtime_error("Failed to create block: " + name);
    }

    m_Blocks.push_back(block);
    m_BlockNames[block] = name;

    m_Header.GetBlockSize().push_back(0);

    uint32_t index = -1;

    for (uint32_t i = 0; i < m_Header.GetBlockTypes().size(); i++)
    {
        std::string blockName(m_Header.GetBlockTypes()[i].GetValue().begin(), m_Header.GetBlockTypes()[i].GetValue().end());

        if (blockName == name)
        {
            index = i;
            break;
        }
    }

    if (index == -1) {
        index = m_Header.GetBlockTypes().size();
        nejlika::geometry::SizedString blockType;
        blockType.SetValue(std::vector<char>(name.begin(), name.end()));
        blockType.SetLength(name.size());
    
        m_Header.GetBlockTypes().push_back(blockType);
    }

    m_Header.GetBlockTypeIndex().push_back(index);

    return block;
}


uint32_t NifWrapper::GetBlockIndex(nejlika::geometry::Construct* block) const
{
    for (uint32_t i = 0; i < m_Blocks.size(); i++)
    {
        if (m_Blocks[i] == block)
        {
            return i;
        }
    }

    return 0xFFFFFFFF;
}

nejlika::geometry::Construct* NifWrapper::GetBlock(uint32_t index) const
{
    if (index >= m_Blocks.size())
    {
        return nullptr;
    }

    return m_Blocks[index];
}

nejlika::geometry::NiNode* NifWrapper::FindNodeByName(const std::string &name)
{
    for (auto* block : m_Blocks)
    {
        if (auto* node = dynamic_cast<nejlika::geometry::NiNode*>(block))
        {
            const auto nameIndex = node->GetName().GetIndex();
            const auto nodeName = GetString(nameIndex);

            if (nodeName == name)
            {
                return node;
            }
        }
    }

    return nullptr;
}

std::string NifWrapper::GetString(uint32_t index) const
{
    if (index >= m_Header.GetStrings().size())
    {
        return "";
    }

    const auto& value = m_Header.GetStrings()[index].GetValue();

    return std::string(value.begin(), value.end());
}

glm::mat4 NifWrapper::GetWorldTransform(nejlika::geometry::NiAVObject* node)
{
    glm::mat4 transform = glm::mat4(1.0f);

    while (node)
    {
        glm::mat4 localTransform = glm::mat4(1.0f);

        if (auto* niNode = dynamic_cast<nejlika::geometry::NiNode*>(node))
        {
            localTransform = glm::translate(localTransform, 
                glm::vec3(
                    niNode->GetTranslation().Getx(),
                    niNode->GetTranslation().Gety(),
                    niNode->GetTranslation().Getz()
                )
            );

            const auto& rotation = niNode->GetRotation();
            glm::mat3 rotationMatrix = {
                { rotation.Getm11(), rotation.Getm12(), rotation.Getm13() },
                { rotation.Getm21(), rotation.Getm22(), rotation.Getm23() },
                { rotation.Getm31(), rotation.Getm32(), rotation.Getm33() }
            };

            glm::quat q = glm::quat_cast(rotationMatrix);
            glm::mat4 r = glm::mat4_cast(q);

            localTransform = localTransform * r;

            localTransform = glm::scale(localTransform, glm::vec3(niNode->GetScale()));
        }

        transform = localTransform * transform;

        node = GetParent(node);
    }

    return transform;
}

nejlika::geometry::NiNode* NifWrapper::GetParent(nejlika::geometry::NiAVObject* node)
{
    const auto blockIndex = GetBlockIndex(node);

    for (auto* block : m_Blocks)
    {
        if (auto* niNode = dynamic_cast<nejlika::geometry::NiNode*>(block))
        {
            for (auto child : niNode->GetChildren())
            {
                if (child.GetIndex() == blockIndex)
                {
                    return niNode;
                }
            }
        }
    }

    return nullptr;
}

void NifWrapper::SetParent(nejlika::geometry::NiAVObject* node, nejlika::geometry::NiNode* parent)
{
    // First, unset the current parent if it exists
    auto* currentParent = GetParent(node);

    const auto nodeIndex = GetBlockIndex(node);

    if (currentParent)
    {
        auto& children = currentParent->GetChildren();

        for (auto it = children.begin(); it != children.end(); ++it)
        {
            if (it->GetIndex() == nodeIndex)
            {
                children.erase(it);
                currentParent->SetNumChildren(children.size());
                break;
            }
        }
    }

    // Then, set the new parent
    if (parent)
    {
        if (currentParent == nullptr)
        {
            // Remove the node from the root
            for (auto it = m_Footer.GetRoots().begin(); it != m_Footer.GetRoots().end(); ++it)
            {
                if (it->GetIndex() == nodeIndex)
                {
                    m_Footer.GetRoots().erase(it);
                    m_Footer.SetNumRoots(m_Footer.GetRoots().size());
                    break;
                }
            }
        }

        auto& children = parent->GetChildren();
        children.push_back(PointerTo<nejlika::geometry::NiAVObject>(node));
        parent->SetNumChildren(children.size());
    }
    else
    {
        // Add the node to the root
        m_Footer.GetRoots().push_back(PointerTo<nejlika::geometry::NiObject>(node));
        m_Footer.SetNumRoots(m_Footer.GetRoots().size());
    }
}

const std::vector<nejlika::geometry::NiNode*> NifWrapper::GetRootNodes() const
{
    std::vector<nejlika::geometry::NiNode*> rootNodes;

    for (const auto& ptr : m_Footer.GetRoots())
    {
        if (auto* niObject = FindBlock(ptr))
        {
            if (auto* niNode = dynamic_cast<nejlika::geometry::NiNode*>(niObject))
            {
                rootNodes.push_back(niNode);
            }
        }
    }

    return rootNodes;
}

void NifWrapper::SetRootNodes(const std::vector<nejlika::geometry::NiNode*>& nodes)
{
    m_Footer.GetRoots().clear();

    for (auto* node : nodes)
    {
        m_Footer.GetRoots().push_back(PointerTo<nejlika::geometry::NiObject>(node));
    }

    m_Footer.SetNumRoots(nodes.size());
}

nejlika::geometry::StringIndex NifWrapper::GetStringIndex(const std::string &str)
{
    const auto& strings = m_Header.GetStrings();

    uint32_t maxStringLength = 0;

    for (uint32_t i = 0; i < strings.size(); i++)
    {
        const auto& value = strings[i].GetValue();
        
        std::string string(value.begin(), value.end());

        maxStringLength = std::max(maxStringLength, static_cast<uint32_t>(string.size()));

        if (string == str)
        {
            return i;
        }
    }

    nejlika::geometry::StringIndex index = strings.size();

    nejlika::geometry::SizedString sizedString;
    sizedString.SetValue(std::vector<char>(str.begin(), str.end()));
    sizedString.SetLength(str.size());

    maxStringLength = std::max(maxStringLength, static_cast<uint32_t>(str.size()));

    m_Header.GetStrings().push_back(sizedString);
    m_Header.SetMaxStringLength(maxStringLength);

    return index;
}

void NifWrapper::Cleanup()
{
    for (auto* block : m_Blocks)
    {
        delete block;
    }

    m_Blocks.clear();
    m_BlockNames.clear();
}

nejlika::geometry::NiTriShape* NifWrapper::ImportMesh(const MeshImport& mesh)
{
    if (mesh.m_Vertices.size() > std::numeric_limits<uint16_t>::max())
    {
        throw std::runtime_error("Too many vertices");
    }

    if ((mesh.m_Indices.size()) > std::numeric_limits<uint16_t>::max())
    {
        throw std::runtime_error("Too many indices");
    }

    auto* niTriShape = AddBlock<nejlika::geometry::NiTriShape>("NiTriShape");

    auto* data = AddBlock<nejlika::geometry::NiTriShapeData>("NiTriShapeData");

    auto& vertices = data->GetVertices();
    auto& triangles = data->GetTriangles();
    auto& normals = data->GetNormals();
    auto& colors = data->GetVertexColors();
    auto& uvSets = data->GetUVSets();
    auto& uvSet = uvSets.emplace_back();

    for (const auto& vertex : mesh.m_Vertices)
    {
        vertices.push_back(ToGeometry(vertex));

        if (mesh.m_UVs.empty())
        {
            uvSet.push_back(nejlika::geometry::TexCoord(vertex.x, vertex.z));
        }
    }

    if (mesh.m_UVs.size() > 0)
    {
        for (const auto& uv : mesh.m_UVs)
        {
            uvSet.push_back(nejlika::geometry::TexCoord(uv.x, uv.y));
        }
    }

    if (mesh.m_Indices.size() % 3 != 0)
    {
        throw std::runtime_error("Invalid indices size");
    }

    if (uvSet.size() != vertices.size())
    {
        throw std::runtime_error("UV size mismatch");
    }

    for (size_t i = 0; i < mesh.m_Indices.size(); i += 3)
    {
        nejlika::geometry::Triangle triangle;
        triangle.Setv3(mesh.m_Indices[i]);
        triangle.Setv2(mesh.m_Indices[i + 1]);
        triangle.Setv1(mesh.m_Indices[i + 2]);

        triangles.push_back(triangle);
    }

    // Calculate normals, one per vertex
    if (mesh.m_Normals.empty())
    {
        std::vector<glm::vec3> vertexNormals(vertices.size());

        for (size_t i = 0; i < triangles.size(); ++i)
        {
            const auto& triangle = triangles[i];
            const auto& v0 = ToGLM(vertices[triangle.Getv1()]);
            const auto& v1 = ToGLM(vertices[triangle.Getv2()]);
            const auto& v2 = ToGLM(vertices[triangle.Getv3()]);

            glm::vec3 normal = glm::normalize(glm::cross(v1 - v0, v2 - v0));

            vertexNormals[triangle.Getv1()] += normal;
            vertexNormals[triangle.Getv2()] += normal;
            vertexNormals[triangle.Getv3()] += normal;
        }

        for (size_t i = 0; i < vertexNormals.size(); ++i)
        {
            normals.push_back(ToGeometry(glm::normalize(vertexNormals[i])));
        }
    }
    else
    {
        if (mesh.m_Normals.size() != mesh.m_Vertices.size())
        {
            throw std::runtime_error("Normals size mismatch");
        }

        for (const auto& normal : mesh.m_Normals)
        {
            normals.push_back(ToGeometry(normal));
        }
    }

    data->SetUnknownInt(0);
    data->SetNumVertices(vertices.size());
    data->SetKeepFlags(0);
    data->SetCompressFlags(0);
    data->SetHasVertices(true);
    data->SetNumUVSets(1);
    data->SetHasNormals(true);

    glm::vec3 center;
    float radius = 0.0f;

    for (const auto& vertex : mesh.m_Vertices)
    {
        center += vertex;
    }

    center /= static_cast<float>(mesh.m_Vertices.size());

    for (const auto& vertex : mesh.m_Vertices)
    {
        radius = glm::max(radius, glm::distance(center, vertex));
    }

    data->SetCenter(ToGeometry(center));
    data->SetRadius(radius);

    if (!mesh.m_Colors.empty())
    {
        if (mesh.m_Colors.size() != mesh.m_Vertices.size())
        {
            throw std::runtime_error("Colors size mismatch");
        }

        for (const auto& color : mesh.m_Colors)
        {
            colors.push_back(ToGeometryColor4(color));
        }

        data->SetHasVertexColors(true);
    }
    else
    {
        data->SetHasVertexColors(false);
    }
    
    data->SetConsistencyFlags(nejlika::geometry::ConsistencyType::CT_STATIC);

    data->SetNumTriangles(triangles.size());
    data->SetNumTrianglePoints(triangles.size() * 3);

    data->SetHasTriangles(true);

    data->SetNumMatchGroups(0);

    niTriShape->SetData(PointerTo<nejlika::geometry::NiGeometryData>(data));

    // Other settings
    niTriShape->GetName().SetIndex(GetStringIndex("Geometry"));
    niTriShape->SetFlags(16);
    niTriShape->SetScale(1.0f);
    niTriShape->SetTranslation(ToGeometry(glm::vec3(0.0f)));
    // Roll 180 degrees
    glm::vec3 axis = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::quat rotation = glm::angleAxis(glm::radians(180.0f), axis);
    niTriShape->SetRotation(ConvertQuatToRotationMatrix(rotation));
    niTriShape->SetActiveMaterial(-1);
    niTriShape->SetDirtyFlag(true);

    // Properties
    auto* niMaterialProperty = AddBlock<nejlika::geometry::NiMaterialProperty>("NiMaterialProperty");

    niMaterialProperty->GetName().SetIndex(GetStringIndex("Material"));
    niMaterialProperty->SetNumExtraDataList(0);
    niMaterialProperty->SetAmbientColor(ToGeometryColor3(mesh.m_DiffuseColor));
    niMaterialProperty->SetDiffuseColor(ToGeometryColor3(glm::vec3(1.0f)));
    niMaterialProperty->SetSpecularColor(ToGeometryColor3(glm::vec3(0.0f)));
    niMaterialProperty->SetEmissiveColor(ToGeometryColor3(glm::vec3(0.0f)));
    niMaterialProperty->SetGlossiness(4.0f);
    niMaterialProperty->SetAlpha(mesh.m_DiffuseAlpha);
    niMaterialProperty->SetFlags(0);
    
    auto* niAlphaProperty = AddBlock<nejlika::geometry::NiAlphaProperty>("NiAlphaProperty");

    niAlphaProperty->GetName().SetIndex(GetStringIndex("Alpha"));
    niAlphaProperty->SetFlags(237);
    niAlphaProperty->SetThreshold(mesh.m_DiffuseAlphaThreshold);
    niAlphaProperty->SetNumExtraDataList(0);

    auto* niSpecularProperty = AddBlock<nejlika::geometry::NiSpecularProperty>("NiSpecularProperty");

    niSpecularProperty->GetName().SetIndex(GetStringIndex("Specular"));
    niSpecularProperty->SetNumExtraDataList(0);
    niSpecularProperty->SetFlags(0);

    auto* niVertexColorProperty = AddBlock<nejlika::geometry::NiVertexColorProperty>("NiVertexColorProperty");

    niVertexColorProperty->GetName().SetIndex(GetStringIndex("VertexColor"));
    niVertexColorProperty->SetNumExtraDataList(0);
    niVertexColorProperty->SetFlags(40);

    nejlika::geometry::NiTexturingProperty* niTexturingProperty = nullptr;

    if (!mesh.m_DiffuseTexture.empty())
    {
        niTexturingProperty = AddBlock<nejlika::geometry::NiTexturingProperty>("NiTexturingProperty");

        niTexturingProperty->GetName().SetIndex(GetStringIndex("Texturing"));
        niTexturingProperty->SetNumExtraDataList(0);
        niTexturingProperty->SetFlags(4);
        niTexturingProperty->SetTextureCount(9);
        niTexturingProperty->SetHasBaseTexture(true);
        niTexturingProperty->SetHasDarkTexture(false);
        niTexturingProperty->SetHasDetailTexture(false);
        niTexturingProperty->SetHasGlossTexture(false);
        niTexturingProperty->SetHasGlowTexture(false);
        niTexturingProperty->SetHasBumpMapTexture(false);
        niTexturingProperty->SetHasNormalTexture(false);
        niTexturingProperty->SetHasUnknown2Texture(false);
        niTexturingProperty->SetHasDecal0Texture(false);
        niTexturingProperty->SetNumShaderTextures(0);
        
        auto* niSourceTexture = AddBlock<nejlika::geometry::NiSourceTexture>("NiSourceTexture");

        niSourceTexture->SetNumExtraDataList(0);
        niSourceTexture->SetUseExternal(true);
        niSourceTexture->GetFileName().SetIndex(GetStringIndex(mesh.m_DiffuseTexture));
        niSourceTexture->SetPixelLayout(nejlika::geometry::PixelLayout::PIX_LAY_DEFAULT);
        niSourceTexture->SetUseMipmaps(nejlika::geometry::MipMapFormat::MIP_FMT_DEFAULT);
        niSourceTexture->SetAlphaFormat(nejlika::geometry::AlphaFormat::ALPHA_SMOOTH);
        niSourceTexture->SetIsStatic(true);

        auto& baseTexture = niTexturingProperty->GetBaseTexture();
        baseTexture.SetSource(PointerTo<nejlika::geometry::NiSourceTexture>(niSourceTexture));
        baseTexture.SetFlags(12800);
        baseTexture.SetHasTextureTransform(false);
    }

    niTriShape->SetProperties({ 
        PointerTo<nejlika::geometry::NiProperty>(niMaterialProperty),
        PointerTo<nejlika::geometry::NiProperty>(niAlphaProperty),
        PointerTo<nejlika::geometry::NiProperty>(niSpecularProperty),
        PointerTo<nejlika::geometry::NiProperty>(niVertexColorProperty)
    });

    if (niTexturingProperty)
    {
        niTriShape->GetProperties().push_back(PointerTo<nejlika::geometry::NiProperty>(niTexturingProperty));
    }

    niTriShape->SetNumProperties(niTriShape->GetProperties().size());

    auto* root = FindNodeByName("SceneNode");

    if (root)
    {
        root->GetChildren().push_back(PointerTo<nejlika::geometry::NiAVObject>(niTriShape));

        root->SetNumChildren(root->GetNumChildren() + 1);
    }

    return niTriShape;
}

nejlika::geometry::NiNode* NifWrapper::AddNode(const std::string& name, nejlika::geometry::NiNode* parent)
{
    auto* niNode = AddBlock<nejlika::geometry::NiNode>("NiNode");

    niNode->GetName().SetIndex(GetStringIndex(name));
    niNode->SetFlags(8);
    niNode->SetTranslation(ToGeometry(glm::vec3(0.0f)));
    niNode->SetRotation(nejlika::geometry::Matrix33());
    niNode->SetScale(1.0f);

    if (parent)
    {
        parent->GetChildren().push_back(PointerTo<nejlika::geometry::NiAVObject>(niNode));
        parent->SetNumChildren(parent->GetNumChildren() + 1);
    }
    else
    {
        m_Footer.GetRoots().push_back(PointerTo<nejlika::geometry::NiObject>(niNode));
        m_Footer.SetNumRoots(m_Footer.GetRoots().size());
    }

    return niNode;
}

void NifWrapper::SetLocalTransform(nejlika::geometry::NiAVObject* node, const glm::vec3& position, const glm::quat& rotation, float scale)
{
    node->SetTranslation(ToGeometry(position));
    node->SetRotation(ConvertQuatToRotationMatrix(rotation));
    node->SetScale(scale);
}

void NifWrapper::SetPosition(nejlika::geometry::NiAVObject* node, const glm::vec3& position)
{
    node->SetTranslation(ToGeometry(position));
}

void NifWrapper::SetRotation(nejlika::geometry::NiAVObject* node, const glm::quat& rotation)
{
    node->SetRotation(ConvertQuatToRotationMatrix(rotation));
}

void NifWrapper::SetScale(nejlika::geometry::NiAVObject* node, float scale)
{
    node->SetScale(scale);
}

glm::vec3 NifWrapper::GetPosition(nejlika::geometry::NiAVObject* node) const
{
    return ToGLM(node->GetTranslation());
}

glm::quat NifWrapper::GetRotation(nejlika::geometry::NiAVObject* node) const
{
    nejlika::geometry::Matrix33 rotation = node->GetRotation();
    
    glm::mat3 rotationMatrix = {
        { rotation.Getm11(), rotation.Getm12(), rotation.Getm13() },
        { rotation.Getm21(), rotation.Getm22(), rotation.Getm23() },
        { rotation.Getm31(), rotation.Getm32(), rotation.Getm33() }
    };

    return glm::quat_cast(rotationMatrix);
}

float NifWrapper::GetScale(nejlika::geometry::NiAVObject* node) const
{
    return node->GetScale();
}

void NifWrapper::AddProperty(nejlika::geometry::NiAVObject* node, nejlika::geometry::NiProperty* property)
{
    node->GetProperties().push_back(PointerTo<nejlika::geometry::NiProperty>(property));
    node->SetNumProperties(node->GetProperties().size());
}

void NifWrapper::RemoveProperty(nejlika::geometry::NiAVObject* node, nejlika::geometry::NiProperty* property)
{
    auto& properties = node->GetProperties();

    const auto propertyIndex = GetBlockIndex(property);

    for (auto it = properties.begin(); it != properties.end(); ++it)
    {
        if (it->GetIndex() == propertyIndex)
        {
            properties.erase(it);
            node->SetNumProperties(properties.size());
            break;
        }
    }
}

NifWrapper::~NifWrapper()
{
    Cleanup();
}

std::vector<MeshImport> MeshImport::Decompose(uint32_t vertexLimit)
{
    // Make sure vertexLimit is divisible by 3, if not, lower it to the nearest multiple of 3
    if (vertexLimit % 3 != 0)
    {
        vertexLimit -= vertexLimit % 3;
    }

    std::vector<MeshImport> outputMeshes;
    std::unordered_map<size_t, size_t> globalToLocalIndexMap; // Maps global indices to new local indices
    MeshImport currentMesh;
    currentMesh.m_DiffuseTexture = m_DiffuseTexture;
    currentMesh.m_DiffuseColor = m_DiffuseColor;
    currentMesh.m_DiffuseAlpha = m_DiffuseAlpha;
    currentMesh.m_DiffuseAlphaThreshold = m_DiffuseAlphaThreshold;

    size_t currentTriangleCount = 0;

    for (size_t i = 0; i < m_Indices.size(); i += 3) // Process indices in groups of three (triangles)
    {
        // Temporary indices for the current triangle
        std::vector<uint32_t> newIndices(3); // Pre-size to hold three elements
        bool exceedsVertexLimit = false;

        for (size_t j = 0; j < 3; ++j) // For each vertex in the triangle
        {
            uint32_t globalIndex = m_Indices[i + j];

            if (globalToLocalIndexMap.find(globalIndex) == globalToLocalIndexMap.end())
            {
                // Add vertex to the current mesh if not already added
                if (currentMesh.m_Vertices.size() >= vertexLimit)
                {
                    exceedsVertexLimit = true;
                    break;
                }

                globalToLocalIndexMap[globalIndex] = currentMesh.m_Vertices.size();
                currentMesh.m_Vertices.push_back(m_Vertices[globalIndex]);
                if (!m_Normals.empty())
                    currentMesh.m_Normals.push_back(m_Normals[globalIndex]);
                if (!m_Colors.empty())
                    currentMesh.m_Colors.push_back(m_Colors[globalIndex]);
                if (!m_UVs.empty())
                    currentMesh.m_UVs.push_back(m_UVs[globalIndex]);
            }

            // Add the local index to the triangle
            newIndices[j] = globalToLocalIndexMap[globalIndex];
        }

        // If adding the current triangle exceeds vertex or triangle limits, finalize the current mesh
        if (exceedsVertexLimit || currentTriangleCount >= vertexLimit)
        {
            outputMeshes.push_back(std::move(currentMesh));
            currentMesh = MeshImport();
            globalToLocalIndexMap.clear();
            currentTriangleCount = 0;

            // Restart processing the current triangle in the new mesh
            for (size_t j = 0; j < 3; ++j)
            {
                uint32_t globalIndex = m_Indices[i + j];
                globalToLocalIndexMap[globalIndex] = currentMesh.m_Vertices.size();
                currentMesh.m_Vertices.push_back(m_Vertices[globalIndex]);
                if (!m_Normals.empty())
                    currentMesh.m_Normals.push_back(m_Normals[globalIndex]);
                if (!m_Colors.empty())
                    currentMesh.m_Colors.push_back(m_Colors[globalIndex]);
                if (!m_UVs.empty())
                    currentMesh.m_UVs.push_back(m_UVs[globalIndex]);

                newIndices[j] = globalToLocalIndexMap[globalIndex];
            }
        }

        // Add the current triangle to the mesh
        currentMesh.m_Indices.insert(currentMesh.m_Indices.end(), newIndices.begin(), newIndices.end());
        currentTriangleCount++;
    }

    // Add the final mesh if it has any data
    if (!currentMesh.m_Vertices.empty())
    {
        outputMeshes.push_back(std::move(currentMesh));
    }

    return outputMeshes;
}
