#include "bhkRigidBody.hpp"

using namespace nejlika::geometry;

void bhkRigidBody::Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg)
{
    bhkEntity::Read(reader, version, user, arg);

    m_UnknownInt1 = reader.Read<int>();

    m_UnknownInt2 = reader.Read<int>();

    m_Unknown3Ints.resize(3);
    for (uint32_t i = 0; i < m_Unknown3Ints.size(); i++)
    {
        m_Unknown3Ints[i] = reader.Read<int>();
    }

    m_CollisionResponse = reader.Read<hkResponseType>();

    m_UnknownByte = reader.Read<byte>();

    m_ProcessContactCallbackDelay = reader.Read<ushort>();

    m_Unknown2Shorts.resize(2);
    for (uint32_t i = 0; i < m_Unknown2Shorts.size(); i++)
    {
        m_Unknown2Shorts[i] = reader.Read<ushort>();
    }

    if (user< 12)
    {
        m_LayerCopy = reader.Read<OblivionLayer>();
    }
    else
    {
        m_LayerCopy = static_cast<OblivionLayer>(OL_STATIC);
    }

    if (user< 12)
    {
        m_ColFilterCopy = reader.Read<byte>();
    }
    else
    {
        m_ColFilterCopy = 0;
    }

    if (user>= 12)
    {
        m_SkyrimLayerCopy = reader.Read<SkyrimLayer>();
    }
    else
    {
        m_SkyrimLayerCopy = static_cast<SkyrimLayer>(SKYL_STATIC);
    }

    if (user>= 12)
    {
        m_FlagsAndPartNumberCopy = reader.Read<byte>();
    }
    else
    {
        m_FlagsAndPartNumberCopy = 0;
    }

    m_Unknown7Shorts.resize(7);
    for (uint32_t i = 0; i < m_Unknown7Shorts.size(); i++)
    {
        m_Unknown7Shorts[i] = reader.Read<ushort>();
    }

    m_Translation.Read(reader, version, user, 0);

    m_Rotation.Read(reader, version, user, 0);

    m_LinearVelocity.Read(reader, version, user, 0);

    m_AngularVelocity.Read(reader, version, user, 0);

    m_Inertia.Read(reader, version, user, 0);

    m_Center.Read(reader, version, user, 0);

    m_Mass = reader.Read<float>();

    m_LinearDamping = reader.Read<float>();

    m_AngularDamping = reader.Read<float>();

    if ((user>= 12))
    {
        m_UnknownTimeFactorOrGravityFactor1 = reader.Read<float>();
    }

    if ((user>= 12))
    {
        m_UnknownTimeFactorOrGravityFactor2 = reader.Read<float>();
    }

    m_Friction = reader.Read<float>();

    if ((user>= 12))
    {
        m_RollingFrictionMultiplier = reader.Read<float>();
    }

    m_Restitution = reader.Read<float>();

    m_MaxLinearVelocity = reader.Read<float>();

    m_MaxAngularVelocity = reader.Read<float>();

    m_PenetrationDepth = reader.Read<float>();

    m_MotionSystem = reader.Read<MotionSystem>();

    m_DeactivatorType = reader.Read<DeactivatorType>();

    m_SolverDeactivation = reader.Read<SolverDeactivation>();

    m_QualityType = reader.Read<MotionQuality>();

    m_UnknownInt6 = reader.Read<uint>();

    m_UnknownInt7 = reader.Read<uint>();

    m_UnknownInt8 = reader.Read<uint>();

    if ((user>= 12))
    {
        m_UnknownInt81 = reader.Read<uint>();
    }

    m_NumConstraints = reader.Read<uint>();

    m_Constraints.resize(m_NumConstraints);
    for (uint32_t i = 0; i < m_Constraints.size(); i++)
    {
        m_Constraints[i].Read(reader, version, user, 0);
    }

    if ((user<= 11))
    {
        m_UnknownInt9 = reader.Read<uint>();
    }

    if ((user>= 12))
    {
        m_UnknownInt91 = reader.Read<ushort>();
    }

}

void bhkRigidBody::Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const
{
    bhkEntity::Write(writer, version, user, arg);

    writer.Write(m_UnknownInt1);

    writer.Write(m_UnknownInt2);

    for (uint32_t i = 0; i < m_Unknown3Ints.size(); i++)
    {
        writer.Write(m_Unknown3Ints[i]);
    }

    writer.Write(m_CollisionResponse);

    writer.Write(m_UnknownByte);

    writer.Write(m_ProcessContactCallbackDelay);

    for (uint32_t i = 0; i < m_Unknown2Shorts.size(); i++)
    {
        writer.Write(m_Unknown2Shorts[i]);
    }

    if (user< 12)
    {
        writer.Write(m_LayerCopy);
    }
    else
    {
        //writer.Write(OL_STATIC);
    }

    if (user< 12)
    {
        writer.Write(m_ColFilterCopy);
    }
    else
    {
        //writer.Write(0);
    }

    if (user>= 12)
    {
        writer.Write(m_SkyrimLayerCopy);
    }
    else
    {
        //writer.Write(SKYL_STATIC);
    }

    if (user>= 12)
    {
        writer.Write(m_FlagsAndPartNumberCopy);
    }
    else
    {
        //writer.Write(0);
    }

    for (uint32_t i = 0; i < m_Unknown7Shorts.size(); i++)
    {
        writer.Write(m_Unknown7Shorts[i]);
    }

    m_Translation.Write(writer, version, user, 0);

    m_Rotation.Write(writer, version, user, 0);

    m_LinearVelocity.Write(writer, version, user, 0);

    m_AngularVelocity.Write(writer, version, user, 0);

    m_Inertia.Write(writer, version, user, 0);

    m_Center.Write(writer, version, user, 0);

    writer.Write(m_Mass);

    writer.Write(m_LinearDamping);

    writer.Write(m_AngularDamping);

    if ((user>= 12))
    {
        writer.Write(m_UnknownTimeFactorOrGravityFactor1);
    }

    if ((user>= 12))
    {
        writer.Write(m_UnknownTimeFactorOrGravityFactor2);
    }

    writer.Write(m_Friction);

    if ((user>= 12))
    {
        writer.Write(m_RollingFrictionMultiplier);
    }

    writer.Write(m_Restitution);

    writer.Write(m_MaxLinearVelocity);

    writer.Write(m_MaxAngularVelocity);

    writer.Write(m_PenetrationDepth);

    writer.Write(m_MotionSystem);

    writer.Write(m_DeactivatorType);

    writer.Write(m_SolverDeactivation);

    writer.Write(m_QualityType);

    writer.Write(m_UnknownInt6);

    writer.Write(m_UnknownInt7);

    writer.Write(m_UnknownInt8);

    if ((user>= 12))
    {
        writer.Write(m_UnknownInt81);
    }

    writer.Write(m_NumConstraints);

    for (uint32_t i = 0; i < m_Constraints.size(); i++)
    {
        m_Constraints[i].Write(writer, version, user, 0);
    }

    if ((user<= 11))
    {
        writer.Write(m_UnknownInt9);
    }

    if ((user>= 12))
    {
        writer.Write(m_UnknownInt91);
    }

}
