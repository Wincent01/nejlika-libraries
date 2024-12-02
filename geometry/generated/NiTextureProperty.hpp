#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiImage.hpp"
#include "NiProperty.hpp"
namespace nejlika::geometry {


class NiTextureProperty : public NiProperty
{
protected:
    /**
     * Property flags.
     */
    std::vector<uint> m_UnknownInts1;
    /**
     * Property flags.
     */
    Flags m_Flags;
    /**
     * Link to the texture image.
     */
    Pointer<class NiImage*> m_Image;
    /**
     * Unknown.  0?
     */
    std::vector<uint> m_UnknownInts2;

public:
    const std::vector<uint>& GetUnknownInts1() const { return m_UnknownInts1; }
    std::vector<uint>& GetUnknownInts1() { return m_UnknownInts1; }
    void SetUnknownInts1(const std::vector<uint>& value) { m_UnknownInts1 = value; }

    const Flags& GetFlags() const { return m_Flags; }
    Flags& GetFlags() { return m_Flags; }
    void SetFlags(const Flags& value) { m_Flags = value; }

    const Pointer<class NiImage*>& GetImage() const { return m_Image; }
    Pointer<class NiImage*>& GetImage() { return m_Image; }
    void SetImage(const Pointer<class NiImage*>& value) { m_Image = value; }

    const std::vector<uint>& GetUnknownInts2() const { return m_UnknownInts2; }
    std::vector<uint>& GetUnknownInts2() { return m_UnknownInts2; }
    void SetUnknownInts2(const std::vector<uint>& value) { m_UnknownInts2 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
