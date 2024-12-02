#include "Properties.hpp"

#include <sstream>


nejlika::world::Properties::Properties(nejlika::Reader &io)
{
    const std::u16string& properties = io.ReadString16<uint32_t>();

    std::vector<std::u16string> lines;
    std::vector<char16_t> buffer;

    buffer.reserve(32);
    lines.reserve(32);

    for (char16_t c : properties)
    {
        if (c == u'\n')
        {
            if (!buffer.empty())
            {
                lines.emplace_back(buffer.begin(), buffer.end());
                buffer.clear();
            }
        }
        else
        {
            buffer.push_back(c);
        }
    }

    if (!buffer.empty())
    {
        lines.emplace_back(buffer.begin(), buffer.end());
    }

    for (const std::u16string& line : lines)
    {
        size_t equals = line.find(u'=');
        size_t colon = line.find(u':');

        if (equals == std::u16string::npos || colon == std::u16string::npos)
        {
            throw std::runtime_error("Invalid property line");
        }

        std::u16string name = line.substr(0, equals);
        std::u16string type = line.substr(equals + 1, colon - equals - 1);
        std::u16string value = line.substr(colon + 1);

        auto converter = std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>{};
        ObjectPropertyType propertyType = static_cast<ObjectPropertyType>(std::stoi(converter.to_bytes(type)));
        
        switch (propertyType)
        {
        case ObjectPropertyType::String:
            SetProperty(name, Property(value));
            break;
        case ObjectPropertyType::Blob:
            SetProperty(name, Property(converter.to_bytes(value)));
            break;
        case ObjectPropertyType::Integer:
            SetProperty(name, Property(std::stoi(converter.to_bytes(value))));
            break;
        case ObjectPropertyType::Float:
            SetProperty(name, Property(std::stof(converter.to_bytes(value))));
            break;
        case ObjectPropertyType::Double:
            SetProperty(name, Property(std::stod(converter.to_bytes(value))));
            break;
        case ObjectPropertyType::UnsignedInteger:
            SetProperty(name, Property(static_cast<uint32_t>(std::stoul(converter.to_bytes(value)))));
            break;
        case ObjectPropertyType::Boolean:
            // 'true' or greater than 0 is true, everything else is false
            try
            {
                SetProperty(name, Property(std::stoi(converter.to_bytes(value)) > 0));
            }
            catch (std::invalid_argument&)
            {
                SetProperty(name, Property(value == u"true"));
            }
            break;
        case ObjectPropertyType::Long:
            SetProperty(name, Property(static_cast<int64_t>(std::stoll(converter.to_bytes(value)))));
            break;
        default:
            throw std::runtime_error("Invalid property type");
        }
    }
}

void nejlika::world::Properties::Save(nejlika::Writer &io) const
{
    std::vector<char16_t> buffer;
    buffer.reserve(32 * m_PropertyMap.size());

    for (const auto& [name, property] : m_PropertyMap)
    {
        std::u16string propertyString = property.Save(name);
        buffer.insert(buffer.end(), propertyString.begin(), propertyString.end());
        buffer.push_back(u'\n');
    }

    if (!buffer.empty())
    {
        buffer.pop_back();  // Remove the last newline
    }

    std::u16string properties(buffer.begin(), buffer.end());
    io.WriteString16<uint32_t>(properties);
}

std::unordered_map<std::u16string, nejlika::world::Property> &nejlika::world::Properties::GetPropertyMap()
{
    return m_PropertyMap;
}

const std::unordered_map<std::u16string, nejlika::world::Property> &nejlika::world::Properties::GetPropertyMap() const
{
    return m_PropertyMap;
}

const nejlika::world::Property &nejlika::world::Properties::GetProperty(const std::u16string &name) const
{
    return m_PropertyMap.at(name);
}

void nejlika::world::Properties::SetProperty(const std::u16string &name, const nejlika::world::Property &property)
{
    m_PropertyMap[name] = property;
}

void nejlika::world::Properties::SetProperty(const std::u16string &name, const std::u16string &value)
{
    SetProperty(name, Property(value));
}

void nejlika::world::Properties::SetProperty(const std::u16string &name, const std::string &value)
{
    SetProperty(name, Property(value));
}

void nejlika::world::Properties::SetProperty(const std::u16string &name, const int32_t value)
{
    SetProperty(name, Property(value));
}

void nejlika::world::Properties::SetProperty(const std::u16string &name, const float value)
{
    SetProperty(name, Property(value));
}

void nejlika::world::Properties::SetProperty(const std::u16string &name, const double value)
{
    SetProperty(name, Property(value));
}

void nejlika::world::Properties::SetProperty(const std::u16string &name, const uint32_t value)
{
    SetProperty(name, Property(value));
}

void nejlika::world::Properties::SetProperty(const std::u16string &name, const bool value)
{
    SetProperty(name, Property(value));
}

void nejlika::world::Properties::SetProperty(const std::u16string &name, const int64_t value)
{
    SetProperty(name, Property(value));
}

bool nejlika::world::Properties::HasProperty(const std::u16string &name) const
{
    return m_PropertyMap.find(name) != m_PropertyMap.end();
}

void nejlika::world::Properties::RemoveProperty(const std::u16string &name)
{
    m_PropertyMap.erase(name);
}

void nejlika::world::Properties::ClearProperties()
{
    m_PropertyMap.clear();
}

nejlika::world::Properties::~Properties() = default;