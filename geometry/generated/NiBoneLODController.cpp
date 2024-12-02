#include "NiBoneLODController.hpp"

using namespace nejlika::geometry;

void NiBoneLODController::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiTimeController::Read(reader, version, user, arg);

    m_UnknownInt1 = reader.Read<uint>();

    m_NumNodeGroups = reader.Read<uint>();

    m_NumNodeGroups2 = reader.Read<uint>();

    m_NodeGroups.resize(m_NumNodeGroups);
    for (uint32_t i = 0; i < m_NodeGroups.size(); i++)
    {
        m_NodeGroups[i].Read(reader, version, user, 0);
    }

    if (version >= VERSION_NUMBER(4, 2, 2, 0) && user == 0)
    {
        m_NumShapeGroups = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(10, 2, 0, 0) && user == 1)
    {
        m_NumShapeGroups = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(4, 2, 2, 0) && user == 0)
    {
        m_ShapeGroups1.resize(m_NumShapeGroups);
        for (uint32_t i = 0; i < m_ShapeGroups1.size(); i++)
        {
            m_ShapeGroups1[i].Read(reader, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(10, 2, 0, 0) && user == 1)
    {
        m_ShapeGroups1.resize(m_NumShapeGroups);
        for (uint32_t i = 0; i < m_ShapeGroups1.size(); i++)
        {
            m_ShapeGroups1[i].Read(reader, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(4, 2, 2, 0) && user == 0)
    {
        m_NumShapeGroups2 = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(10, 2, 0, 0) && user == 1)
    {
        m_NumShapeGroups2 = reader.Read<uint>();
    }

    if (version >= VERSION_NUMBER(4, 2, 2, 0) && user == 0)
    {
        m_ShapeGroups2.resize(m_NumShapeGroups2);
        for (uint32_t i = 0; i < m_ShapeGroups2.size(); i++)
        {
            m_ShapeGroups2[i].Read(reader, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(10, 2, 0, 0) && user == 1)
    {
        m_ShapeGroups2.resize(m_NumShapeGroups2);
        for (uint32_t i = 0; i < m_ShapeGroups2.size(); i++)
        {
            m_ShapeGroups2[i].Read(reader, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(20, 3, 0, 9) && version <= VERSION_NUMBER(20, 3, 0, 9) && user == 131072)
    {
        m_UnknownInt2 = reader.Read<int>();
    }

    if (version >= VERSION_NUMBER(20, 3, 0, 9) && version <= VERSION_NUMBER(20, 3, 0, 9) && user == 131072)
    {
        m_UnknownInt3 = reader.Read<int>();
    }

}

void NiBoneLODController::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiTimeController::Write(writer, version, user, arg);

    writer.Write(m_UnknownInt1);

    writer.Write(m_NumNodeGroups);

    writer.Write(m_NumNodeGroups2);

    for (uint32_t i = 0; i < m_NodeGroups.size(); i++)
    {
        m_NodeGroups[i].Write(writer, version, user, 0);
    }

    if (version >= VERSION_NUMBER(4, 2, 2, 0) && user == 0)
    {
        writer.Write(m_NumShapeGroups);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(10, 2, 0, 0) && user == 1)
    {
        writer.Write(m_NumShapeGroups);
    }

    if (version >= VERSION_NUMBER(4, 2, 2, 0) && user == 0)
    {
        for (uint32_t i = 0; i < m_ShapeGroups1.size(); i++)
        {
            m_ShapeGroups1[i].Write(writer, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(10, 2, 0, 0) && user == 1)
    {
        for (uint32_t i = 0; i < m_ShapeGroups1.size(); i++)
        {
            m_ShapeGroups1[i].Write(writer, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(4, 2, 2, 0) && user == 0)
    {
        writer.Write(m_NumShapeGroups2);
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(10, 2, 0, 0) && user == 1)
    {
        writer.Write(m_NumShapeGroups2);
    }

    if (version >= VERSION_NUMBER(4, 2, 2, 0) && user == 0)
    {
        for (uint32_t i = 0; i < m_ShapeGroups2.size(); i++)
        {
            m_ShapeGroups2[i].Write(writer, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(10, 2, 0, 0) && version <= VERSION_NUMBER(10, 2, 0, 0) && user == 1)
    {
        for (uint32_t i = 0; i < m_ShapeGroups2.size(); i++)
        {
            m_ShapeGroups2[i].Write(writer, version, user, 0);
        }
    }

    if (version >= VERSION_NUMBER(20, 3, 0, 9) && version <= VERSION_NUMBER(20, 3, 0, 9) && user == 131072)
    {
        writer.Write(m_UnknownInt2);
    }

    if (version >= VERSION_NUMBER(20, 3, 0, 9) && version <= VERSION_NUMBER(20, 3, 0, 9) && user == 131072)
    {
        writer.Write(m_UnknownInt3);
    }

}
