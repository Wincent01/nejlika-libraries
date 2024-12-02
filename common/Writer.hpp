#pragma once

#include <filesystem>
#include <vector>
#include <string>
#include <cstring>

namespace nejlika {

class Writer {
public:
    Writer();

    template<typename T>
    void Write(const T& value)
    {
        if (m_WriteHead + sizeof(T) > m_Buffer.size())
        {
            Resize(m_Buffer.size() * 2);
        }
        
        ::memcpy(m_Buffer.data() + m_WriteHead, &value, sizeof(T));

        m_WriteHead += sizeof(T);

        if (m_WriteHead > m_BufferSize)
        {
            m_BufferSize = m_WriteHead;
        }
    }

    template<typename TSize>
    void WriteString(const std::string& value)
    {
        Write<TSize>(static_cast<TSize>(value.size()));
        
        for (size_t i = 0; i < value.size(); i++)
        {
            Write<char>(value[i]);
        }
    }

    template<typename TSize>
    void WriteString16(const std::u16string& value)
    {
        Write<TSize>(static_cast<TSize>(value.size()));

        for (size_t i = 0; i < value.size(); i++)
        {
            Write<char16_t>(value[i]);
        }
    }

    void SetWriteHead(size_t writeHead);

    size_t GetWriteHead() const;

    void Skip(size_t size);

    void Resize(size_t size);

    ~Writer();

    void Save(const std::filesystem::path& path) const;

    const std::vector<char>& GetBuffer() const;

    std::vector<char> GetCompressedBuffer();

private:
    size_t m_WriteHead;
    
    std::vector<char> m_Buffer;

    size_t m_BufferSize;
};

}