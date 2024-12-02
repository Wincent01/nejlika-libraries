#include "ElementReference.hpp"

using namespace nejlika::geometry;

void ElementReference::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_Semantic.Read(reader, version, user, 0);

    m_NormalizeFlag = reader.Read<uint>();

}

void ElementReference::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    m_Semantic.Write(writer, version, user, 0);

    writer.Write(m_NormalizeFlag);

}
