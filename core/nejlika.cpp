#include "nejlika.hpp"

#include <tinyxml2.h>

#include <fstream>
#include <iostream>
#include <regex>

#include "Configuration.hpp"
#include "Database.hpp"
#include "Lookup.hpp"
#include "Locale.hpp"
#include "Mods.hpp"
#include "Artifacts.hpp"
#include "ContextExtention.hpp"
#include "ArtifactsInterface.hpp"
#include "TypeTemplateInterface.hpp"

using namespace nejlika;

bool nejlika::allowUnknownMods = true;

void nejlika::Context::Initalize(const Configuration& configuration)
{
    this->configuration = std::make_unique<Configuration>(configuration);

    // Copy the database to a temporary location, randomize the name
    char database[17];
    std::generate_n(database, 16, []() -> char {
        return "0123456789abcdef"[std::rand() % 16];
    });
    database[16] = '\0';
    tempDatabase = std::filesystem::temp_directory_path() / (std::string(database) + ".sqlite");
    std::filesystem::copy(configuration.GetDatabase(), tempDatabase, std::filesystem::copy_options::overwrite_existing);
    
    this->database = std::make_unique<Database>(tempDatabase);
    lookup = std::make_unique<Lookup>(configuration.GetLookup());

    if (!std::filesystem::exists(configuration.GetLocale()))
    {
        // Copy from the client
        std::filesystem::copy(configuration.GetClient() / "locale" / "locale.xml", configuration.GetLocale());
    }

    locale = std::make_unique<Locale>(configuration.GetLocale());

    std::cout << "Loaded locales" << std::endl;

    // Load the mods
    mods = std::make_unique<Mods>(*this, configuration.GetModsDirectory());

    std::cout << "Loaded mods" << std::endl;

    // Load the artifacts
    artifacts = std::make_unique<Artifacts>(configuration.GetArtifactsDirectory());

    std::cout << "Loaded artifacts" << std::endl;

    // Loop through all extentions and initalize them
    for (auto extention : extentions)
    {
        extention->Initalize(*this);
    }

    std::cout << "Initalized extentions" << std::endl;
}

std::string replaceNewlinesInXML(const std::string& xml) {
    // Regular expression to find the content between XML element tags
    std::regex elementBodyRegex(R"((>)([^<]*)(<))");

    std::stringstream result;
    auto it = xml.begin();
    auto end = xml.end();
    std::smatch match;

    // Process the XML string and replace newlines within element bodies
    while (std::regex_search(it, end, match, elementBodyRegex)) {
        // Append the part before the match to result
        result << match.prefix().str();

        // Extract the body and replace newlines
        std::string body = match[2].str();
        size_t pos = 0;
        while ((pos = body.find('\n', pos)) != std::string::npos) {
            body.replace(pos, 1, "&#x0A;");
            pos += 6; // Move past the replaced string
        }

        // Reconstruct the element with the replaced body
        result << match[1].str() << body << match[3].str();

        // Move the iterator to the end of the current match
        it = match.suffix().first;
    }

    // Append the rest of the string after the last match
    result << std::string(it, end);

    return result.str();
}

void nejlika::Context::Save(std::filesystem::path path)
{
    lookup->Save();

    // Save the locale to the client
    tinyxml2::XMLDocument document;

    locale->Serialize(document);

    if (path == "") {
        path = configuration->GetClient() / "locale";
    }

    const auto localePath = path / "locale.xml";
    
    // Open file
    std::ofstream file(localePath);

    // Write to file
    tinyxml2::XMLPrinter printer;

    document.Print(&printer);

    file << R"(<?xml version="1.0" encoding="utf-8"?>)" << std::endl;
    std::string xmlStr = printer.CStr();
    file << replaceNewlinesInXML(xmlStr);

    file.close();

    // Copy to client-mirrors
    for (const auto& mirror : configuration->GetClientMirrors())
    {
        const auto mirrorPath = mirror / "locale";
        std::filesystem::create_directories(mirrorPath);
        std::filesystem::copy(localePath, mirrorPath / "locale.xml", std::filesystem::copy_options::overwrite_existing);
    }

    // Save artifacts
    artifacts->Save();
}

void nejlika::Context::SaveExtentions()
{
    // Loop through all extentions and save them
    for (auto extention : extentions)
    {
        extention->Save(*this);
    }
}

void nejlika::Context::AddExtention(ContextExtention *extention)
{
    extentions.push_back(extention);
}

nejlika::Context::Context()
{
    database = nullptr;
    configuration = nullptr;
    lookup = nullptr;
    locale = nullptr;
    mods = nullptr;
    artifacts = nullptr;
    templates = std::make_unique<TypeTemplateInterface>();
    tempDatabase = "";
}

nejlika::Context::~Context()
{
    // Loop through all extentions and deinitialize them
    for (auto extention : extentions)
    {
        extention->Deinitialize(*this);
    }

    database = nullptr;
    configuration = nullptr;
    lookup = nullptr;
    locale = nullptr;
    mods = nullptr;
    artifacts = nullptr;
    templates = nullptr;

    for (auto extention : extentions)
    {
        delete extention;
    }
}

void nejlika::Context::Copy(Context& other) const
{
    char database[17];
    std::generate_n(database, 16, []() -> char {
        return "0123456789abcdef"[std::rand() % 16];
    });
    database[16] = '\0';
    auto tempDatabase = std::filesystem::temp_directory_path() / (std::string(database) + ".sqlite");
    std::filesystem::copy(this->configuration->GetDatabase(), tempDatabase, std::filesystem::copy_options::overwrite_existing);

    other.templates = std::make_unique<TypeTemplateInterface>(*this->templates);
    other.database = std::make_unique<Database>(tempDatabase);
    other.configuration = std::make_unique<Configuration>(*this->configuration);
    other.lookup = std::make_unique<Lookup>(*this->lookup);
    other.locale = std::make_unique<Locale>(*this->locale);
    other.mods = std::make_unique<Mods>(other, *this->mods);
    auto* cast_artifacts = dynamic_cast<Artifacts*>(this->artifacts.get());
    if (cast_artifacts != nullptr)
    {
        other.artifacts = std::make_unique<Artifacts>(*cast_artifacts);
    }
    else
    {
        other.artifacts = nullptr;
    }

    for (auto extention : extentions)
    {
        other.AddExtention(extention->Clone());
    }
}

nejlika::Context::Context(Context &&other) noexcept
{
    database = std::move(other.database);
    configuration = std::move(other.configuration);
    lookup = std::move(other.lookup);
    locale = std::move(other.locale);
    mods = std::move(other.mods);
    artifacts = std::move(other.artifacts);
    templates = std::move(other.templates);
    extentions = std::move(other.extentions);
    tempDatabase = std::move(other.tempDatabase);
}
