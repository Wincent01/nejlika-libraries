#pragma once

#include <filesystem>
#include <unordered_map>
#include <unordered_set>

#include "hashing.hpp"

namespace nejlika
{

class Context;

/**
 * @brief A way to access resource files.
 * 
 * Each mod pack has its own resource directory. Files are accessed by their relative path to the resource directory.
 * 
 * @note Has static methods for working with the read-only core resource directory.
 */
class ModResources
{
public:
    /**
     * @brief Constructs a new ModResources object.
     */
    ModResources();

    /**
     * @brief Constructs a new ModResources object.
     * 
     * @param path The path to the mod pack directory.
     */
    ModResources(const std::filesystem::path& path);

    /**
     * @brief Gets the path to the resource directory.
     * 
     * @return The path to the resource directory.
     */
    const std::filesystem::path& GetPath() const;

    /**
     * @brief Sets the path to the resource directory.
     * 
     * @param path The path to the resource directory.
     * 
     * @throw If the resource directory could not be read.
     * 
     * @note Should rarely be used by itself, see ModPack::Rename.
     */
    void SetPath(const std::filesystem::path& path);

    /**
     * @brief Reload the resources in the resource directory.
     * 
     * @throw If the resource directory could not be read.
     */
    void Reload();

    /**
     * @brief Gets the path to the specified resource file (absolute path).
     * 
     * @param path The path to the resource file.
     * @return The path to the specified resource file.
     * @throw If the resource file is not found.
     */
    std::filesystem::path GetResourcePath(const std::filesystem::path& path) const;

    /**
     * @brief Add a resource file at a specified path. This does not involve writing to the file system.
     * 
     * @param path The path to the resource file.
     * @return The path to the resource file.
     * @throw If the resource file already exists.
     */
    std::filesystem::path AddResource(const std::filesystem::path& path);

    /**
     * @brief Remove a resource file at a specified path.
     * 
     * @param path The path to the resource file.
     * @param deleteFile If true, the file will be deleted from the file system.
     * @throw If the file could not be deleted.
     */
    void RemoveResource(const std::filesystem::path& path, bool deleteFile = true);

    /**
     * @brief Create a subdirectory in the resource directory.
     * 
     * @param path The path to the subdirectory.
     * @throw If the subdirectory could not be created.
     * 
     * @note Intermediate directories will be created if they do not exist.
     */
    void CreateSubdirectory(const std::filesystem::path& path);

    /**
     * @brief Check if there are any resources is a subdirectory (or root) of the resource directory.
     * 
     * @param subdirectory The subdirectory to search in.
     */
    bool HasResourcesInSubdirectory(const std::filesystem::path& subdirectory) const;

    /**
     * @brief Delete a subdirectory in the resource directory.
     * 
     * @param path The path to the subdirectory.
     * @throw If the subdirectory could not be deleted.
     */
    void DeleteSubdirectory(const std::filesystem::path& path);

    /**
     * @brief Check if a resource file exists.
     * 
     * @param path The path to the resource file.
     * @return True if the resource file exists, false otherwise.
     */
    bool HasResource(const std::filesystem::path& path) const;

    /**
     * @brief Get a set of all resource files which are either new or have been modified.
     * 
     * @return A set of all resource files which are either new or have been modified.
     */
    const std::unordered_set<std::filesystem::path, nejlika::filepath_hash>& GetResources() const;

    /**
     * @brief Get all resources which are in a subdirectory (or root) of the resource directory. 
     * 
     * @param subdirectory The subdirectory to search in.
     * @param includeSubdirectories If true, the result will include paths to subdirectories.
     * @return All resources which are in a subdirectory (or root) of the resource directory.
     * 
     * @note Non-recursive.
     */
    std::unordered_set<std::filesystem::path, nejlika::filepath_hash> GetResourcesInSubdirectory(
        const std::filesystem::path& subdirectory,
        bool includeSubdirectories = false,
        bool recursive = false
    ) const;

    /**
     * @brief Get the directory name of the resource directory.
     * 
     * @return The directory name of the resource directory.
     */
    const std::filesystem::path& GetDirectoryName() const;

    /**
     * @brief Get a resource path which includes the resource directory name if it does not already.
     * 
     * @param path The path to the resource file.
     * @return The resource path which includes the resource directory name if it does not already.
     */
    std::filesystem::path GetResourcePathWithDirectoryName(const std::filesystem::path& path) const;

    /**
     * @brief Get a resource path without the resource directory name if it includes it.
     * 
     * @param path The path to the resource file.
     * @return The resource path without the resource directory name if it includes it.
     */
    std::filesystem::path GetResourcePathWithoutDirectoryName(const std::filesystem::path& path) const;

    /**
     * @brief Get all resources which are in a subdirectory (or root) of the resource directory, for the standard resource directory.
     * 
     * @param ctx The context.
     * @param subdirectory The subdirectory to search in.
     * @param includeSubdirectories If true, the result will include paths to subdirectories.
     * @return All resources which are in a subdirectory (or root) of the resource directory, for the standard resource directory.
     * 
     * @note Non-recursive.
     */
    static std::unordered_set<std::filesystem::path, nejlika::filepath_hash> GetResourcesInSubdirectoryCore(
        nejlika::Context& ctx,
        const std::filesystem::path& subdirectory,
        bool includeSubdirectories = false,
        bool recursive = false
    );

    /**
     * @brief Check if a resource is a core resource.
     * 
     * @param path The path to the resource file.
     * @param withoutPrefix The path without the prefix (out parameter).
     * @return True if the resource is a core resource, false otherwise.
     */
    static bool IsCoreResource(const std::filesystem::path& path, std::filesystem::path& withoutPrefix);

    /**
     * @brief Check if a resource is a core resource.
     * 
     * @param path The path to the resource file.
     * @return True if the resource is a core resource, false otherwise.
     */
    static bool IsCoreResource(const std::filesystem::path& path);

    /**
     * @brief Get the path to a core resource.
     * 
     * @param ctx The context.
     * @param path The path to the resource file.
     * @param subdirectory The subdirectory to search in.
     * @return The path to the core resource.
     * 
     * @note Will normalize the path, all lowercase, change all slashes to forward slashes, and search for the file in a case-insensitive manner.
     */
    static std::filesystem::path GetCoreResourcePath(nejlika::Context& ctx, const std::filesystem::path& path, const std::filesystem::path& subdirectory);

    /**
     * @brief Find the resources for a resource path. A resource path is formatted as "modpackname:resourcepath". If no modpack name is specified, take a supplied default.
     * 
     * @param ctx The context.
     * @param path The resource path.
     * @param defaultModPack The default mod pack.
     * @param withoutPrefix The resource path without the prefix (out parameter).
     * 
     * @return The resources for a resource path.
     */
    static const ModResources& FindResources(nejlika::Context& ctx, const std::filesystem::path& path, const ModResources& defaultModPack, std::filesystem::path& withoutPrefix);
    
    /**
     * @brief Find the resources for a resource path. A resource path is formatted as "modpackname:resourcepath".
     * 
     * @param ctx The context.
     * @param path The resource path.
     * @param withoutPrefix The resource path without the prefix (out parameter).
     * 
     * @return The resources for a resource path.
     * @throw If the mod pack does not exist.
     */
    static const ModResources& FindResources(nejlika::Context& ctx, const std::filesystem::path& path, std::filesystem::path& withoutPrefix);
    
    /**
     * @brief Find the resource for a resource path. A resource path is formatted as "modpackname:resourcepath". If no modpack name is specified, the core resource directory is used.
     * 
     * @param ctx The context.
     * @param path The resource path.
     * 
     * @return The resources for a resource path.
     */
    static std::filesystem::path FindResource(nejlika::Context& ctx, const std::filesystem::path& path);

    /**
     * Finds a case-insensitive match for a given path within a root directory.
     *
     * @param root The root directory to search within.
     * @param path The path to find within the root directory.
     * @return The case-insensitive match for the given path, if found. Otherwise, an empty path is returned.
     */
    static std::filesystem::path FindCaseInsensitive(const std::filesystem::path &root, const std::filesystem::path &path);

private:
    std::filesystem::path m_Path;

    std::filesystem::path m_DirectoryName;

    std::unordered_set<std::filesystem::path, nejlika::filepath_hash> m_Resources;
};

}