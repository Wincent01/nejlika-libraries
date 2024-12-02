#include <iostream>
#include <sstream>

#include <Configuration.hpp>
#include <Database.hpp>
#include <nejlika.hpp>
#include <Mods.hpp>
#include <Artifacts.hpp>
#include <Lookup.hpp>
#include <AbstractMod.hpp>
#include <chrono>

int main(int argc, char** argv) //try
{
    std::string configuration = "nejlika.json";

    if (argc >= 2)
    {
        configuration = argv[1];
    }

    nejlika::allowUnknownMods = true;

    nejlika::Context ctx;

    ctx.Initalize(nejlika::Configuration(configuration));

    // Run the pre-commands
    for (const auto& command : ctx.configuration->GetPreCommands())
    {
        std::system(command.c_str());
    }

    ctx.database->BeginTransaction();

    const auto restored = ctx.artifacts->Restore(ctx);

    for (const auto& artifact : restored)
    {
        std::cout << "Restored " << artifact << std::endl;
    }

    for (const auto& [k, v] : ctx.lookup->GetMap())
    {
        std::cout << k << " = " << v << std::endl;
    }

    for (auto& pack : ctx.mods->GetModPacks())
    {
        std::cout << pack->GetManifest().GetName() << std::endl;

        for (const auto& mod : pack->GetMods())
        {
            std::cout << "\t[" << mod->GetType() << "] " << mod->GetName() << std::endl;

            ctx.mods->ApplyMod(ctx, mod);
        }

        auto& resources = pack->GetResources();
    }

    ctx.SaveExtentions();

    bool hasUnresolved = false;

    for (const auto& k : ctx.lookup->GetUnresolved())
    {
        std::cout << "Unresolved reference to symbol: \"" << k << "\"" << std::endl;
        hasUnresolved = true;
    }

    for (const auto& k : ctx.mods->GetUnresolved())
    {
        std::cout << "Unresolved reference to mod: \"" << k << "\"" << std::endl;
        hasUnresolved = true;
    }

    if (hasUnresolved)
    {
        std::cout << "Unresolved references found, aborting." << std::endl;
        return 1;
    }

    ctx.database->CommitTransaction();
    ctx.database->Close();

    std::cout << "Finishng up..." << std::endl;

    // Remove cdclient.fdb if it exists
    std::filesystem::remove(ctx.configuration->GetClient() / "res" / "cdclient.fdb");
    
    // Run the sqlite_to_fdb executable.
    std::stringstream command;
    command << ctx.configuration->GetSqliteToFdb() << " " << ctx.database->GetPath() << " " << (ctx.configuration->GetClient() / "res" / "cdclient.fdb");
    std::system(command.str().c_str());

    // Copy the database file to CDServer.sqlite
    std::filesystem::copy(ctx.database->GetPath(), ctx.configuration->GetDatabase().parent_path() / "CDServer.sqlite", std::filesystem::copy_options::overwrite_existing);

    auto postCommands = ctx.configuration->GetPostCommands();

    ctx.Save();

    // Run the post-commands
    for (const auto& command : postCommands)
    {
        pid_t pid = fork();

        if (pid == 0)
        {
            std::system(command.c_str());
            exit(0);
        }
    }

    return 0;
} /*catch (const std::exception& e)
{
    std::cerr << "Error: " << e.what() << std::endl;
    throw;
}*/