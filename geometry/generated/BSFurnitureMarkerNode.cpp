#include "BSFurnitureMarkerNode.hpp"

using namespace nejlika::geometry;

void BSFurnitureMarkerNode::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    BSFurnitureMarker::Read(reader, version, user, arg);

}

void BSFurnitureMarkerNode::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    BSFurnitureMarker::Write(writer, version, user, arg);

}
