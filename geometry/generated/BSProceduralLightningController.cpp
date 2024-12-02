#include "BSProceduralLightningController.hpp"

using namespace nejlika::geometry;

void BSProceduralLightningController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiFloatInterpController::Read(reader, version, user, arg);

    m_Interpolator2Mutation.Read(reader, version, user, 0);

    m_Interpolator3.Read(reader, version, user, 0);

    m_Interpolator4.Read(reader, version, user, 0);

    m_Interpolator5.Read(reader, version, user, 0);

    m_Interpolator6.Read(reader, version, user, 0);

    m_Interpolator7.Read(reader, version, user, 0);

    m_Interpolator8.Read(reader, version, user, 0);

    m_Interpolator9ArcOffset.Read(reader, version, user, 0);

    m_UnknownShort1 = reader.Read<ushort>();

    m_UnknownShort2 = reader.Read<ushort>();

    m_UnknownShort3 = reader.Read<ushort>();

    m_DistanceWeight = reader.Read<float>();

    m_Float2 = reader.Read<float>();

    m_StripWidth = reader.Read<float>();

    m_Fork = reader.Read<float>();

    m_Float5 = reader.Read<float>();

    m_Byte1 = reader.Read<byte>();

    m_Byte2 = reader.Read<byte>();

    m_Byte3 = reader.Read<byte>();

    m_Interpolator10.Read(reader, version, user, 0);

}

void BSProceduralLightningController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiFloatInterpController::Write(writer, version, user, arg);

    m_Interpolator2Mutation.Write(writer, version, user, 0);

    m_Interpolator3.Write(writer, version, user, 0);

    m_Interpolator4.Write(writer, version, user, 0);

    m_Interpolator5.Write(writer, version, user, 0);

    m_Interpolator6.Write(writer, version, user, 0);

    m_Interpolator7.Write(writer, version, user, 0);

    m_Interpolator8.Write(writer, version, user, 0);

    m_Interpolator9ArcOffset.Write(writer, version, user, 0);

    writer.Write(m_UnknownShort1);

    writer.Write(m_UnknownShort2);

    writer.Write(m_UnknownShort3);

    writer.Write(m_DistanceWeight);

    writer.Write(m_Float2);

    writer.Write(m_StripWidth);

    writer.Write(m_Fork);

    writer.Write(m_Float5);

    writer.Write(m_Byte1);

    writer.Write(m_Byte2);

    writer.Write(m_Byte3);

    m_Interpolator10.Write(writer, version, user, 0);

}
