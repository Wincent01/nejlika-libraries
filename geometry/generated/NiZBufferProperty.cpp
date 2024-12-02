#include "NiZBufferProperty.hpp"

using namespace nejlika::geometry;

void NiZBufferProperty::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiProperty::Read(reader, version, user, arg);

    m_Flags = reader.Read<Flags>();

    if (version >= VERSION_NUMBER(4, 1, 0, 12) && version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_Function = reader.Read<ZCompareMode>();
    }
    else
    {
        m_Function = static_cast<ZCompareMode>(ZCOMP_LESS_EQUAL);
    }

}

void NiZBufferProperty::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiProperty::Write(writer, version, user, arg);

    writer.Write(m_Flags);

    if (version >= VERSION_NUMBER(4, 1, 0, 12) && version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        writer.Write(m_Function);
    }
    else
    {
        //writer.Write(ZCOMP_LESS_EQUAL);
    }

}
