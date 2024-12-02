#include "NiPSBoundUpdater.hpp"

using namespace nejlika::geometry;

void NiPSBoundUpdater::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_Unknown1 = reader.Read<byte>();

    m_Unknown2 = reader.Read<byte>();

}

void NiPSBoundUpdater::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    writer.Write(m_Unknown1);

    writer.Write(m_Unknown2);

}
