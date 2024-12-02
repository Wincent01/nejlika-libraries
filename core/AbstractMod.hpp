#pragma once

#include <vector>
#include <functional>
#include <unordered_map>
#include <boost/json.hpp>

#include "nejlika.hpp"
#include "AbstractSerializable.hpp"

namespace nejlika
{

class AbstractMod : public AbstractSerializable, public std::enable_shared_from_this<AbstractMod>
{
public:
    /**
     * @brief Parses the specified JSON object into a mod.
     * 
     * @param json The JSON object to parse.
     * @return The parsed mod, of the appropriate type.
     * @throw If the specified JSON object could not be parsed or is of an unknown type.
     */
    static std::shared_ptr<AbstractMod> Parse(nejlika::Context& ctx, const boost::json::object& json);

    /**
     * @brief Gets the name of the mod. A name this mod can be identified by.
     * 
     * @return The name of the mod.
     */
    const name& GetName() const;

    /**
     * @brief Gets the type of the mod.
     * 
     * @return The type of the mod.
     */
    const std::string& GetType() const;

    /**
     * @brief Gets the explicit ID of the mod. Will be chosen when first picking an ID for the mod.
     * 
     * @return The explicit ID of the mod.
     */
    const id& GetExplicitId() const;

    /**
     * @brief Gets the aliases of the mod. These are named the mod can be identified by.
     * 
     * @return The aliases of the mod.
     */
    const std::vector<name>& GetAliases() const;

    /**
     * @brief Check if this mod can be identified by the specified name.
     * 
     * @param name The name to check.
     * @return Whether this mod can be identified by the specified name.
     * @note This will also check the aliases.
     */
    bool CanIdentifyWith(const name& name) const;

    /**
     * @brief Gets the action of the mod.
     * 
     * @return The action of the mod.
     */
    const std::string& GetAction() const;

    /**
     * @brief Gets whether to show the default values of the mod.
     * 
     * @return Whether to show the default values of the mod.
     * @deprecated With the introduction of TypeTemplates, this is unused.
     */
    bool GetShowDefaults() const;

    /**
     * @brief Apply the mod.
     * 
     * @param ctx The context to apply the mod to.
     */
    virtual void Apply(nejlika::Context& ctx);

    /**
     * @brief Serializes the object into a JSON object.
     * 
     * @return The serialized JSON object.
     */
    virtual boost::json::object Serialize() const override;

    /**
     * @brief Deserializes the specified JSON object into the object.
     * 
     * @param json The JSON object to deserialize.
     */
    virtual void Deserialize(const boost::json::object& json) override;

    /**
     * @brief Tries to get the ID of the mod.
     * 
     * @param modId The ID of the mod.
     * @return Whether the ID was successfully retrieved.
     */
    bool TryGetId(nejlika::Context& ctx, id& modId) const;

    /**
     * @brief Gets the unique runtime ID of the mod.
     * 
     * @return The unique runtime ID of the mod.
     */
    size_t GetUniqueRuntimeId() const;

    /**
     * @brief Sets the unique runtime ID of the mod.
     * 
     * @param uniqueRuntimeId The unique runtime ID of the mod.
     */
    void SetUniqueRuntimeId(size_t uniqueRuntimeId);

    /**
     * @brief Raname the mod.
     * 
     * @param name The new name of the mod.
     * 
     * @note This will also update the aliases to include the old name. Will not update usage of the old name.
     */
    void Rename(const name& name);
    
protected:
    // Required
    name m_Name;

    std::string m_Type;

    // Optional
    id m_ExplicitId = 0;

    std::vector<name> m_Aliases;

    std::string m_Action;

    bool m_ShowDefaults;

    size_t m_UniqueRuntimeId = 0;

    std::string m_ExtraData;
};

}