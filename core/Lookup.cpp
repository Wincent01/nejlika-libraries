#include "Lookup.hpp"

#include <fstream>

#include <boost/json.hpp>

#include "JsonUtilities.hpp"

#include <iostream>

using namespace nejlika;

Lookup::Lookup(const std::filesystem::path& lookup)
{
    m_Lookup = lookup;

    // Check if the file exists.
    if (!std::filesystem::exists(lookup))
    {
        // Empty lookup
        return;
    }

    // Read the json file
    std::ifstream file(lookup);

    std::string json((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    // Parse the json
    auto doc = boost::json::parse(json);


    // The document is a map, so we can iterate over it.
    for (const auto& [k, v] : doc.get_object()) {
        name key = (name) k;
        
        if (v.is_int64())
        {
            m_LookupMap[key] = v.get_int64();

            continue;
        }
        
        if (!v.is_object()) {
            std::stringstream ss;

            ss << "Invalid value for key \"" << key << "\" in lookup.";

            throw std::runtime_error(ss.str());
        }

        // Get the data
        auto data = v.get_object();

        // Get the id
        auto id = data["id"].get_int64();

        m_LookupMap[key] = id;

        // Get the metadata
        auto metadata = data["metadata"].get_string();

        m_Metadata[key] = metadata;
    }
}

nejlika::Lookup::Lookup(const Lookup &other)
{
    m_Lookup = other.m_Lookup;
    m_LookupMap = other.m_LookupMap;
    m_Metadata = other.m_Metadata;
    m_CoreSymbols = other.m_CoreSymbols;
}

id Lookup::GetValue(const name& symbol) const
{
    id value;

    if (IsCoreSymbol(symbol, value)) {
        return value;
    }

    const auto& it = m_LookupMap.find(symbol);

    if (it == m_LookupMap.end())
    {
        std::stringstream ss;

        ss << "Symbol \"" << symbol << "\" does not exist in the lookup.";

        throw std::runtime_error(ss.str());
    }

    return it->second;
}

bool nejlika::Lookup::Exists(const name &symbol) const
{
    return IsCoreSymbol(symbol) || (m_CoreSymbols.find(symbol) != m_CoreSymbols.end()) || (m_LookupMap.find(symbol) != m_LookupMap.end());
}

bool nejlika::Lookup::Exists(id value) const
{
    for (const auto& [k, v] : m_LookupMap)
    {
        if (v == value)
        {
            return true;
        }
    }

    return false;
}

void Lookup::Register(const name& symbol, id value, bool overwrite)
{
    if (IsCoreSymbol(symbol)) {
        return;
    }

    auto it = m_LookupMap.find(symbol);

    if (it != m_LookupMap.end())
    {
        if (!overwrite && it->second != value)
        {
            std::stringstream ss;

            ss << "Symbol \"" << symbol << "\" already exists in the lookup with a different value.";

            throw std::runtime_error(ss.str());
        }

        it->second = value;

        return;
    }
    
    m_LookupMap[symbol] = value;

    // Call all callbacks
    auto callbackIt = m_Callbacks.find(symbol);

    if (callbackIt == m_Callbacks.end())
    {
        return;
    }

    for (auto& callback : callbackIt->second)
    {
        callback(value);
    }

    m_Callbacks.erase(callbackIt);
}

void Lookup::AwaitValue(const name& symbol, std::function<void(id)> callback)
{
    // If it's only whitespace, throw an error.
    if (symbol.find_first_not_of(' ') == std::string::npos)
    {
        std::stringstream ss;

        ss << "Symbol \"" << symbol << "\" is only whitespace.";

        throw std::runtime_error(ss.str());
    }

    if (Exists(symbol))
    {
        callback(GetValue(symbol));

        return;
    }

    auto it = m_LookupMap.find(symbol);

    if (it != m_LookupMap.end())
    {
        callback(it->second);

        return;
    }

    m_Callbacks[symbol].push_back(callback);
}

void nejlika::Lookup::AwaitValues(const std::unordered_set<name> &symbols, const std::function<void()>& callback)
{
    if (symbols.empty())
    {
        callback();

        return;
    }

    std::shared_ptr<size_t> count = std::make_shared<size_t>(symbols.size());

    for (const auto& symbol : symbols)
    {
        AwaitValue(symbol, [this, &symbols, count, callback](id)
        {
            if (--*count == 0)
            {
                callback();
            }
        });
    }
}

void Lookup::SetMetadata(const name& symbol, const std::string& metadata)
{
    m_Metadata[symbol] = metadata;
}

const std::string& Lookup::GetMetadata(const name& symbol) const
{
    const auto& it = m_Metadata.find(symbol);

    if (it == m_Metadata.end())
    {
        static std::string empty;

        return empty;
    }

    return it->second;
}

const std::filesystem::path& Lookup::GetLookup() const
{
    return m_Lookup;
}

const std::unordered_map<name, id> &nejlika::Lookup::GetMap() const
{
    return m_LookupMap;
}

void nejlika::Lookup::SetMap(const std::unordered_map<name, id> &map)
{
    m_LookupMap = map;
}

std::unordered_set<name> nejlika::Lookup::GetUnresolved() const
{
    std::unordered_set<name> unresolved;

    for (const auto& [k, v] : m_Callbacks)
    {
        unresolved.emplace(k);
    }

    return unresolved;
}

void Lookup::Save()
{
    // Create the json document
    boost::json::object doc;

    // Iterate over the lookup map
    for (const auto& [k, v] : m_LookupMap)
    {
        const auto& it = m_Metadata.find(k);

        if (it == m_Metadata.end())
        {
            doc[k] = v;

            continue;
        }

        boost::json::object data;

        data["id"] = v;
        data["metadata"] = it->second;

        doc[k] = data;
    }

    // Write the json to file
    std::ofstream file(m_Lookup);

    nejlika::json_pretty_print(file, doc);

    file.close();
}

void nejlika::Lookup::RegisterCoreSymbols(const std::unordered_map<name, id> &symbols)
{
    // Insert the core symbols
    m_CoreSymbols.insert(symbols.begin(), symbols.end());
}

bool nejlika::Lookup::IsCoreSymbol(const name &symbol, id &value) const
{
    try {
        value = std::stoi(symbol);

        return true;
    } catch (...) {
        // cont...
    }

    if (!symbol.starts_with(core_prefix)) {
        return false;
    }

    // Check in the core symbols
    const auto& it = m_CoreSymbols.find(symbol);

    if (it != m_CoreSymbols.end())
    {
        value = it->second;

        return true;
    }
    
    // In the format "core:<value>"
    try {
        value = std::stoi(symbol.substr(core_prefix.size() + 1));
    } catch (...) {
        return false;
    }

    return true;
}

bool nejlika::Lookup::IsCoreSymbol(const name &symbol)
{
    // Check if it can be converted to an integer
    try {
        [[maybe_unused]] auto value = std::stoi(symbol);

        return true;
    } catch (...) {
        // cont...
    }
    
    return symbol.starts_with(core_prefix);
}
