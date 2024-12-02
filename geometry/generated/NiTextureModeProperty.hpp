#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiProperty.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Unknown
 *         
 */
class NiTextureModeProperty : public NiProperty
{
protected:
    std::vector<uint> m_UnknownInts;
    /**
     * Unknown. Either 210 or 194.
     */
    short m_UnknownShort;
    /**
     * 0?
     */
    short m_PS2L;
    /**
     * -75?
     */
    short m_PS2K;

public:
    const std::vector<uint>& GetUnknownInts() const { return m_UnknownInts; }
    std::vector<uint>& GetUnknownInts() { return m_UnknownInts; }
    void SetUnknownInts(const std::vector<uint>& value) { m_UnknownInts = value; }

    const short& GetUnknownShort() const { return m_UnknownShort; }
    short& GetUnknownShort() { return m_UnknownShort; }
    void SetUnknownShort(const short& value) { m_UnknownShort = value; }

    const short& GetPS2L() const { return m_PS2L; }
    short& GetPS2L() { return m_PS2L; }
    void SetPS2L(const short& value) { m_PS2L = value; }

    const short& GetPS2K() const { return m_PS2K; }
    short& GetPS2K() { return m_PS2K; }
    void SetPS2K(const short& value) { m_PS2K = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
