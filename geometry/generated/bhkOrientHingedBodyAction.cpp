#include "bhkOrientHingedBodyAction.hpp"

using namespace nejlika::geometry;

void bhkOrientHingedBodyAction::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkSerializable::Read(reader, version, user, arg);

    m_UnknownInts1.resize(17);
    for (uint32_t i = 0; i < m_UnknownInts1.size(); i++)
    {
        m_UnknownInts1[i] = reader.Read<int>();
    }

}

void bhkOrientHingedBodyAction::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkSerializable::Write(writer, version, user, arg);

    for (uint32_t i = 0; i < m_UnknownInts1.size(); i++)
    {
        writer.Write(m_UnknownInts1[i]);
    }

}
