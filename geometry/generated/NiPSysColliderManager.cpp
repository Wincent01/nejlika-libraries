#include "NiPSysColliderManager.hpp"

using namespace nejlika::geometry;

void NiPSysColliderManager::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysModifier::Read(reader, version, user, arg);

    m_Collider.Read(reader, version, user, 0);

}

void NiPSysColliderManager::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysModifier::Write(writer, version, user, arg);

    m_Collider.Write(writer, version, user, 0);

}
