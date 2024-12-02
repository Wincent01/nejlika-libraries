#include "NiPSysBombModifier.hpp"

using namespace nejlika::geometry;

void NiPSysBombModifier::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiPSysModifier::Read(reader, version, user, arg);

    m_BombObject.Read(reader, version, user, 0);

    m_BombAxis.Read(reader, version, user, 0);

    m_Decay = reader.Read<float>();

    m_DeltaV = reader.Read<float>();

    m_DecayType = reader.Read<DecayType>();

    m_SymmetryType = reader.Read<SymmetryType>();

}

void NiPSysBombModifier::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiPSysModifier::Write(writer, version, user, arg);

    m_BombObject.Write(writer, version, user, 0);

    m_BombAxis.Write(writer, version, user, 0);

    writer.Write(m_Decay);

    writer.Write(m_DeltaV);

    writer.Write(m_DecayType);

    writer.Write(m_SymmetryType);

}
