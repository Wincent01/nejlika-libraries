#include "NiBinaryVoxelExtraData.hpp"

using namespace nejlika::geometry;

void NiBinaryVoxelExtraData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiExtraData::Read(reader, version, user, arg);

    m_UnknownInt = reader.Read<uint>();

    m_Data.Read(reader, version, user, 0);

}

void NiBinaryVoxelExtraData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiExtraData::Write(writer, version, user, arg);

    writer.Write(m_UnknownInt);

    m_Data.Write(writer, version, user, 0);

}
