#include "NiPhysXBodyDesc.hpp"

using namespace nejlika::geometry;

void NiPhysXBodyDesc::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    if (version >= VERSION_NUMBER(20, 3, 0, 6))
    {
        m_UnknownBytes.resize(136);
        for (uint32_t i = 0; i < m_UnknownBytes.size(); i++)
        {
            m_UnknownBytes[i] = reader.Read<byte>();
        }
    }

}

void NiPhysXBodyDesc::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    if (version >= VERSION_NUMBER(20, 3, 0, 6))
    {
        for (uint32_t i = 0; i < m_UnknownBytes.size(); i++)
        {
            writer.Write(m_UnknownBytes[i]);
        }
    }

}
