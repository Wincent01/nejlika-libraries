#pragma once

#include <string>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "Waypoint.hpp"
#include "PlatformData.hpp"
#include "PropertyData.hpp"
#include "CameraData.hpp"
#include "SpawnerData.hpp"

namespace nejlika::world
{

class Path
{
public:
    Path(nejlika::Reader& io, version pathVersion);

    Path(PathType pathType, version pathVersion);

    Path(const Path& other);

    Path& operator=(const Path& other);

    void Save(nejlika::Writer& io, version pathVersion) const;

    version GetPathVersion() const;

    const str16& GetName() const;

    const str16& GetTypeName() const;

    PathType GetPathType() const;

    uint32_t GetFlags() const;

    PathBehavior GetBehavior() const;

    template<typename T>
    T& GetData() const {
        return *dynamic_cast<T*>(m_Data.get());
    }

    std::vector<Waypoint>& GetWaypoints();

    void SetName(const str16& name);

    void SetTypeName(const str16& typeName);
    
    void SetFlags(uint32_t flags);

    void SetBehavior(PathBehavior behavior);

    ~Path();

private:
    version m_PathVersion;

    str16 m_Name;

    str16 m_TypeName;

    PathType m_PathType;

    uint32_t m_Flags;

    PathBehavior m_Behavior;

    std::unique_ptr<WorldSerialize> m_Data;

    std::vector<Waypoint> m_Waypoints;
};

}