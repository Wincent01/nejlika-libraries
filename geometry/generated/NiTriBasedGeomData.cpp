#include "NiTriBasedGeomData.hpp"

using namespace nejlika::geometry;

void NiTriBasedGeomData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiGeometryData::Read(reader, version, user, arg);

    m_NumTriangles = reader.Read<ushort>();

}

void NiTriBasedGeomData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiGeometryData::Write(writer, version, user, arg);

    writer.Write(m_NumTriangles);

}
