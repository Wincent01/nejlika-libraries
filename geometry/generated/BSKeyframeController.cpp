#include "BSKeyframeController.hpp"

using namespace nejlika::geometry;

void BSKeyframeController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiKeyframeController::Read(reader, version, user, arg);

    m_Data2.Read(reader, version, user, 0);

}

void BSKeyframeController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiKeyframeController::Write(writer, version, user, arg);

    m_Data2.Write(writer, version, user, 0);

}
