# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# C++ 20
set(CMAKE_CXX_STANDARD 20)

# Set the project name
project(world)

include_directories(${CMAKE_SOURCE_DIR})

# Add an executable target
add_library(world SHARED
    "Zone.cpp"
    "SceneReference.cpp"
    "BoundaryLine.cpp"
    "TransitionInformation.cpp"
    "Transition.cpp"
    "TransitionPoint.cpp"
    "PathInformation.cpp"
    "Path.cpp"
    "PropertyData.cpp"
    "PlatformData.cpp"
    "SpawnerData.cpp"
    "CameraData.cpp"
    "Waypoint.cpp"
    "PathKeyValuePairs.cpp"
    "NpcWaypointData.cpp"
    "CameraWaypointData.cpp"
    "PlatformWayointData.cpp"
    "SpawnerWaypointData.cpp"
    "RailWaypointData.cpp"
    "RacingWaypointData.cpp"
    "WritePointer.cpp"
    "Level.cpp"
    "OldLevelInfo.cpp"
    "LevelInfo.cpp"
    "EnvironmentInformation.cpp"
    "LightingInformation.cpp"
    "ParticleInformation.cpp"
    "SceneDrawDistances.cpp"
    "CullData.cpp"
    "SkydomeInformation.cpp"
    "EditorSettings.cpp"
    "LevelObjects.cpp"
    "ObjectInformation.cpp"
    "Properties.cpp"
    "Property.cpp"
    "RenderTechnique.cpp"
    "RenderAttribute.cpp"
    "Particle.cpp"
    "WorldRegistry.cpp"
    "World.cpp"
    "Terrain.cpp"
    "TerrainChunk.cpp"
    "TerrainColorMap.cpp"
    "TerrainDirectDrawSurface.cpp"
    "TerrainFoliage.cpp"
    "TerrainHeightMap.cpp"
)

target_include_directories(world PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link against the libraries
target_link_libraries(world core)
