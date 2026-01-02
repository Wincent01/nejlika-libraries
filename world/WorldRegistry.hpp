#pragma once

#include <nejlika.hpp>
#include <ContextExtention.hpp>

#include "World.hpp"

namespace nejlika::world
{

class WorldRegistry : public ContextExtention
{
public:
    WorldRegistry() = default;

    WorldRegistry(const WorldRegistry& other);

    ContextExtention* Clone() const override;

    void Initalize(Context& ctx) override;

    void Save(Context& ctx) override;

    void Deinitialize(Context& ctx) override;

    bool HasWorld(const nejlika::name& name) const;

    /**
     * @brief Get a world.
     *
     * @param ctx The context.
     * @param name The name of the world.
     */
    World& GetWorld(Context& ctx, const nejlika::name& name);

    ~WorldRegistry() = default;

private:
    std::unordered_map<nejlika::name, World> m_Worlds;
};

} // namespace nejlika::world
