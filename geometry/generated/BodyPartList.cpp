#include "BodyPartList.hpp"

using namespace nejlika::geometry;

void BodyPartList::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    m_PartFlag = reader.Read<BSPartFlag>();

    m_BodyPart = reader.Read<BSDismemberBodyPartType>();

}

void BodyPartList::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    writer.Write(m_PartFlag);

    writer.Write(m_BodyPart);

}
