#pragma once

#include <string>
#include <vector>

#include <Reader.hpp>
#include <Writer.hpp>

#include "numerics.hpp"
#include "WorldSerialize.hpp"
#include "WritePointer.hpp"
#include <variant>

namespace nejlika::world
{

class Property
{
public:
    using ValueType = std::variant<std::u16string, int32_t, float, double, uint32_t, bool, int64_t, std::string>;

    Property() = default;

    Property(const std::u16string& value);

    Property(const std::string& value);

    Property(const int32_t value);

    Property(const float value);

    Property(const double value);

    Property(const uint32_t value);

    Property(const bool value);

    Property(const int64_t value);

    Property(ObjectPropertyType type, const ValueType& value);

    Property(const Property& other) = default;

    std::u16string Save(const std::u16string& name) const;

    ObjectPropertyType GetType() const;

    const ValueType& GetValue() const;

    const std::u16string& GetString() const;

    const int32_t GetInteger() const;

    const float GetFloat() const;

    const double GetDouble() const;

    const uint32_t GetUnsignedInteger() const;

    const bool GetBoolean() const;

    const int64_t GetLong() const;

    const std::string& GetBlob() const;

    const std::string GetValueAsString() const;

    ~Property();

private:
    ObjectPropertyType m_Type;

    ValueType m_Value;
};

}