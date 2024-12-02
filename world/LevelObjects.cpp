#include "LevelObjects.hpp"

#include <algorithm>

using namespace nejlika::world;

LevelObjects::LevelObjects(nejlika::Reader& io, uint32_t version) {
    uint32_t objectCount = io.Read<uint32_t>();
    m_ObjectIDMap.reserve(objectCount);

    for (uint32_t i = 0; i < objectCount; i++) {
        uint64_t objectID = io.Read<uint64_t>();

        auto result = m_ObjectIDMap.emplace(objectID, ObjectInformation(io, version));

        if (!result.second) {
            throw std::runtime_error("Duplicate object ID found");
        }

        auto& object = result.first->second;

        object.SetObjectId(objectID);
        
        int32_t lot = object.GetTemplateId();

        m_LotMultiMap.emplace(lot, objectID);
        
        // Insert into object map and lot map

        if (lot == SpawnerLot) {
            const auto& spawnerPropIt = object.GetProperties().GetPropertyMap().find(u"spawntemplate");
            if (spawnerPropIt != object.GetProperties().GetPropertyMap().end()) {
                const auto& spawnerProp = spawnerPropIt->second;
                m_SpawnerMultiMap.emplace(spawnerProp.GetInteger(), objectID);
            }
        }
    }
}

void LevelObjects::Save(nejlika::Writer& io, uint32_t version) const {
    io.Write<uint32_t>(m_ObjectIDMap.size());
    for (const auto& [id, object] : m_ObjectIDMap) {
        object.Save(io, version);
    }
}

ObjectInformation& LevelObjects::GetObject(uint64_t objectID) {
    auto it = m_ObjectIDMap.find(objectID);
    if (it == m_ObjectIDMap.end()) {
        throw std::runtime_error("Object ID not found");
    }
    return it->second;
}

bool LevelObjects::HasObject(uint64_t objectID) const {
    return m_ObjectIDMap.find(objectID) != m_ObjectIDMap.end();
}

std::vector<uint64_t> LevelObjects::GetObjects(int32_t lot) {
    std::vector<uint64_t> objects;
    auto range = m_LotMultiMap.equal_range(lot);
    for (auto it = range.first; it != range.second; ++it) {
        objects.push_back(it->second);
    }
    return objects;
}

std::vector<uint64_t> LevelObjects::GetSpawners(int32_t lot) {
    std::vector<uint64_t> spawners;
    auto range = m_SpawnerMultiMap.equal_range(lot);
    for (auto it = range.first; it != range.second; ++it) {
        spawners.push_back(it->second);
    }
    return spawners;
}

void LevelObjects::AddObject(const ObjectInformation& object) {
    uint64_t objectID = object.GetObjectId();
    int32_t lot = object.GetTemplateId();
    
    // Insert into object map and lot map
    auto result = m_ObjectIDMap.emplace(objectID, object);
    if (result.second) {
        m_LotMultiMap.emplace(lot, objectID);
    }

    if (lot == SpawnerLot) {
        const auto& spawnerPropIt = object.GetProperties().GetPropertyMap().find(u"spawntemplate");
        if (spawnerPropIt != object.GetProperties().GetPropertyMap().end()) {
            const auto& spawnerProp = spawnerPropIt->second;
            m_SpawnerMultiMap.emplace(spawnerProp.GetInteger(), objectID);
        }
    }
}

void LevelObjects::RemoveObjects(int32_t lot) {
    std::vector<uint64_t> objectsToRemove;
    auto range = m_LotMultiMap.equal_range(lot);
    for (auto it = range.first; it != range.second; ++it) {
        objectsToRemove.push_back(it->second);
    }
    for (auto objectID : objectsToRemove) {
        RemoveObjectHelper(objectID);
    }
    m_LotMultiMap.erase(lot);
}

void LevelObjects::RemoveObject(uint64_t objectID) {
    RemoveObjectHelper(objectID);
}

void LevelObjects::RemoveSpawner(int32_t spawnerLot) {
    std::vector<uint64_t> spawnersToRemove;
    auto range = m_SpawnerMultiMap.equal_range(spawnerLot);
    for (auto it = range.first; it != range.second; ++it) {
        spawnersToRemove.push_back(it->second);
    }
    for (auto spawnerID : spawnersToRemove) {
        RemoveObjectHelper(spawnerID);
    }
    m_SpawnerMultiMap.erase(spawnerLot);
}

void LevelObjects::ClearObjects() {
    m_ObjectIDMap.clear();
    m_LotMultiMap.clear();
    m_SpawnerMultiMap.clear();
}

void LevelObjects::RemoveObjectHelper(uint64_t objectID) {
    auto it = m_ObjectIDMap.find(objectID);
    if (it == m_ObjectIDMap.end()) {
        return;
    }
    int32_t lot = it->second.GetTemplateId();

    // Remove from lot map
    auto lotRange = m_LotMultiMap.equal_range(lot);
    std::vector<decltype(lotRange.first)> toErase;
    for (auto lotIt = lotRange.first; lotIt != lotRange.second; ++lotIt) {
        if (lotIt->second == objectID) {
            toErase.push_back(lotIt);
        }
    }
    for (auto it : toErase) {
        m_LotMultiMap.erase(it);
    }

    // Remove from spawner map if applicable
    if (lot == SpawnerLot) {
        const auto& spawnerPropIt = it->second.GetProperties().GetPropertyMap().find(u"spawntemplate");
        if (spawnerPropIt != it->second.GetProperties().GetPropertyMap().end()) {
            const auto& spawnerProp = spawnerPropIt->second;
            auto spawnerRange = m_SpawnerMultiMap.equal_range(spawnerProp.GetInteger());
            for (auto spawnerIt = spawnerRange.first; spawnerIt != spawnerRange.second;) {
                if (spawnerIt->second == objectID) {
                    spawnerIt = m_SpawnerMultiMap.erase(spawnerIt);
                } else {
                    ++spawnerIt;
                }
            }
        }
    }

    m_ObjectIDMap.erase(it);
}

std::unordered_map<uint64_t, ObjectInformation>& LevelObjects::GetObjectMap() {
    return m_ObjectIDMap;
}

const std::unordered_map<uint64_t, ObjectInformation>& LevelObjects::GetObjectMap() const {
    return m_ObjectIDMap;
}