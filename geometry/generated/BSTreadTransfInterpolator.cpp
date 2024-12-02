#include "BSTreadTransfInterpolator.hpp"

using namespace nejlika::geometry;

void BSTreadTransfInterpolator::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiInterpolator::Read(reader, version, user, arg);

    m_NumTreadTransforms = reader.Read<int>();

    m_TreadTransforms.resize(m_NumTreadTransforms);
    for (uint32_t i = 0; i < m_TreadTransforms.size(); i++)
    {
        m_TreadTransforms[i].Read(reader, version, user, 0);
    }

    m_Data.Read(reader, version, user, 0);

}

void BSTreadTransfInterpolator::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiInterpolator::Write(writer, version, user, arg);

    writer.Write(m_NumTreadTransforms);

    for (uint32_t i = 0; i < m_TreadTransforms.size(); i++)
    {
        m_TreadTransforms[i].Write(writer, version, user, 0);
    }

    m_Data.Write(writer, version, user, 0);

}
