#pragma once

#include <filesystem>
#include <functional>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>

#include "nejlika.hpp"

namespace nejlika {

/**
 * @brief A one-way mapping between symbols (names) and their corresponding numerical values.
 * 
 * This is an active lookup, meaning that it is possible to add new symbols and their values to the lookup.
 * 
 * A method is provided to wait for a symbol to be added to the lookup.
 */
class Lookup
{
public:
    inline static const name core_prefix = "lego-universe";

    /**
     * @brief Constructs a Lookup object with the specified lookup file path.
     *
     * @param lookup The path to the lookup file.
     * @throw If the lookup file could not be parsed.
     */
    Lookup(const std::filesystem::path& lookup);

    /**
     * @brief Constructs a Lookup object from another Lookup object.
     *
     * @param other The other Lookup object.
     */
    Lookup(const Lookup& other);

    /**
     * @brief Gets the value of the specified symbol.
     *
     * @param symbol The symbol to get the value of.
     * @return The value of the specified symbol.
     * @throw If the specified symbol does not exist.
     */
    id GetValue(const name& symbol) const;

    /**
     * @brief Checks whether the specified symbol exists.
     * 
     * @param symbol The symbol to check.
     * @return Whether the specified symbol exists.
     */
    bool Exists(const name& symbol) const;
    
    /**
     * @brief Checks whether any symbol has the specified value.
     * 
     * @param value The value to check.
     * @return Whether any symbol has the specified value.
     */
    bool Exists(id value) const;

    /**
     * @brief Registers a new symbol with the specified value.
     * 
     * @param symbol The symbol to register.
     * @param value The value of the symbol.
     * @param overwrite Whether to overwrite the value of an existing symbol.
     * @throw If the specified symbol already exists with a different value and overwrite is false.
     */
    void Register(const name& symbol, id value, bool overwrite = false);

    /**
     * @brief Set up a callback to be called when the specified symbol is registered.
     * 
     * @param symbol The symbol to wait for.
     * @param callback The callback to call when the symbol is registered.
     */
    void AwaitValue(const name& symbol, std::function<void(id)> callback);

    /**
     * @brief Wait for a set of symbols to be registered.
     * 
     * @param symbols The symbols to wait for.
     * @param callback The callback to call when all symbols are registered.
     */
    void AwaitValues(const std::unordered_set<name>& symbols, const std::function<void()>& callback);

    /**
     * @brief Set metadata of a specified symbol.
     * 
     * @param symbol The symbol to set metadata of.
     * @param metadata The metadata to set.
     */
    void SetMetadata(const name& symbol, const std::string& metadata);

    /**
     * @brief Gets the metadata of a specified symbol.
     * 
     * @param symbol The symbol to get metadata of.
     * @return The metadata of the specified symbol or an empty string if the symbol does not exist.
     */
    const std::string& GetMetadata(const name& symbol) const;

    /**
     * @brief Gets the path to the lookup file.
     *
     * @return The path to the lookup file.
     */
    const std::filesystem::path& GetLookup() const;

    /**
     * @brief Gets the map of all symbols and their values.
     * 
     * @return The map of all symbols and their values.
     */
    const std::unordered_map<name, id>& GetMap() const;

    /**
     * @brief Sets the map of all symbols and their values.
     * 
     * @param map The map of all symbols and their values.
     */
    void SetMap(const std::unordered_map<name, id>& map);

    /**
     * @brief Get a set of all unresolved symbols.
     * 
     * @return A set of all unresolved symbols.
     */
    std::unordered_set<name> GetUnresolved() const;

    /**
     * Saves the lookup to file.
     */
    void Save();

    /**
     * @brief Register a mapping of core symbols.
     * 
     * @param symbols The symbols to register.
     */
    void RegisterCoreSymbols(const std::unordered_map<name, id>& symbols);

    /**
     * @brief Checks whether the specified symbol is a core symbol.
     * 
     * @param symbol The symbol to check.
     * @param value The value of the core symbol.
     * @return Whether the specified symbol is a core symbol.
     */
    bool IsCoreSymbol(const name& symbol, id& value) const;

    /**
     * @brief Checks whether the specified symbol is a core symbol.
     * 
     * A symbol is considered a core symbol if it is either:
     * a number;
     * or a string starting with the core_prefix.
     * 
     * @param symbol The symbol to check.
     * @return Whether the specified symbol is a core symbol.
     */
    static bool IsCoreSymbol(const name& symbol);

private:

    std::filesystem::path m_Lookup;

    std::unordered_map<name, id> m_LookupMap;

    std::unordered_map<name, std::string> m_Metadata;

    std::unordered_map<name, std::vector<std::function<void(int)>>> m_Callbacks;

    std::unordered_map<name, id> m_CoreSymbols;
};

} // namespace nejlika