#include "TypeTemplateCollection.hpp"

#include "TypeTemplate.hpp"

#include <fstream>
#include <boost/json.hpp>

using namespace nejlika;

std::shared_ptr<TypeTemplate> TypeTemplateCollection::GetTemplate(const std::string &name) const
{
    if (!HasTemplate(name))
    {
        throw std::runtime_error("TypeTemplate::GetTemplate: Template does not exist.");
    }

    return m_Templates.at(name);
}

bool TypeTemplateCollection::HasTemplate(const name& name) const
{
    return m_Templates.find(name) != m_Templates.end();
}

void nejlika::TypeTemplateCollection::LoadTemplates(const std::filesystem::path &path)
{   
    m_Path = path;

    for (const auto& entry : std::filesystem::directory_iterator(path))
    {
        if (!entry.is_regular_file())
        {
            continue;
        }

        if (entry.path().extension() != ".json")
        {
            continue;
        }

        const auto& file = entry.path();

        std::ifstream stream(file);

        if (!stream.is_open())
        {
            continue;
        }

        boost::json::value value = boost::json::parse(stream);

        if (!value.is_object())
        {
            continue;
        }

        const auto& object = value.as_object();

        if (!object.contains("name"))
        {
            continue;
        }

        const auto& name = object.at("name");

        if (!name.is_string())
        {
            continue;
        }

        const auto& templateName = name.as_string().c_str();

        auto templateObject = std::make_shared<TypeTemplate>();
        templateObject->Deserialize(object);

        m_Templates.emplace(templateName, templateObject);
    }
}

const std::unordered_map<name, std::shared_ptr<TypeTemplate>> &nejlika::TypeTemplateCollection::GetTemplates()
{
    return m_Templates;
}

const std::filesystem::path &nejlika::TypeTemplateCollection::GetLoadedPath() const
{
    return m_Path;
}
