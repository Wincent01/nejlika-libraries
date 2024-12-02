#include "NiExtraData.hpp"

using namespace nejlika::geometry;

void NiExtraData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    if (version >= VERSION_NUMBER(10, 0, 1, 0))
    {
        m_Name.Read(reader, version, user, 0);
    }

    if (version <= VERSION_NUMBER(4, 2, 2, 0))
    {
        m_NextExtraData.Read(reader, version, user, 0);
    }

}

void NiExtraData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    if (version >= VERSION_NUMBER(10, 0, 1, 0))
    {
        m_Name.Write(writer, version, user, 0);
    }

    if (version <= VERSION_NUMBER(4, 2, 2, 0))
    {
        m_NextExtraData.Write(writer, version, user, 0);
    }

}
