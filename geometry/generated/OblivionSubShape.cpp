#include "OblivionSubShape.hpp"

using namespace nejlika::geometry;

void OblivionSubShape::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Layer = reader.Read<OblivionLayer>();

    m_ColFilter = reader.Read<byte>();

    m_UnknownShort = reader.Read<ushort>();

    m_NumVertices = reader.Read<uint>();

    m_Material = reader.Read<HavokMaterial>();

}

void OblivionSubShape::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_Layer);

    writer.Write(m_ColFilter);

    writer.Write(m_UnknownShort);

    writer.Write(m_NumVertices);

    writer.Write(m_Material);

}
