#include "string.hpp"

using namespace nejlika::geometry;

void string::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_String.Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        m_Index = reader.Read<StringIndex>();
    }

}

void string::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_String.Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(20, 1, 0, 3))
    {
        writer.Write(m_Index);
    }

}
