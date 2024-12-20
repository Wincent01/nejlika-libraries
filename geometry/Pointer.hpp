#pragma once

#include "Construct.hpp"

#define TEMPLATE_READ(type, member) \
    if constexpr (std::is_class_v<type>) \
    { \
        member.Read(reader, version, user, arg); \
    } \
    else \
    { \
        member = reader.Read<type>(); \
    }

#define TEMPLATE_WRITE(type, member) \
    if constexpr (std::is_class_v<type>) \
    { \
        member.Write(writer, version, user, arg); \
    } \
    else \
    { \
        writer.Write(member); \
    }

namespace nejlika::geometry {

template<typename T>
class Pointer : public Construct
{
private:
    uint32_t m_Index;

public:
    Pointer() : m_Index(0xFFFFFFFF)
    {
    }

    Pointer(uint32_t index) : m_Index(index)
    {
    }

    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
    {
        m_Index = reader.Read<uint32_t>();
    }

    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
    {
        writer.Write(m_Index);
    }

    bool IsNull() const
    {
        return m_Index == 0xFFFFFFFF;
    }

    uint32_t GetIndex() const
    {
        return m_Index;
    }

    void SetIndex(uint32_t index)
    {
        m_Index = index;
    }

    void Reset()
    {
        m_Index = 0xFFFFFFFF;
    }

    T Query(const std::vector<nejlika::geometry::Construct*>& blocks) const
    {
        if (IsNull())
        {
            return nullptr;
        }

        return dynamic_cast<T>(blocks[m_Index]);
    }
};

}