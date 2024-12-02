#pragma once

#include "nejlika.hpp"

#include <unordered_map>

namespace nejlika
{

class TypeTemplate;

/**
 * @brief A collection of type templates.
 */
class TypeTemplateCollection
{
public:
    /**
     * @brief Get a type template by name.
     * 
     * @param name The name of the type template to get.
     * @return The type template.
     * @throw If the type template does not exist.
     */
    std::shared_ptr<TypeTemplate> GetTemplate(const std::string& name) const;

    /**
     * @brief Check if a type template exists by name.
     * 
     * @param name The name of the type template to check.
     * @return True if the type template exists, false otherwise.
     */
    bool HasTemplate(const name& name) const;

    /**
     * @brief Loads all type templates from a directory.
     * 
     * @param path The path to the directory to load the type templates from.
     * 
     * @note Will overwrite any existing type templates.
     */
    void LoadTemplates(const std::filesystem::path& path);

    /**
     * @brief Get all type templates.
     * 
     * @return All type templates.
     */
    const std::unordered_map<name, std::shared_ptr<TypeTemplate>>& GetTemplates();

    /**
     * @brief Get the path of the collection.
     * 
     * @return The path of the collection, may be empty.
     */
    const std::filesystem::path& GetLoadedPath() const;

private:
    std::filesystem::path m_Path;

    std::unordered_map<name, std::shared_ptr<TypeTemplate>> m_Templates;
};

}