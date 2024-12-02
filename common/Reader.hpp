#pragma once

#include <filesystem>
#include <vector>

#define READER_EXCEPTIONS

namespace nejlika {

class Reader
{
public:
    Reader(const std::filesystem::path& path);

    template<typename T>
    T& Read()
    {
        #ifdef READER_EXCEPTIONS
        if (m_ReadHead + sizeof(T) > m_Buffer.size())
        {
            throw std::runtime_error("Reading past the end of the buffer");
        }
        #endif

        T& value = *reinterpret_cast<T*>(&m_Buffer.data()[m_ReadHead]);
        m_ReadHead += sizeof(T);
        return value;
    }

    template<typename TSize>
    std::string ReadString()
    {
        TSize size = Read<TSize>();

        #ifdef READER_EXCEPTIONS
        if (m_ReadHead + size * sizeof(char) > m_Buffer.size())
        {
            throw std::runtime_error("Reading past the end of the buffer");
        }
        #endif

        std::string str;

        str.reserve(size);

        for (TSize i = 0; i < size; i++)
        {
            str.push_back(Read<char>());
        }

        return str;
    }

    template<typename TSize>
    std::u16string ReadString16()
    {
        TSize size = Read<TSize>();

        #ifdef READER_EXCEPTIONS
        if (m_ReadHead + size * sizeof(char16_t) > m_Buffer.size())
        {
            throw std::runtime_error("Reading past the end of the buffer");
        }
        #endif
        
        std::u16string str;

        str.reserve(size);

        for (TSize i = 0; i < size; i++)
        {
            str.push_back(Read<char16_t>());
        }

        return str;
    }

    void SetReadHead(size_t readHead);

    size_t GetReadHead() const;

    void Skip(size_t size);

    size_t GetSize() const;

    ~Reader();
    
private:
    size_t m_ReadHead;

    std::filesystem::path m_Path;

    std::vector<char> m_Buffer;
};


}