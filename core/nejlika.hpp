#pragma once

#include <string>
#include <filesystem>
#include <vector>
#include <stdexcept>

namespace nejlika {
    
typedef std::string name;
typedef int32_t id;

class ContextExtention;
class Database;
class Configuration;
class Lookup;
class Locale;
class Mods;
class ArtifactsInterface;
class TypeTemplateInterface;

extern bool allowUnknownMods;

/**
 * @brief The context holds the state of the application.
 */
class Context {
public:
    /**
     * @brief The SQLite database.
     */
    std::unique_ptr<Database> database;

    /**
     * @brief The configuration.
     */
    std::unique_ptr<Configuration> configuration;

    /**
     * @brief The lookup for identifiers.
     */
    std::unique_ptr<Lookup> lookup;

    /**
     * @brief The locale for localization.
     */
    std::unique_ptr<Locale> locale;

    /**
     * @brief The mod manager.
     */
    std::unique_ptr<Mods> mods;

    /**
     * @brief The artifacts manager.
     */
    std::unique_ptr<ArtifactsInterface> artifacts;

    /**
     * @brief The type template manager.
     */
    std::unique_ptr<TypeTemplateInterface> templates;

    /**
     * @brief Construct a new Context object.
     */
    Context();

    /**
     * @brief Copy constructor.
     * 
     * @deprecated Due to paranoia about accidentally copying the context, please use Copy instead.
     */
    Context(const Context& other) = delete;

    /**
     * @brief Move constructor.
     */
    Context(Context&& other) noexcept;

    /**
     * @brief Copy the context.
     * 
     * @param other The context to copy.
     */
    void Copy(Context& other) const;
    
    /**
     * @brief Initalize the context.
     * 
     * @param configuration The configuration to use.
     */
    void Initalize(const Configuration& configuration);

    /**
     * @brief Save the context to a file.
     * 
     * @param path The path to save the context to.
     */
    void Save(std::filesystem::path path = "");

    /**
     * @brief Notify all extentions that they should save any runtime data.
     */
    void SaveExtentions();

    /**
     * @brief Get an extension by type.
     * 
     * @tparam T The type of the extension, must be a subclass of ContextExtention.
     */
    template <typename T>
    T* Extention() {
        // Check T at compile time
        if (!std::is_base_of<ContextExtention, T>::value) {
            throw std::runtime_error("T must be a subclass of ContextExtention.");
        }
        
        for (auto extention : extentions) {
            if (auto casted = dynamic_cast<T*>(extention)) {
                return casted;
            }
        }

        throw std::runtime_error("Extention not found.");
    }

    /**
     * @brief Add an extension to the context.
     * 
     * @tparam T The type of the extension, must be a subclass of ContextExtention.
     */
    template <typename T>
    void AddExtention() {
        // Check T at compile time
        if (!std::is_base_of<ContextExtention, T>::value) {
            throw std::runtime_error("T must be a subclass of ContextExtention.");
        }

        extentions.push_back(new T());
    }

    /**
     * @brief Add an extension to the context.
     * 
     * @param extention The extension to add.
     */
    void AddExtention(ContextExtention* extention);

    ~Context();

private:
    std::filesystem::path tempDatabase;
    
    std::vector<ContextExtention*> extentions;
};
} // namespace nejlika
