#pragma once

#include "nejlika.hpp"

#include "TypeTemplateApplier.hpp"
#include "TypeTemplateValidator.hpp"
#include "TypeTemplateCollection.hpp"

namespace nejlika
{

class TypeTemplate;

/**
 * @brief A way to retrieve type templates, the validator and the applier.
 */
class TypeTemplateInterface
{
public:
    /**
     * @brief Default constructor.
     */
    TypeTemplateInterface() = default;

    /**
     * @brief Copy constructor.
     */
    TypeTemplateInterface(const TypeTemplateInterface&);

    /**
     * @brief Get a type template by name.
     * 
     * @param name The name of the type template to get.
     * @return The type template.
     * @throw If the type template does not exist.
     */
    std::shared_ptr<TypeTemplate> GetTemplate(const std::string &name) const;

    /**
     * @brief Check if a type template exists by name.
     * 
     * @param name The name of the type template to check.
     * @return True if the type template exists, false otherwise.
     */
    bool HasTemplate(const name& name) const;

    /**
     * @brief Get the type template applier.
     * 
     * @return The type template applier.
     */
    const TypeTemplateApplier& GetApplier() const;

    /**
     * @brief Get the type template applier.
     * 
     * @return The type template applier.
     */
    TypeTemplateApplier& GetApplier();

    /**
     * @brief Get the type template validator.
     * 
     * @return The type template validator.
     */
    const TypeTemplateValidator& GetValidator() const;

    /**
     * @brief Get the type template validator.
     * 
     * @return The type template validator.
     */
    TypeTemplateValidator& GetValidator();

    /**
     * @brief Add a collection of type templates from a directory.
     * 
     * @param path The path to the directory to load the type templates from.
     */
    void AddTemplates(const std::filesystem::path &path);

    /**
     * @brief Get all type templates.
     * 
     * @return All type templates.
     * @note If multiple collections have the same template name, the last one added will be returned.
     */
    std::unordered_map<name, std::shared_ptr<TypeTemplate>> GetTemplates() const;

    /**
     * @brief Get all the collections of type templates.
     * 
     * @return All the collections of type templates.
     */
    const std::vector<std::unique_ptr<TypeTemplateCollection>>& GetCollections() const;

private:
    TypeTemplateApplier m_Applier;
    TypeTemplateValidator m_Validator;

    std::vector<std::unique_ptr<TypeTemplateCollection>> m_Collection;
};

}