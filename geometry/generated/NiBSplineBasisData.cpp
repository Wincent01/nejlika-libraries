#include "NiBSplineBasisData.hpp"

using namespace nejlika::geometry;

void NiBSplineBasisData::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_NumControlPoints = reader.Read<uint>();

}

void NiBSplineBasisData::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    writer.Write(m_NumControlPoints);

}
