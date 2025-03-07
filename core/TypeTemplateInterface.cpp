#include "TypeTemplateInterface.hpp"

using namespace nejlika;

nejlika::TypeTemplateInterface::TypeTemplateInterface(const TypeTemplateInterface& other)
{
    m_Applier = other.m_Applier;
    m_Validator = other.m_Validator;
    for (const auto& collection : other.m_Collection)
    {
        m_Collection.push_back(std::make_unique<TypeTemplateCollection>(*collection));
    }
}

std::shared_ptr<TypeTemplate> TypeTemplateInterface::GetTemplate(const std::string &name) const
{
    if (!HasTemplate(name))
    {
        throw std::runtime_error("TypeTemplateInterface::GetTemplate: Template does not exist.");
    }

    for (const auto& collection : m_Collection)
    {
        if (collection->HasTemplate(name))
        {
            return collection->GetTemplate(name);
        }
    }

    throw std::runtime_error("TypeTemplateInterface::GetTemplate: Template does not exist.");
}

bool nejlika::TypeTemplateInterface::HasTemplate(const name &name) const
{
    for (const auto& collection : m_Collection)
    {
        if (collection->HasTemplate(name))
        {
            return true;
        }
    }

    return false;
}

const TypeTemplateApplier& TypeTemplateInterface::GetApplier() const
{
    return m_Applier;
}

TypeTemplateApplier& TypeTemplateInterface::GetApplier()
{
    return m_Applier;
}

const TypeTemplateValidator& TypeTemplateInterface::GetValidator() const
{
    return m_Validator;
}

TypeTemplateValidator& TypeTemplateInterface::GetValidator()
{
    return m_Validator;
}

void TypeTemplateInterface::AddTemplates(const std::filesystem::path& path)
{
    m_Collection.insert(m_Collection.begin(), std::make_unique<TypeTemplateCollection>());

    m_Collection.front()->LoadTemplates(path);
}

std::unordered_map<name, std::shared_ptr<TypeTemplate>> nejlika::TypeTemplateInterface::GetTemplates() const
{
    std::unordered_map<name, std::shared_ptr<TypeTemplate>> templates;

    for (auto it = m_Collection.rbegin(); it != m_Collection.rend(); ++it)
    {
        for (const auto& [name, typeTemplate] : (*it)->GetTemplates())
        {
            templates[name] = typeTemplate;
        }
    }

    return templates;
}

const std::vector<std::unique_ptr<TypeTemplateCollection>>& nejlika::TypeTemplateInterface::GetCollections() const
{
    return m_Collection;
}
