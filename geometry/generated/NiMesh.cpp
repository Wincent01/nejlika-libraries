#include "NiMesh.hpp"

using namespace nejlika::geometry;

void NiMesh::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    NiRenderObject::Read(reader, version, user, arg);

    m_PrimitiveType = reader.Read<MeshPrimitiveType>();

    if (user == 15)
    {
        m_Unknown51 = reader.Read<int>();
    }

    if (user == 15)
    {
        m_Unknown52 = reader.Read<int>();
    }

    if (user == 15)
    {
        m_Unknown53 = reader.Read<int>();
    }

    if (user == 15)
    {
        m_Unknown54 = reader.Read<int>();
    }

    if (user == 15)
    {
        m_Unknown55 = reader.Read<float>();
    }

    if (user == 15)
    {
        m_Unknown56 = reader.Read<int>();
    }

    m_NumSubmeshes = reader.Read<ushort>();

    m_InstancingEnabled = reader.Read<bool>();

    m_Bound.Read(reader, version, user, 0);

    m_NumDatas = reader.Read<uint>();

    m_Datas.resize(m_NumDatas);
    for (uint32_t i = 0; i < m_Datas.size(); i++)
    {
        m_Datas[i].Read(reader, version, user, 0);
    }

    m_NumModifiers = reader.Read<uint>();

    m_Modifiers.resize(m_NumModifiers);
    for (uint32_t i = 0; i < m_Modifiers.size(); i++)
    {
        m_Modifiers[i].Read(reader, version, user, 0);
    }

    if (user == 15)
    {
        m_Unknown100 = reader.Read<byte>();
    }

    if (user == 15)
    {
        m_Unknown101 = reader.Read<int>();
    }

    if (user == 15)
    {
        m_Unknown102 = reader.Read<uint>();
    }

    if (user == 15)
    {
        m_Unknown103.resize(m_Unknown102);
        for (uint32_t i = 0; i < m_Unknown103.size(); i++)
        {
            m_Unknown103[i] = reader.Read<float>();
        }
    }

    if (user == 15)
    {
        m_Unknown200 = reader.Read<int>();
    }

    if (user == 15)
    {
        m_Unknown201.resize(m_Unknown200);
        for (uint32_t i = 0; i < m_Unknown201.size(); i++)
        {
            m_Unknown201[i].Read(reader, version, user, 0);
        }
    }

    if (user == 15)
    {
        m_Unknown250 = reader.Read<int>();
    }

    if (user == 15)
    {
        m_Unknown251.resize(m_Unknown250);
        for (uint32_t i = 0; i < m_Unknown251.size(); i++)
        {
            m_Unknown251[i] = reader.Read<int>();
        }
    }

    if (user == 15)
    {
        m_Unknown300 = reader.Read<int>();
    }

    if (user == 15)
    {
        m_Unknown301 = reader.Read<short>();
    }

    if (user == 15)
    {
        m_Unknown302 = reader.Read<int>();
    }

    if (user == 15)
    {
        m_Unknown303.resize(m_Unknown302);
        for (uint32_t i = 0; i < m_Unknown303.size(); i++)
        {
            m_Unknown303[i] = reader.Read<byte>();
        }
    }

    if (user == 15)
    {
        m_Unknown350 = reader.Read<int>();
    }

    if (user == 15)
    {
        m_Unknown351.resize(m_Unknown350);
        for (uint32_t i = 0; i < m_Unknown351.size(); i++)
        {
            m_Unknown351[i].Read(reader, version, user, 0);
        }
    }

    if (user == 15)
    {
        m_Unknown400 = reader.Read<int>();
    }

}

void NiMesh::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    NiRenderObject::Write(writer, version, user, arg);

    writer.Write(m_PrimitiveType);

    if (user == 15)
    {
        writer.Write(m_Unknown51);
    }

    if (user == 15)
    {
        writer.Write(m_Unknown52);
    }

    if (user == 15)
    {
        writer.Write(m_Unknown53);
    }

    if (user == 15)
    {
        writer.Write(m_Unknown54);
    }

    if (user == 15)
    {
        writer.Write(m_Unknown55);
    }

    if (user == 15)
    {
        writer.Write(m_Unknown56);
    }

    writer.Write(m_NumSubmeshes);

    writer.Write(m_InstancingEnabled);

    m_Bound.Write(writer, version, user, 0);

    writer.Write(m_NumDatas);

    for (uint32_t i = 0; i < m_Datas.size(); i++)
    {
        m_Datas[i].Write(writer, version, user, 0);
    }

    writer.Write(m_NumModifiers);

    for (uint32_t i = 0; i < m_Modifiers.size(); i++)
    {
        m_Modifiers[i].Write(writer, version, user, 0);
    }

    if (user == 15)
    {
        writer.Write(m_Unknown100);
    }

    if (user == 15)
    {
        writer.Write(m_Unknown101);
    }

    if (user == 15)
    {
        writer.Write(m_Unknown102);
    }

    if (user == 15)
    {
        for (uint32_t i = 0; i < m_Unknown103.size(); i++)
        {
            writer.Write(m_Unknown103[i]);
        }
    }

    if (user == 15)
    {
        writer.Write(m_Unknown200);
    }

    if (user == 15)
    {
        for (uint32_t i = 0; i < m_Unknown201.size(); i++)
        {
            m_Unknown201[i].Write(writer, version, user, 0);
        }
    }

    if (user == 15)
    {
        writer.Write(m_Unknown250);
    }

    if (user == 15)
    {
        for (uint32_t i = 0; i < m_Unknown251.size(); i++)
        {
            writer.Write(m_Unknown251[i]);
        }
    }

    if (user == 15)
    {
        writer.Write(m_Unknown300);
    }

    if (user == 15)
    {
        writer.Write(m_Unknown301);
    }

    if (user == 15)
    {
        writer.Write(m_Unknown302);
    }

    if (user == 15)
    {
        for (uint32_t i = 0; i < m_Unknown303.size(); i++)
        {
            writer.Write(m_Unknown303[i]);
        }
    }

    if (user == 15)
    {
        writer.Write(m_Unknown350);
    }

    if (user == 15)
    {
        for (uint32_t i = 0; i < m_Unknown351.size(); i++)
        {
            m_Unknown351[i].Write(writer, version, user, 0);
        }
    }

    if (user == 15)
    {
        writer.Write(m_Unknown400);
    }

}
