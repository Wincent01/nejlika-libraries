#include "WorldRegistry.hpp"

#include <Configuration.hpp>
#include <Database.hpp>
#include <Lookup.hpp>
#include <TypeTemplateApplier.hpp>
#include <TypeTemplateContext.hpp>
#include <TypeTemplateInterface.hpp>

#include <Reader.hpp>

using namespace nejlika;
using namespace nejlika::world;

nejlika::world::WorldRegistry::WorldRegistry(const WorldRegistry &other)
{
    m_Worlds = other.m_Worlds;
}

ContextExtention *nejlika::world::WorldRegistry::Clone() const
{
    return new WorldRegistry(*this);
}

void nejlika::world::WorldRegistry::Initalize(Context& ctx)
{   
    ctx.templates->GetApplier().RegisterExtentionFunction("claim-world-id", [](
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) -> TypeTemplateError
    {
        auto* worldRegistry = context->GetContext().Extention<WorldRegistry>();

        const auto zone = context->FindValue(operation.at("zone"), TypeTemplateQueryOptions::Full);
        
        auto& world = worldRegistry->GetWorld(context->GetContext(), std::to_string(zone.as_int64()));

        context->SetVariable("id", world.ClaimObjectId());

        return TypeTemplateError::Success;
    });

    ctx.templates->GetApplier().RegisterExtentionFunction("add-world-object", [](
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) -> TypeTemplateError
    {
        auto* worldRegistry = context->GetContext().Extention<WorldRegistry>();

        const auto zone = context->FindValue(operation.at("zone"), TypeTemplateQueryOptions::Full);
        const auto levelId = context->FindValue(operation.at("level-id"), TypeTemplateQueryOptions::Full);
        const auto levelLayer = context->FindValue(operation.at("level-layer"), TypeTemplateQueryOptions::Full);

        const auto objectId = context->FindValue(operation.at("object-id"), TypeTemplateQueryOptions::Full);

        auto t = objectId.kind();

        const auto lot = context->FindValue(operation.at("lot"), TypeTemplateQueryOptions::Full);

        t = lot.kind();
        
        const auto x = context->FindValue(operation.at("x"), TypeTemplateQueryOptions::Full);
        const auto y = context->FindValue(operation.at("y"), TypeTemplateQueryOptions::Full);
        const auto z = context->FindValue(operation.at("z"), TypeTemplateQueryOptions::Full);

        const auto rx = context->FindValue(operation.at("rx"), TypeTemplateQueryOptions::Full);
        const auto ry = context->FindValue(operation.at("ry"), TypeTemplateQueryOptions::Full);
        const auto rz = context->FindValue(operation.at("rz"), TypeTemplateQueryOptions::Full);
        const auto rw = context->FindValue(operation.at("rw"), TypeTemplateQueryOptions::Full);

        const auto scale = context->FindValue(operation.at("scale"), TypeTemplateQueryOptions::Full);

        auto& world = worldRegistry->GetWorld(context->GetContext(), std::to_string(zone.as_int64()));
        auto& level = world.GetLevel(levelId.as_int64(), levelLayer.as_int64());

        auto& objects = level.GetObjects();

        ObjectInformation object;
        object.SetObjectId(objectId.to_number<int64_t>());
        object.SetTemplateId(lot.to_number<int64_t>());
        object.SetPosition({ (float) x.to_number<float>(), (float) y.to_number<float>(), (float) z.to_number<float>() });
        object.SetRotation({ (float) rw.to_number<float>(), (float) rx.to_number<float>(), (float) ry.to_number<float>(), (float) rz.to_number<float>() });
        object.SetScale((float) scale.to_number<float>());

        objects.AddObject(object);

        return TypeTemplateError::Success;
    });

    ctx.templates->GetApplier().RegisterExtentionFunction("remove-world-object", [](
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) -> TypeTemplateError
    {
        auto* worldRegistry = context->GetContext().Extention<WorldRegistry>();

        const auto zone = context->FindValue(operation.at("zone"), TypeTemplateQueryOptions::Full);
        const auto objectId = context->FindValue(operation.at("object-id"), TypeTemplateQueryOptions::Full);
        const auto lot = context->FindValue(operation.at("lot"), TypeTemplateQueryOptions::Full);

        if (objectId.is_null() && lot.is_null())
        {
            return TypeTemplateError("Either 'object-id' or 'lot' must be set.");
        }

        auto& world = worldRegistry->GetWorld(context->GetContext(), std::to_string(zone.as_int64()));
        
        const auto levelId = context->FindValue(operation.at("level-id"), TypeTemplateQueryOptions::Full).to_number<int32_t>();
        const auto levelLayer = context->FindValue(operation.at("level-layer"), TypeTemplateQueryOptions::Full).to_number<int32_t>();

        for (auto& [levelHash, level] : world.GetLevels()) {
            if (levelId != 0 && levelLayer != 0) {
                if (((static_cast<uint64_t>(levelId) << 32) | levelLayer) != levelHash) {
                    continue;
                }
            }

            auto& objects = level.GetObjects();

            if (!objectId.is_null())
            {
                objects.RemoveObject(objectId.to_number<int64_t>());
            }

            if (!lot.is_null())
            {
                objects.RemoveObjects(lot.to_number<int64_t>());
                objects.RemoveSpawner(lot.to_number<int64_t>());
            }
        }

        return TypeTemplateError::Success;
    });

    ctx.templates->GetApplier().RegisterExtentionFunction("transform-world-object", [](
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) -> TypeTemplateError
    {
        auto* worldRegistry = context->GetContext().Extention<WorldRegistry>();

        const auto zone = context->FindValue(operation.at("zone"), TypeTemplateQueryOptions::Full);
        const auto levelId = context->FindValue(operation.at("level-id"), TypeTemplateQueryOptions::Full);
        const auto levelLayer = context->FindValue(operation.at("level-layer"), TypeTemplateQueryOptions::Full);
        const auto objectId = context->FindValue(operation.at("object-id"), TypeTemplateQueryOptions::Full);
        const auto lot = context->FindValue(operation.at("lot"), TypeTemplateQueryOptions::Full);

        if (objectId.is_null() && lot.is_null())
        {
            return TypeTemplateError("Either 'object-id' or 'lot' must be set.");
        }

        const auto x = context->FindValue(operation.at("x"), TypeTemplateQueryOptions::Full);
        const auto y = context->FindValue(operation.at("y"), TypeTemplateQueryOptions::Full);
        const auto z = context->FindValue(operation.at("z"), TypeTemplateQueryOptions::Full);

        const auto rx = context->FindValue(operation.at("rx"), TypeTemplateQueryOptions::Full);
        const auto ry = context->FindValue(operation.at("ry"), TypeTemplateQueryOptions::Full);
        const auto rz = context->FindValue(operation.at("rz"), TypeTemplateQueryOptions::Full);
        const auto rw = context->FindValue(operation.at("rw"), TypeTemplateQueryOptions::Full);

        const auto scale = context->FindValue(operation.at("scale"), TypeTemplateQueryOptions::Full);

        auto& world = worldRegistry->GetWorld(context->GetContext(), std::to_string(zone.as_int64()));
        auto& level = world.GetLevel(levelId.as_int64(), levelLayer.as_int64());

        auto& objects = level.GetObjects();

        if (!objectId.is_null() && !objects.HasObject(objectId.as_uint64()))
        {
            return TypeTemplateError("Object not found.");
        }

        for (auto& [id, object] : objects.GetObjectMap())
        {
            if (!objectId.is_null() && id != objectId.as_uint64())
            {
                continue;
            }

            if (!lot.is_null() && object.GetTemplateId() != lot.as_int64())
            {
                // Check if the 'spawntemplate' property is set
                auto& properties = object.GetProperties().GetPropertyMap();

                const auto& propIt = properties.find(u"spawntemplate");

                auto found = false;

                if (propIt != properties.end())
                {
                    const auto& prop = propIt->second;

                    if (prop.GetValueAsString() == std::to_string(lot.as_int64()))
                    {
                        found = true;
                    }
                }

                if (!found)
                {
                    continue;
                }
            }

            if (!x.is_null() && !y.is_null() && !z.is_null())
            {
                object.SetPosition({ (float) x.to_number<float>(), (float) y.to_number<float>(), (float) z.to_number<float>() });
            }
            
            if (!rx.is_null() && !ry.is_null() && !rz.is_null() && !rw.is_null())
            {
                object.SetRotation({ (float) rw.to_number<float>(), (float) rx.to_number<float>(), (float) ry.to_number<float>(), (float) rz.to_number<float>() });
            }

            if (!scale.is_null())
            {
                object.SetScale((float) scale.to_number<float>());
            }

            break;
        }

        return TypeTemplateError::Success;
    });

    ctx.templates->GetApplier().RegisterExtentionFunction("world-environment", [](
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) -> TypeTemplateError
    {
        auto* worldRegistry = context->GetContext().Extention<WorldRegistry>();

        const auto zone = context->FindValue(operation.at("zone"), TypeTemplateQueryOptions::Full);
        const auto levelId = context->FindValue(operation.at("level-id"), TypeTemplateQueryOptions::Full);
        const auto levelLayer = context->FindValue(operation.at("level-layer"), TypeTemplateQueryOptions::Full);

        auto& world = worldRegistry->GetWorld(context->GetContext(), std::to_string(zone.as_int64()));
        auto& level = world.GetLevel(levelId.as_int64(), levelLayer.as_int64());

        const auto skybox = context->FindValue(operation.at("skybox"), TypeTemplateQueryOptions::Full);

        auto& environment = level.GetEnvironmentInformation();

        if (!skybox.is_null())
        {
            environment.GetSkydomeInformation().SetFilename(skybox.as_string().c_str());
        }

        return TypeTemplateError::Success;
    });

    ctx.templates->GetApplier().RegisterExtentionFunction("add-world-object-property", [](
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) -> TypeTemplateError
    {
        auto* worldRegistry = context->GetContext().Extention<WorldRegistry>();

        const auto zone = context->FindValue(operation.at("zone"), TypeTemplateQueryOptions::Full);
        const auto levelId = context->FindValue(operation.at("level-id"), TypeTemplateQueryOptions::Full);
        const auto levelLayer = context->FindValue(operation.at("level-layer"), TypeTemplateQueryOptions::Full);
        const auto objectId = context->FindValue(operation.at("object-id"), TypeTemplateQueryOptions::Full);

        const auto name = context->FindValue(operation.at("name"), TypeTemplateQueryOptions::Full);
        const auto type = context->FindValue(operation.at("data-type"), TypeTemplateQueryOptions::Full);
        const auto value = context->FindValue(operation.at("value"), TypeTemplateQueryOptions::Full);

        auto& world = worldRegistry->GetWorld(context->GetContext(), std::to_string(zone.as_int64()));
        auto& level = world.GetLevel(levelId.as_int64(), levelLayer.as_int64());

        auto& objects = level.GetObjects();

        if (!objects.HasObject(objectId.as_uint64()))
        {
            return TypeTemplateError("Object not found.");
        }
        
        auto& object = objects.GetObject(objectId.as_uint64());

        std::string str;

        if (value.is_string())
        {
            str = value.as_string().c_str();
        }
        else if (value.is_int64())
        {
            str = std::to_string(value.as_int64());
        }
        else if (value.is_uint64())
        {
            str = std::to_string(value.as_uint64());
        }
        else if (value.is_double())
        {
            str = std::to_string(value.as_double());
        }
        else if (value.is_bool())
        {
            str = value.as_bool() ? "1" : "0";
        }
        else if (value.is_null())
        {
            str = "";
        }
        else
        {
            return TypeTemplateError("Invalid data type.");
        }

        object.GetProperties().GetPropertyMap().emplace(
            string_to_u16string(name.as_string().c_str()), Property(static_cast<ObjectPropertyType>(type.to_number<int64_t>()), str)
        );

        return TypeTemplateError::Success;
    });

    ctx.templates->GetApplier().RegisterExtentionFunction("add-world-spawn-waypoint", [](
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) -> TypeTemplateError
    {
        auto* worldRegistry = context->GetContext().Extention<WorldRegistry>();

        const auto zone = context->FindValue(operation.at("zone"), TypeTemplateQueryOptions::Full);

        const auto path = context->FindValue(operation.at("path"), TypeTemplateQueryOptions::Full);

        const auto x = context->FindValue(operation.at("x"), TypeTemplateQueryOptions::Full);
        const auto y = context->FindValue(operation.at("y"), TypeTemplateQueryOptions::Full);
        const auto z = context->FindValue(operation.at("z"), TypeTemplateQueryOptions::Full);
        const auto rx = context->FindValue(operation.at("rx"), TypeTemplateQueryOptions::Full);
        const auto ry = context->FindValue(operation.at("ry"), TypeTemplateQueryOptions::Full);
        const auto rz = context->FindValue(operation.at("rz"), TypeTemplateQueryOptions::Full);
        const auto rw = context->FindValue(operation.at("rw"), TypeTemplateQueryOptions::Full);

        if (!path.is_string())
        {
            return TypeTemplateError("Path must be a string.");
        }

        if (!x.is_number() || !y.is_number() || !z.is_number())
        {
            return TypeTemplateError("Position must be a number.");
        }

        if (!rx.is_number() || !ry.is_number() || !rz.is_number() || !rw.is_number())
        {
            return TypeTemplateError("Rotation must be a number.");
        }

        vector3 position = { (float) x.to_number<float>(), (float) y.to_number<float>(), (float) z.to_number<float>() };
        vector4 rotation = { (float) rw.to_number<float>(), (float) rx.to_number<float>(), (float) ry.to_number<float>(), (float) rz.to_number<float>() };

        auto& world = worldRegistry->GetWorld(context->GetContext(), std::to_string(zone.as_int64()));

        auto& paths = world.GetZone().GetPathInformation().GetPaths();

        std::string pathStr = path.as_string().c_str();

        for (auto& pathInfo : paths)
        {
            if (u16string_to_string(pathInfo.GetName()) == pathStr)
            {
                if (pathInfo.GetPathType() != PathType::Spawner)
                {
                    return TypeTemplateError("Path already exists, but is not a spawn path.");
                }

                auto& waypoints = pathInfo.GetWaypoints();

                Waypoint waypoint(
                    position,
                    PathType::Spawner
                );

                auto& data = waypoint.GetData<SpawnerWaypointData>();

                data.SetRotation(rotation);

                waypoints.push_back(waypoint);

                return TypeTemplateError::Success;
            }
        }
        
        return TypeTemplateError("Path not found.");
    });

    ctx.templates->GetApplier().RegisterExtentionFunction("add-world-spawn-path", [](
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) -> TypeTemplateError
    {
        auto* worldRegistry = context->GetContext().Extention<WorldRegistry>();

        const auto zone = context->FindValue(operation.at("zone"), TypeTemplateQueryOptions::Full);

        const auto path = context->FindValue(operation.at("path"), TypeTemplateQueryOptions::Full);

        const auto lot = context->FindValue(operation.at("lot"), TypeTemplateQueryOptions::Full);
        const auto to_maintain = context->FindValue(operation.at("to-maintain"), TypeTemplateQueryOptions::Full);
        const auto max_spawn = context->FindValue(operation.at("max-spawn"), TypeTemplateQueryOptions::Full);
        const auto respawn_time = context->FindValue(operation.at("respawn-time"), TypeTemplateQueryOptions::Full);
        const auto activate_on_load = context->FindValue(operation.at("activate-on-load"), TypeTemplateQueryOptions::Full);
        const auto object_id = context->FindValue(operation.at("object-id"), TypeTemplateQueryOptions::Full);

        if (!path.is_string())
        {
            return TypeTemplateError("Path must be a string.");
        }

        if (!lot.is_number() || !to_maintain.is_number() || !max_spawn.is_number() || !respawn_time.is_number() || !activate_on_load.is_bool() || !object_id.is_number())
        {
            return TypeTemplateError("Invalid data type.");
        }

        auto& world = worldRegistry->GetWorld(context->GetContext(), std::to_string(zone.as_int64()));

        auto& paths = world.GetZone().GetPathInformation().GetPaths();

        std::string pathStr = path.as_string().c_str();

        version version = 2;

        for (auto& pathInfo : paths)
        {
            version = pathInfo.GetPathVersion();

            if (u16string_to_string(pathInfo.GetName()) == pathStr)
            {
                return TypeTemplateError("Path already exists.");
            }
        }

        Path pathInfo(
            PathType::Spawner,
            version
        );

        pathInfo.SetName(string_to_u16string(pathStr));

        auto& data = pathInfo.GetData<SpawnerData>();

        data.SetSpawnedLot(lot.to_number<int32_t>());
        data.SetNumToMaintain(to_maintain.to_number<int32_t>());
        data.SetMaxToSpawn(max_spawn.to_number<int32_t>());
        data.SetRespawnTime(respawn_time.to_number<int32_t>());
        data.SetActivateOnLoad(activate_on_load.as_bool());
        data.SetObjectID(object_id.to_number<int64_t>());

        paths.push_back(pathInfo);

        return TypeTemplateError::Success;
    });


    ctx.templates->GetApplier().RegisterExtentionFunction("add-world-camera-path", [](
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) -> TypeTemplateError
    {
        auto* worldRegistry = context->GetContext().Extention<WorldRegistry>();

        const auto zone = context->FindValue(operation.at("zone"), TypeTemplateQueryOptions::Full);

        const auto path = context->FindValue(operation.at("path"), TypeTemplateQueryOptions::Full);

        if (!path.is_string())
        {
            return TypeTemplateError("Path must be a string.");
        }

        auto& world = worldRegistry->GetWorld(context->GetContext(), std::to_string(zone.as_int64()));

        auto& paths = world.GetZone().GetPathInformation().GetPaths();

        std::string pathStr = path.as_string().c_str();

        version version = 2;

        for (auto& pathInfo : paths)
        {
            version = pathInfo.GetPathVersion();

            if (u16string_to_string(pathInfo.GetName()) == pathStr)
            {
                return TypeTemplateError("Path already exists.");
            }
        }

        Path pathInfo(
            PathType::Camera,
            version
        );

        pathInfo.SetName(string_to_u16string(pathStr));

        auto& data = pathInfo.GetData<CameraData>();

        const auto rotatePlayer = context->FindValue(operation.at("rotate-player"), TypeTemplateQueryOptions::Full);
        const auto nextPath = context->FindValue(operation.at("next-path"), TypeTemplateQueryOptions::Full);

        data.SetRotatePlayer(rotatePlayer.as_bool());
        data.SetNextPath(string_to_u16string(nextPath.as_string().c_str()));

        paths.push_back(pathInfo);

        return TypeTemplateError::Success;
    });

    ctx.templates->GetApplier().RegisterExtentionFunction("add-world-camera-waypoint", [](
        const std::shared_ptr<TypeTemplateContext>& context,
        const boost::json::object& operation,
        const boost::json::object& json,
        const TypeTemplate& typeTemplate,
        const std::unordered_map<std::string, TypeTemplateValue>& parameters
    ) -> TypeTemplateError
    {
        auto* worldRegistry = context->GetContext().Extention<WorldRegistry>();

        const auto zone = context->FindValue(operation.at("zone"), TypeTemplateQueryOptions::Full);

        const auto path = context->FindValue(operation.at("path"), TypeTemplateQueryOptions::Full);

        const auto x = context->FindValue(operation.at("x"), TypeTemplateQueryOptions::Full);
        const auto y = context->FindValue(operation.at("y"), TypeTemplateQueryOptions::Full);
        const auto z = context->FindValue(operation.at("z"), TypeTemplateQueryOptions::Full);
        const auto rx = context->FindValue(operation.at("rx"), TypeTemplateQueryOptions::Full);
        const auto ry = context->FindValue(operation.at("ry"), TypeTemplateQueryOptions::Full);
        const auto rz = context->FindValue(operation.at("rz"), TypeTemplateQueryOptions::Full);
        const auto rw = context->FindValue(operation.at("rw"), TypeTemplateQueryOptions::Full);

        const auto time = context->FindValue(operation.at("time"), TypeTemplateQueryOptions::Full);
        const auto fov = context->FindValue(operation.at("fov"), TypeTemplateQueryOptions::Full);
        const auto tension = context->FindValue(operation.at("tension"), TypeTemplateQueryOptions::Full);
        const auto continuity = context->FindValue(operation.at("continuity"), TypeTemplateQueryOptions::Full);
        const auto bias = context->FindValue(operation.at("bias"), TypeTemplateQueryOptions::Full);

        if (!path.is_string())
        {
            return TypeTemplateError("Path must be a string.");
        }

        if (!x.is_number() || !y.is_number() || !z.is_number())
        {
            return TypeTemplateError("Position must be a number.");
        }

        if (!rx.is_number() || !ry.is_number() || !rz.is_number() || !rw.is_number())
        {
            return TypeTemplateError("Rotation must be a number.");
        }

        if (!time.is_number() || !fov.is_number() || !tension.is_number() || !continuity.is_number() || !bias.is_number())
        {
            return TypeTemplateError("Invalid data type.");
        }

        vector3 position = { (float) x.to_number<float>(), (float) y.to_number<float>(), (float) z.to_number<float>() };
        vector4 rotation = { (float) rw.to_number<float>(), (float) rx.to_number<float>(), (float) ry.to_number<float>(), (float) rz.to_number<float>() };

        auto& world = worldRegistry->GetWorld(context->GetContext(), std::to_string(zone.as_int64()));

        auto& paths = world.GetZone().GetPathInformation().GetPaths();

        std::string pathStr = path.as_string().c_str();

        for (auto& pathInfo : paths)
        {
            if (u16string_to_string(pathInfo.GetName()) == pathStr)
            {
                if (pathInfo.GetPathType() != PathType::Camera)
                {
                    return TypeTemplateError("Path already exists, but is not a camera path.");
                }

                auto& waypoints = pathInfo.GetWaypoints();

                Waypoint waypoint(
                    position,
                    PathType::Camera
                );

                auto& data = waypoint.GetData<CameraWaypointData>();

                data.SetRotation(rotation);
                data.SetTime(time.to_number<float>());
                data.SetFov(fov.to_number<float>());
                data.SetTension(tension.to_number<float>());
                data.SetContinuity(continuity.to_number<float>());
                data.SetBias(bias.to_number<float>());

                waypoints.push_back(waypoint);

                return TypeTemplateError::Success;
            }
        }

        return TypeTemplateError("Path not found.");
    });
}

void nejlika::world::WorldRegistry::Save(Context& ctx)
{
    for (auto& [name, world] : m_Worlds)
    {
        // Replace colons with underscores
        std::string filename = name;
        std::replace(filename.begin(), filename.end(), ':', '_');

        world.Save(ctx, filename);
    }
}

void nejlika::world::WorldRegistry::Deinitialize(Context& ctx)
{
    m_Worlds.clear();
}

World& nejlika::world::WorldRegistry::GetWorld(Context& ctx, const nejlika::name& name)
{
    // If the name is an integer, append the core prefix to it
    try
    {
        std::stoll(name);

        return GetWorld(ctx, Lookup::core_prefix + ":" + name);
    }
    catch (const std::exception&)
    {
    
    }

    if (m_Worlds.find(name) == m_Worlds.end())
    {
        World world;
        world.Load(ctx, name);

        m_Worlds[name] = world;
    }

    return m_Worlds[name];
}