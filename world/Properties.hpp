#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"
#include "WritePointer.hpp"
#include "Property.hpp"

namespace nejlika::world
{

class Properties
{
public:
    Properties() = default;

    Properties(nejlika::Reader& io);

    void Save(nejlika::Writer& io) const;

    std::unordered_map<std::u16string, Property>& GetPropertyMap();

    const std::unordered_map<std::u16string, Property>& GetPropertyMap() const;

    const Property& GetProperty(const std::u16string& name) const;

    void SetProperty(const std::u16string& name, const Property& property);

    void SetProperty(const std::u16string& name, const std::u16string& value);

    void SetProperty(const std::u16string& name, const std::string& value);

    void SetProperty(const std::u16string& name, const int32_t value);

    void SetProperty(const std::u16string& name, const float value);

    void SetProperty(const std::u16string& name, const double value);

    void SetProperty(const std::u16string& name, const uint32_t value);

    void SetProperty(const std::u16string& name, const bool value);

    void SetProperty(const std::u16string& name, const int64_t value);

    bool HasProperty(const std::u16string& name) const;

    void RemoveProperty(const std::u16string& name);

    void ClearProperties();

    ~Properties();

private:
    std::unordered_map<std::u16string, Property> m_PropertyMap;
};

}