#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <string>
#include <stdexcept>

#include <glm/glm.hpp>

#include "Pointer.hpp"
#include "Header.hpp"
#include "Footer.hpp"
#include "Matrix33.hpp"
#include "Vector3.hpp"
#include "Color4.hpp"
#include "NiTriBasedGeomData.hpp"
#include "Factory.hpp"
#include "NiTriShape.hpp"
#include "NiTriStrips.hpp"
#include "NiAVObject.hpp"
#include "NiTriShapeData.hpp"
#include "NiTriStripsData.hpp"
#include "NiNode.hpp"

struct MeshImport
{
    glm::vec3 m_Translation = glm::vec3(0.0f);
    glm::mat3 m_Rotation = glm::mat3(1.0f);
    float m_Scale = 1.0f;

    std::vector<glm::vec3> m_Vertices;
    std::vector<uint32_t> m_Indices;
    std::vector<glm::vec3> m_Normals;
    std::vector<glm::vec4> m_Colors;
    std::vector<glm::vec2> m_UVs;
    std::string m_DiffuseTexture = "";
    float m_DiffuseAlpha = 1.0f;
    float m_DiffuseAlphaThreshold = 0.0f;
    glm::vec3 m_DiffuseColor = glm::vec3(1.0f);

    std::vector<MeshImport> Decompose(uint32_t vertexLimit);
};

enum class TextureType
{
    Base,
    Dark,
    Detail,
    Gloss,
    Glow,
    BumpMap,
    Normal,
    Unknown2,
    Decal0
};

class NifWrapper
{
public:
    /**
     * @brief Load a NIF file
     *
     * @param reader The reader
     */
    void LoadNif(nejlika::Reader& reader);

    /**
     * @brief Export the NIF file
     *
     * @param writer The writer
     */
    void ExportNif(nejlika::Writer& writer);

    /**
     * @brief Get the header
     *
     * @return const nejlika::geometry::Header& The header
     */
    const nejlika::geometry::Header& GetHeader() const;

    /**
     * @brief Get the header
     *
     * @return nejlika::geometry::Header& The header
     */
    nejlika::geometry::Header& GetHeader();

    /**
     * @brief Get the blocks
     *
     * @return const std::vector<nejlika::geometry::Construct*>& The blocks
     */
    const std::vector<nejlika::geometry::Construct*>& GetBlocks() const;

    /**
     * @brief Get the blocks
     *
     * @return std::vector<nejlika::geometry::Construct*>& The blocks
     */
    std::vector<nejlika::geometry::Construct*>& GetBlocks();

    /**
     * @brief Get the block names
     *
     * @return const std::unordered_map<nejlika::geometry::Construct*, std::string>& The block names
     */
    const std::unordered_map<nejlika::geometry::Construct*, std::string>& GetBlockNames() const;

    /**
     * @brief Get the block names
     *
     * @return std::unordered_map<nejlika::geometry::Construct*, std::string>& The block names
     */
    std::unordered_map<nejlika::geometry::Construct*, std::string>& GetBlockNames();

    /**
     * @brief Add a block to the NIF
     *
     * @param name The name of the block
     * @return nejlika::geometry::Construct* The block
     */
    nejlika::geometry::Construct* AddBlock(const std::string& name);

    /**
     * @brief Get the block index
     *
     * @param block The block
     * @return uint32_t The block index
     */
    uint32_t GetBlockIndex(nejlika::geometry::Construct* block) const;

    /**
     * @brief Get a block by index
     *
     * @param index The index
     * @return nejlika::geometry::Construct* The block
     */
    nejlika::geometry::Construct* GetBlock(uint32_t index) const;

    /**
     * @brief Find a node by name
     *
     * @param name The name
     * @return nejlika::geometry::NiNode* The node
     */
    nejlika::geometry::NiNode* FindNodeByName(const std::string& name);

    /**
     * @brief Get a string by index
     *
     * @param index The index
     * @return std::string The string
     */
    std::string GetString(uint32_t index) const;

    /**
     * @brief Get the world transform of a node
     *
     * @param node The node
     * @return glm::mat4 The world transform
     */
    glm::mat4 GetWorldTransform(nejlika::geometry::NiAVObject* node);

    /**
     * @brief Get the parent of a node
     *
     * @param node The node
     * @return nejlika::geometry::NiNode* The parent
     */
    nejlika::geometry::NiNode* GetParent(nejlika::geometry::NiAVObject* node);

    /**
     * @brief Set the parent of a node
     *
     * @param node The node
     * @param parent The parent, or nullptr to add to the root
     */
    void SetParent(nejlika::geometry::NiAVObject* node, nejlika::geometry::NiNode* parent);

    /**
     * @brief Get the root nodes
     *
     * @return const std::vector<nejlika::geometry::NiNode*> The root nodes
     */
    const std::vector<nejlika::geometry::NiNode*> GetRootNodes() const;

    /**
     * @brief Set the root nodes
     *
     * @param nodes The root nodes
     */
    void SetRootNodes(const std::vector<nejlika::geometry::NiNode*>& nodes);

    /**
     * @brief Add a block to the NIF
     *
     * @tparam T The type of block
     * @param name The name of the block
     * @return T* The block
     */
    template <typename T> T* AddBlock(const std::string& name) { return dynamic_cast<T*>(AddBlock(name)); }

    /**
     * @brief Get a pointer to a block
     *
     * @tparam T The type of block
     * @param block The block
     * @return nejlika::geometry::Pointer<T*> The pointer
     */
    template <typename T> nejlika::geometry::Pointer<T*> PointerTo(nejlika::geometry::Construct* block) const
    {
        if (block == nullptr)
        {
            return nejlika::geometry::Pointer<T*>();
        }

        if (dynamic_cast<T*>(block) == nullptr)
        {
            throw std::runtime_error("Block is not of the correct type");
        }

        uint32_t index = GetBlockIndex(block);

        if (index == 0xFFFFFFFF)
        {
            throw std::runtime_error("Block not found");
        }

        return nejlika::geometry::Pointer<T*>(GetBlockIndex(block));
    }

    /**
     * @brief Find a block by pointer
     *
     * @tparam T The type of block
     * @param pointer The pointer
     * @return T* The block
     */
    template <typename T> T* FindBlock(const nejlika::geometry::Pointer<T*>& pointer) const { return pointer.Query(m_Blocks); }

    /**
     * @brief Get the string index of a string
     *
     * @param str The string
     * @note This will add the string to the string table if it does not exist
     * @return nejlika::geometry::StringIndex The string index
     */
    nejlika::geometry::StringIndex GetStringIndex(const std::string& str);

    /**
     * @brief Cleanup the NIF data
     */
    void Cleanup();

    /**
     * @brief Import a mesh into the NIF
     *
     * @param mesh The mesh
     * @param texture Optional texture
     * @return nejlika::geometry::NiTriShape* The shape
     */
    nejlika::geometry::NiTriShape* ImportMesh(const MeshImport& mesh);

    /**
     * @brief Add a mesh into the NIF
     *
     * @param name The name of the mesh
     * @param parent The parent of the node, or nullptr to add to the root
     */
    nejlika::geometry::NiTriShape* AddMesh(const std::string& name, nejlika::geometry::NiNode* parent);

    /**
     * @brief Add a node to the NIF
     *
     * @param name The name of the node
     * @param parent The parent of the node, or nullptr to add to the root
     */
    nejlika::geometry::NiNode* AddNode(const std::string& name, nejlika::geometry::NiNode* parent);

    /**
     * @brief Set the local transform of a node
     *
     * @param node The node
     * @param position The position
     * @param rotation The rotation
     * @param scale The scale
     */
    void SetLocalTransform(nejlika::geometry::NiAVObject* node, const glm::vec3& position, const glm::quat& rotation, float scale);

    /**
     * @brief Set the position of a node
     *
     * @param node The node
     * @param position The position
     */
    void SetPosition(nejlika::geometry::NiAVObject* node, const glm::vec3& position);

    /**
     * @brief Set the rotation of a node
     *
     * @param node The node
     * @param rotation The rotation
     */
    void SetRotation(nejlika::geometry::NiAVObject* node, const glm::quat& rotation);

    /**
     * @brief Set the scale of a node
     *
     * @param node The node
     * @param scale The scale
     */
    void SetScale(nejlika::geometry::NiAVObject* node, float scale);

    /**
     * @brief Get the position of a node
     *
     * @param node The node
     * @return glm::vec3 The position
     */
    glm::vec3 GetPosition(nejlika::geometry::NiAVObject* node) const;

    /**
     * @brief Get the rotation of a node
     *
     * @param node The node
     * @return glm::quat The rotation
     */
    glm::quat GetRotation(nejlika::geometry::NiAVObject* node) const;

    /**
     * @brief Get the scale of a node
     *
     * @param node The node
     * @return float The scale
     */
    float GetScale(nejlika::geometry::NiAVObject* node) const;

    /**
     * @brief Add a property to a node
     *
     * @param node The node
     * @param property The property
     */
    void AddProperty(nejlika::geometry::NiAVObject* node, nejlika::geometry::NiProperty* property);

    /**
     * @brief Remove a property from a node
     *
     * @param node The node
     * @param property The property
     */
    void RemoveProperty(nejlika::geometry::NiAVObject* node, nejlika::geometry::NiProperty* property);

    /**
     * @brief Get a property from a node
     *
     * @tparam T The type of property
     * @param node The node
     * @return T* The property, or nullptr if not found
     */
    template <typename T> T* GetProperty(nejlika::geometry::NiAVObject* node)
    {
        for (auto& propPtr : node->GetProperties())
        {
            nejlika::geometry::NiProperty* prop = propPtr.Query(m_Blocks);

            if (T* castedProp = dynamic_cast<T*>(prop))
            {
                return castedProp;
            }
        }

        return nullptr;
    }

    /**
     * @brief Set mesh vertices
     *
     * @param mesh The mesh
     * @param vertices The vertices
     */
    void SetMeshVertices(nejlika::geometry::NiTriBasedGeom* mesh, const std::vector<glm::vec3>& vertices);

    /**
     * @brief Set mesh normals
     *
     * @param mesh The mesh
     * @param normals The normals
     */
    void SetMeshNormals(nejlika::geometry::NiTriBasedGeom* mesh, const std::vector<glm::vec3>& normals);

    /**
     * @brief Set mesh UVs
     *
     * @param mesh The mesh
     * @param uvs The UVs
     */
    void SetMeshUVs(nejlika::geometry::NiTriBasedGeom* mesh, const std::vector<glm::vec2>& uvs);

    /**
     * @brief Set mesh vertex colors
     *
     * @param mesh The mesh
     * @param colors The colors
     */
    void SetMeshVertexColors(nejlika::geometry::NiTriBasedGeom* mesh, const std::vector<glm::vec4>& colors);

    /**
     * @brief Set mesh indices
     *
     * @param mesh The mesh
     * @param indices The indices
     */
    void SetMeshIndices(nejlika::geometry::NiTriBasedGeom* mesh, const std::vector<uint16_t>& indices);

    /**
     * @brief Set mesh texture
     *
     * @param mesh The mesh
     * @param texture The path to the texture
     * @param type The texture type
     */
    void SetMeshTexture(nejlika::geometry::NiTriBasedGeom* mesh, const std::string& texture, TextureType type = TextureType::Base);

    /**
     * @brief Get the mesh data
     *
     * @param mesh The mesh
     * @return nejlika::geometry::NiTriBasedGeomData* The mesh data
     */
    nejlika::geometry::NiTriBasedGeomData* GetMeshData(nejlika::geometry::NiTriBasedGeom* mesh);

    /**
     * @brief Destructor
     */
    ~NifWrapper();

private:
    nejlika::geometry::Header m_Header;
    nejlika::geometry::Footer m_Footer;

    std::vector<nejlika::geometry::Construct*> m_Blocks;
    std::unordered_map<nejlika::geometry::Construct*, std::string> m_BlockNames;
};
