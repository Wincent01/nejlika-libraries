#include "BSLODTriShape.hpp"

using namespace nejlika::geometry;

void BSLODTriShape::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTriBasedGeom::Read(reader, version, user, arg);

    m_Level0Size = reader.Read<uint>();

    m_Level1Size = reader.Read<uint>();

    m_Level2Size = reader.Read<uint>();

}

void BSLODTriShape::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTriBasedGeom::Write(writer, version, user, arg);

    writer.Write(m_Level0Size);

    writer.Write(m_Level1Size);

    writer.Write(m_Level2Size);

}
