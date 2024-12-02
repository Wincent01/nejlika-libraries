#include "bhkWorldObject.hpp"

using namespace nejlika::geometry;

void bhkWorldObject::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkSerializable::Read(reader, version, user, arg);

    m_Shape.Read(reader, version, user, 0);

    if (user< 12)
    {
        m_Layer = reader.Read<OblivionLayer>();
    }
    else
    {
        m_Layer = static_cast<OblivionLayer>(OL_STATIC);
    }

    if (user< 12)
    {
        m_ColFilter = reader.Read<byte>();
    }
    else
    {
        m_ColFilter = 0;
    }

    if (user>= 12)
    {
        m_SkyrimLayer = reader.Read<SkyrimLayer>();
    }
    else
    {
        m_SkyrimLayer = static_cast<SkyrimLayer>(SKYL_STATIC);
    }

    if (user>= 12)
    {
        m_FlagsAndPartNumber = reader.Read<byte>();
    }
    else
    {
        m_FlagsAndPartNumber = 0;
    }

    m_UnknownShort = reader.Read<ushort>();

}

void bhkWorldObject::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkSerializable::Write(writer, version, user, arg);

    m_Shape.Write(writer, version, user, 0);

    if (user< 12)
    {
        writer.Write(m_Layer);
    }
    else
    {
        //writer.Write(OL_STATIC);
    }

    if (user< 12)
    {
        writer.Write(m_ColFilter);
    }
    else
    {
        //writer.Write(0);
    }

    if (user>= 12)
    {
        writer.Write(m_SkyrimLayer);
    }
    else
    {
        //writer.Write(SKYL_STATIC);
    }

    if (user>= 12)
    {
        writer.Write(m_FlagsAndPartNumber);
    }
    else
    {
        //writer.Write(0);
    }

    writer.Write(m_UnknownShort);

}
