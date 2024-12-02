#include "BSMultiBoundOBB.hpp"

using namespace nejlika::geometry;

void BSMultiBoundOBB::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    BSMultiBoundData::Read(reader, version, user, arg);

    m_Center.Read(reader, version, user, 0);

    m_Size.Read(reader, version, user, 0);

    m_Rotation.Read(reader, version, user, 0);

}

void BSMultiBoundOBB::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    BSMultiBoundData::Write(writer, version, user, arg);

    m_Center.Write(writer, version, user, 0);

    m_Size.Write(writer, version, user, 0);

    m_Rotation.Write(writer, version, user, 0);

}
