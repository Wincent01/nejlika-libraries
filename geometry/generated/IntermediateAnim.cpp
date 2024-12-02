#include "IntermediateAnim.hpp"

using namespace nejlika::geometry;

void IntermediateAnim::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_UnknownInt = reader.Read<int>();

    m_Event.Read(reader, version, user, 0);

}

void IntermediateAnim::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_UnknownInt);

    m_Event.Write(writer, version, user, 0);

}
