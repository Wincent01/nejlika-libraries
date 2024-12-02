#include "Property.hpp"
#include <codecvt>

nejlika::world::Property::Property(const std::u16string &value)
{
    m_Type = ObjectPropertyType::String;
    m_Value = value;
}

nejlika::world::Property::Property(const std::string &value)
{
    m_Type = ObjectPropertyType::Blob;
    m_Value = string_to_u16string(value);
}

nejlika::world::Property::Property(const int32_t value)
{
    m_Type = ObjectPropertyType::Integer;
    m_Value = value;
}

nejlika::world::Property::Property(const float value)
{
    m_Type = ObjectPropertyType::Float;
    m_Value = value;
}

nejlika::world::Property::Property(const double value)
{
    m_Type = ObjectPropertyType::Double;
    m_Value = value;
}

nejlika::world::Property::Property(const uint32_t value)
{
    m_Type = ObjectPropertyType::UnsignedInteger;
    m_Value = value;
}

nejlika::world::Property::Property(const bool value)
{
    m_Type = ObjectPropertyType::Boolean;
    m_Value = value;
}

nejlika::world::Property::Property(const int64_t value)
{
    m_Type = ObjectPropertyType::Long;
    m_Value = value;
}

nejlika::world::Property::Property(ObjectPropertyType type, const ValueType &value)
{
    m_Type = type;
    m_Value = value;
}

std::u16string nejlika::world::Property::Save(const std::u16string &name) const
{
    std::u16string buffer;

    buffer.reserve(32);

    buffer.insert(buffer.end(), name.begin(), name.end());
    buffer.push_back(u'=');
    auto type = string_to_u16string(std::to_string(static_cast<int>(m_Type)));
    buffer.insert(buffer.end(), type.begin(), type.end());
    buffer.push_back(u':');
    
    auto value = std::visit([](auto&& arg) -> std::u16string {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, std::u16string>) {
            return arg;
        } else if constexpr (std::is_same_v<T, int32_t>) {
            return string_to_u16string(std::to_string(arg));
        } else if constexpr (std::is_same_v<T, float>) {
            return string_to_u16string(std::to_string(arg));
        } else if constexpr (std::is_same_v<T, double>) {
            return string_to_u16string(std::to_string(arg));
        } else if constexpr (std::is_same_v<T, uint32_t>) {
            return string_to_u16string(std::to_string(arg));
        } else if constexpr (std::is_same_v<T, bool>) {
            return arg ? u"1" : u"0";
        } else if constexpr (std::is_same_v<T, int64_t>) {
            return string_to_u16string(std::to_string(arg));
        } else if constexpr (std::is_same_v<T, std::string>) {
            return string_to_u16string(arg);
        } else {
            static_assert(false, "non-exhaustive visitor!");
        }
    }, m_Value);

    buffer.insert(buffer.end(), value.begin(), value.end());
    
    return buffer;
}

ObjectPropertyType nejlika::world::Property::GetType() const
{
    return m_Type;
}

const nejlika::world::Property::ValueType& nejlika::world::Property::GetValue() const
{
    return m_Value;
}

const std::u16string &nejlika::world::Property::GetString() const
{
    return std::get<std::u16string>(m_Value);
}

const int32_t nejlika::world::Property::GetInteger() const
{
    return std::get<int32_t>(m_Value);
}

const float nejlika::world::Property::GetFloat() const
{
    return std::get<float>(m_Value);
}

const double nejlika::world::Property::GetDouble() const
{
    return std::get<double>(m_Value);
}

const uint32_t nejlika::world::Property::GetUnsignedInteger() const
{
    return std::get<uint32_t>(m_Value);
}

const bool nejlika::world::Property::GetBoolean() const
{
    return std::get<bool>(m_Value);
}

const int64_t nejlika::world::Property::GetLong() const
{
    return std::get<int64_t>(m_Value);
}

const std::string &nejlika::world::Property::GetBlob() const
{
    return std::get<std::string>(m_Value);
}

const std::string nejlika::world::Property::GetValueAsString() const
{
    return std::visit([](auto&& arg) -> std::string {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, std::u16string>) {
            return u16string_to_string(arg);
        } else if constexpr (std::is_same_v<T, int32_t>) {
            return std::to_string(arg);
        } else if constexpr (std::is_same_v<T, float>) {
            return std::to_string(arg);
        } else if constexpr (std::is_same_v<T, double>) {
            return std::to_string(arg);
        } else if constexpr (std::is_same_v<T, uint32_t>) {
            return std::to_string(arg);
        } else if constexpr (std::is_same_v<T, bool>) {
            return arg ? "1" : "0";
        } else if constexpr (std::is_same_v<T, int64_t>) {
            return std::to_string(arg);
        } else if constexpr (std::is_same_v<T, std::string>) {
            return arg;
        } else {
            static_assert(false, "non-exhaustive visitor!");
        }
    }, m_Value);
}

nejlika::world::Property::~Property() = default;