#include "SemanticData.hpp"

using namespace nejlika::geometry;

void SemanticData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Name.Read(reader, version, user, 0);

    m_Index = reader.Read<uint>();

}

void SemanticData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    m_Name.Write(writer, version, user, 0);

    writer.Write(m_Index);

}
