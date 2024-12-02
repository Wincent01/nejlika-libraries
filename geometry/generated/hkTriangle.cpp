#include "hkTriangle.hpp"

using namespace nejlika::geometry;

void hkTriangle::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Triangle.Read(reader, version, user, 0);

    m_WeldingInfo = reader.Read<ushort>();

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_Normal.Read(reader, version, user, 0);
    }

}

void hkTriangle::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    m_Triangle.Write(writer, version, user, 0);

    writer.Write(m_WeldingInfo);

    if (version <= VERSION_NUMBER(20, 0, 0, 5))
    {
        m_Normal.Write(writer, version, user, 0);
    }

}
