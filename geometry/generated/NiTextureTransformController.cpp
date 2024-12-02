#include "NiTextureTransformController.hpp"

using namespace nejlika::geometry;

void NiTextureTransformController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiFloatInterpController::Read(reader, version, user, arg);

    m_Unknown2 = reader.Read<byte>();

    m_TextureSlot = reader.Read<TexType>();

    m_Operation = reader.Read<TexTransform>();

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_Data.Read(reader, version, user, 0);
    }

}

void NiTextureTransformController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiFloatInterpController::Write(writer, version, user, arg);

    writer.Write(m_Unknown2);

    writer.Write(m_TextureSlot);

    writer.Write(m_Operation);

    if (version <= VERSION_NUMBER(10, 1, 0, 0))
    {
        m_Data.Write(writer, version, user, 0);
    }

}
