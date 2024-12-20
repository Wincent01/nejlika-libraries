#include "Writer.hpp"

#include <fstream>
#include <ostream>
#include <cstdlib>
#include <cstring>

#include <zlib.h>

nejlika::Writer::Writer()
{
    // Start with a 1K buffer
    m_Buffer = std::vector<char>(1024);

    m_WriteHead = 0;

    m_BufferSize = 0;
}

void nejlika::Writer::SetWriteHead(size_t writeHead)
{
    m_WriteHead = writeHead;

    if (m_WriteHead > m_BufferSize)
    {
        m_BufferSize = m_WriteHead;
    }
}

size_t nejlika::Writer::GetWriteHead() const
{
    return m_WriteHead;
}

void nejlika::Writer::Skip(size_t size)
{
    if (m_WriteHead + size > m_Buffer.size())
    {
        Resize(m_Buffer.size() * 2);
    }

    m_WriteHead += size;

    if (m_WriteHead > m_BufferSize)
    {
        m_BufferSize = m_WriteHead;
    }
}

void nejlika::Writer::Resize(size_t size)
{
    m_Buffer.resize(size);
}

nejlika::Writer::~Writer()
{
}

void nejlika::Writer::Save(const std::filesystem::path &path) const
{
    // Delete if it exists
    std::remove(path.string().c_str());

    FILE* file = fopen(path.string().c_str(), "wb");

    if (file == nullptr)
    {
        throw std::runtime_error("Failed to open file for writing");
    }

    fwrite(m_Buffer.data(), 1, m_BufferSize, file);

    fclose(file);
}

const std::vector<char>& nejlika::Writer::GetBuffer() const
{
    return m_Buffer;
}
