#include "NiSortAdjustNode.hpp"

using namespace nejlika::geometry;

void NiSortAdjustNode::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiNode::Read(reader, version, user, arg);

    m_SortingMode = reader.Read<SortingMode>();

    if (version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        m_UnknownInt2 = reader.Read<int>();
    }
    else
    {
        m_UnknownInt2 = -1;
    }

}

void NiSortAdjustNode::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiNode::Write(writer, version, user, arg);

    writer.Write(m_SortingMode);

    if (version <= VERSION_NUMBER(10, 2, 0, 0))
    {
        writer.Write(m_UnknownInt2);
    }
    else
    {
        //writer.Write(-1);
    }

}
