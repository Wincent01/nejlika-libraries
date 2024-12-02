#include "OblivionColFilter.hpp"

using namespace nejlika::geometry;

void OblivionColFilter::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Layer = reader.Read<OblivionLayer>();

    m_ColFilter = reader.Read<byte>();

    m_UnknownShort = reader.Read<ushort>();

}

void OblivionColFilter::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_Layer);

    writer.Write(m_ColFilter);

    writer.Write(m_UnknownShort);

}
