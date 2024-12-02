#pragma once

#include <Writer.hpp>

namespace nejlika::world
{

class WritePointer
{
public:
    WritePointer() = default;

    /**
     * @brief Construct a new Write Pointer object, saving the writing head which the writer is currently at.
     * 
     * Also writes a 0 (uint32_t) to the writer, which will be used to store the size of the data written.
     * 
     * @param io The writer to save the writing head from.
     */
    WritePointer(nejlika::Writer& io);

    /**
     * @brief Write the address of the writing head to the writer at the saved writing head.
     * 
     * @param io The writer to write the address to.
     */
    void WriteAddress(nejlika::Writer& io);

    /**
     * @brief Write a 0 (uint32_t) to the writer at the saved writing head.
     * 
     * @param io The writer to write the 0 to.
     */
    void WriteZero(nejlika::Writer& io);

    /**
     * @brief Write a uint32_t to the writer at the saved writing head.
     * 
     * @param io The writer to write the uint32_t to.
     * @param value The value to write.
     */
    void Write(nejlika::Writer& io, uint32_t value);

    /**
     * @brief Write the size of the data written to the writer at the saved writing head.
     * 
     * @param io The writer to write the size to.
     */
    void WriteSize(nejlika::Writer& io);

    ~WritePointer();

private:
    uint32_t m_Address;

    bool m_Written;
};

}
