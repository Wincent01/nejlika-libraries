#include "BSMultiBoundAABB.hpp"

using namespace nejlika::geometry;

void BSMultiBoundAABB::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    BSMultiBoundData::Read(reader, version, user, arg);

    m_Position.Read(reader, version, user, 0);

    m_Extent.Read(reader, version, user, 0);

}

void BSMultiBoundAABB::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    BSMultiBoundData::Write(writer, version, user, arg);

    m_Position.Write(writer, version, user, 0);

    m_Extent.Write(writer, version, user, 0);

}
