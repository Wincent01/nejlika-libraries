#include "ExportInfo.hpp"

using namespace nejlika::geometry;

void ExportInfo::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    if (version <= VERSION_NUMBER(10, 0, 1, 2))
    {
        m_Unknown = reader.Read<uint>();
    }
    else
    {
        m_Unknown = 3;
    }

    m_Creator.Read(reader, version, user, 0);

    m_ExportInfo1.Read(reader, version, user, 0);

    m_ExportInfo2.Read(reader, version, user, 0);

}

void ExportInfo::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    if (version <= VERSION_NUMBER(10, 0, 1, 2))
    {
        writer.Write(m_Unknown);
    }
    else
    {
        //writer.Write(3);
    }

    m_Creator.Write(writer, version, user, 0);

    m_ExportInfo1.Write(writer, version, user, 0);

    m_ExportInfo2.Write(writer, version, user, 0);

}
