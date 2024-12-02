#pragma once

#include <string>
#include <vector>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"
#include "WritePointer.hpp"
#include "ObjectInformation.hpp"

namespace nejlika::world
{

class LevelObjects
{
public:
    LevelObjects() = default;
    LevelObjects(nejlika::Reader& io, uint32_t version);
    void Save(nejlika::Writer& io, uint32_t version) const;

    std::vector<uint64_t> GetObjects(int32_t lot);
    std::vector<uint64_t> GetSpawners(int32_t lot);
    ObjectInformation& GetObject(uint64_t objectID);
    bool HasObject(uint64_t objectID) const;

    void AddObject(const ObjectInformation& object);
    void RemoveObjects(int32_t lot);
    void RemoveObject(uint64_t objectID);
    void RemoveSpawner(int32_t spawnerLot);
    void ClearObjects();

    std::unordered_map<uint64_t, ObjectInformation>& GetObjectMap();
    const std::unordered_map<uint64_t, ObjectInformation>& GetObjectMap() const;

    ~LevelObjects() = default;  // Destructor now handled by default

private:
    void RemoveObjectHelper(uint64_t objectID); // Helper for removal logic

    std::unordered_map<uint64_t, ObjectInformation> m_ObjectIDMap;
    std::unordered_multimap<int32_t, uint64_t> m_LotMultiMap;
    std::unordered_multimap<int32_t, uint64_t> m_SpawnerMultiMap;

    static constexpr int32_t SpawnerLot = 176;
};


}