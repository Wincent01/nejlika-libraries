#include "NiParticleModifier.hpp"

using namespace nejlika::geometry;

void NiParticleModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiObject::Read(reader, version, user, arg);

    m_NextModifier.Read(reader, version, user, 0);

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        m_Controller.Read(reader, version, user, 0);
    }

}

void NiParticleModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiObject::Write(writer, version, user, arg);

    m_NextModifier.Write(writer, version, user, 0);

    if (version >= VERSION_NUMBER(4, 0, 0, 2))
    {
        m_Controller.Write(writer, version, user, 0);
    }

}
