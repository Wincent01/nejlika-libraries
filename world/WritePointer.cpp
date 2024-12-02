#include "WritePointer.hpp"

nejlika::world::WritePointer::WritePointer(nejlika::Writer &io)
{
    m_Address = io.GetWriteHead();

    io.Write<uint32_t>(0);

    m_Written = false;
}

void nejlika::world::WritePointer::WriteAddress(nejlika::Writer &io)
{
    if (m_Written)
    {
        throw std::runtime_error("WritePointer::Write() called twice");
    }

    uint32_t current = io.GetWriteHead();

    io.SetWriteHead(m_Address);

    io.Write<uint32_t>(current);

    io.SetWriteHead(current);

    m_Written = true;
}

void nejlika::world::WritePointer::WriteZero(nejlika::Writer &io)
{
    if (m_Written)
    {
        throw std::runtime_error("WritePointer::Write() called twice");
    }

    uint32_t current = io.GetWriteHead();

    io.SetWriteHead(m_Address);

    io.Write<uint32_t>(0);

    io.SetWriteHead(current);

    m_Written = true;
}

void nejlika::world::WritePointer::Write(nejlika::Writer &io, uint32_t value)
{
    if (m_Written)
    {
        throw std::runtime_error("WritePointer::Write() called twice");
    }

    uint32_t current = io.GetWriteHead();

    io.SetWriteHead(m_Address);

    io.Write<uint32_t>(value);

    io.SetWriteHead(current);

    m_Written = true;
}

void nejlika::world::WritePointer::WriteSize(nejlika::Writer &io)
{
    if (m_Written)
    {
        throw std::runtime_error("WritePointer::Write() called twice");
    }
    
    uint32_t current = io.GetWriteHead();

    io.SetWriteHead(m_Address);

    io.Write<uint32_t>(current - m_Address - sizeof(uint32_t));

    io.SetWriteHead(current);
}

nejlika::world::WritePointer::~WritePointer()
{
}
