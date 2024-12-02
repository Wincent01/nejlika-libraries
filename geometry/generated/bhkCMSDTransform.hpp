#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Vector4.hpp"
#include "QuaternionXYZW.hpp"
namespace nejlika::geometry {


/**
 * 
 *     A set of transformation data: translation and rotation
 *         
 */
class bhkCMSDTransform : public Construct
{
protected:
    /**
     * A vector that moves the chunk by the specified amount. W is not used.
     */
    Vector4 m_Translation;
    /**
     * Rotation. Reference point for rotation is bhkRigidBody translation.
     */
    QuaternionXYZW m_Rotation;

public:
    const Vector4& GetTranslation() const { return m_Translation; }
    Vector4& GetTranslation() { return m_Translation; }
    void SetTranslation(const Vector4& value) { m_Translation = value; }

    const QuaternionXYZW& GetRotation() const { return m_Rotation; }
    QuaternionXYZW& GetRotation() { return m_Rotation; }
    void SetRotation(const QuaternionXYZW& value) { m_Rotation = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
