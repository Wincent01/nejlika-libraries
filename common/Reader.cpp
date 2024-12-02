#include "Reader.hpp"
#include <fstream>
#include <iterator>

nejlika::Reader::Reader(const std::filesystem::path& path)
{
    m_Path = path;

    FILE* file = fopen(path.string().c_str(), "rb");

    if (!file)
    {
        throw std::runtime_error("Failed to open file");
    }

    // Read in 4K chunks
    char buffer[4096];
    
    size_t bytesRead = 0;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0)
    {
        m_Buffer.insert(m_Buffer.end(), buffer, buffer + bytesRead);
    }

    fclose(file);

    m_ReadHead = 0;
}

void nejlika::Reader::SetReadHead(size_t readHead)
{
    m_ReadHead = readHead;
}

size_t nejlika::Reader::GetSize() const
{
    return m_Buffer.size();
}

size_t nejlika::Reader::GetReadHead() const
{
    return m_ReadHead;
}

void nejlika::Reader::Skip(size_t size)
{
    m_ReadHead += size;
}

nejlika::Reader::~Reader()
{
}
