#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "Key.hpp"
#include "PSLoopBehavior.hpp"
#include "Key.hpp"
#include "ByteColor4.hpp"
#include "PSLoopBehavior.hpp"
#include "QuatKey.hpp"
#include "Quaternion.hpp"
#include "PSLoopBehavior.hpp"
#include "NiPSSimulatorStep.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Encapsulates a floodgate kernel that updates particle size, colors, and rotations.
 *         
 */
class NiPSSimulatorGeneralStep : public NiPSSimulatorStep
{
protected:
    /**
     * The number of size animation keys.
     */
    byte m_NumSizeKeys;
    /**
     * The particle size keys.
     */
    std::vector<Key<float>> m_SizeKeys;
    /**
     * The loop behavior for the size keys.
     */
    PSLoopBehavior m_SizeLoopBehavior;
    float m_Unknown1;
    float m_Unknown2;
    float m_Unknown3;
    /**
     * The number of color animation keys.
     */
    byte m_NumColorKeys;
    /**
     * The particle color keys.
     */
    std::vector<Key<ByteColor4>> m_ColorKeys;
    /**
     * The loop behavior for the color keys.
     */
    PSLoopBehavior m_ColorLoopBehavior;
    /**
     * The number of rotatoin animation keys.
     */
    byte m_NumRotationKeys;
    /**
     * The particle rotation keys.
     */
    std::vector<QuatKey<Quaternion>> m_RotationKeys;
    /**
     * The loop behavior for the rotation keys.
     */
    PSLoopBehavior m_RotationLoopBehavior;
    /**
     *  The the amount of time over which a particle's size is ramped from 0.0 to 1.0 in seconds
     */
    float m_GrowTime;
    /**
     * The the amount of time over which a particle's size is ramped from 1.0 to 0.0 in seconds
     */
    float m_ShrinkTime;
    /**
     * Specifies the particle generation to which the grow effect should be applied. This is usually generation 0, so that newly created particles will grow.
     */
    ushort m_GrowGeneration;
    /**
     * Specifies the particle generation to which the shrink effect should be applied. This is usually the highest supported generation for the particle system, so that particles will shrink immediately before getting killed.
     */
    ushort m_ShrinkGeneration;

public:
    const byte& GetNumSizeKeys() const { return m_NumSizeKeys; }
    byte& GetNumSizeKeys() { return m_NumSizeKeys; }
    void SetNumSizeKeys(const byte& value) { m_NumSizeKeys = value; }

    const std::vector<Key<float>>& GetSizeKeys() const { return m_SizeKeys; }
    std::vector<Key<float>>& GetSizeKeys() { return m_SizeKeys; }
    void SetSizeKeys(const std::vector<Key<float>>& value) { m_SizeKeys = value; }

    const PSLoopBehavior& GetSizeLoopBehavior() const { return m_SizeLoopBehavior; }
    PSLoopBehavior& GetSizeLoopBehavior() { return m_SizeLoopBehavior; }
    void SetSizeLoopBehavior(const PSLoopBehavior& value) { m_SizeLoopBehavior = value; }

    const float& GetUnknown1() const { return m_Unknown1; }
    float& GetUnknown1() { return m_Unknown1; }
    void SetUnknown1(const float& value) { m_Unknown1 = value; }

    const float& GetUnknown2() const { return m_Unknown2; }
    float& GetUnknown2() { return m_Unknown2; }
    void SetUnknown2(const float& value) { m_Unknown2 = value; }

    const float& GetUnknown3() const { return m_Unknown3; }
    float& GetUnknown3() { return m_Unknown3; }
    void SetUnknown3(const float& value) { m_Unknown3 = value; }

    const byte& GetNumColorKeys() const { return m_NumColorKeys; }
    byte& GetNumColorKeys() { return m_NumColorKeys; }
    void SetNumColorKeys(const byte& value) { m_NumColorKeys = value; }

    const std::vector<Key<ByteColor4>>& GetColorKeys() const { return m_ColorKeys; }
    std::vector<Key<ByteColor4>>& GetColorKeys() { return m_ColorKeys; }
    void SetColorKeys(const std::vector<Key<ByteColor4>>& value) { m_ColorKeys = value; }

    const PSLoopBehavior& GetColorLoopBehavior() const { return m_ColorLoopBehavior; }
    PSLoopBehavior& GetColorLoopBehavior() { return m_ColorLoopBehavior; }
    void SetColorLoopBehavior(const PSLoopBehavior& value) { m_ColorLoopBehavior = value; }

    const byte& GetNumRotationKeys() const { return m_NumRotationKeys; }
    byte& GetNumRotationKeys() { return m_NumRotationKeys; }
    void SetNumRotationKeys(const byte& value) { m_NumRotationKeys = value; }

    const std::vector<QuatKey<Quaternion>>& GetRotationKeys() const { return m_RotationKeys; }
    std::vector<QuatKey<Quaternion>>& GetRotationKeys() { return m_RotationKeys; }
    void SetRotationKeys(const std::vector<QuatKey<Quaternion>>& value) { m_RotationKeys = value; }

    const PSLoopBehavior& GetRotationLoopBehavior() const { return m_RotationLoopBehavior; }
    PSLoopBehavior& GetRotationLoopBehavior() { return m_RotationLoopBehavior; }
    void SetRotationLoopBehavior(const PSLoopBehavior& value) { m_RotationLoopBehavior = value; }

    const float& GetGrowTime() const { return m_GrowTime; }
    float& GetGrowTime() { return m_GrowTime; }
    void SetGrowTime(const float& value) { m_GrowTime = value; }

    const float& GetShrinkTime() const { return m_ShrinkTime; }
    float& GetShrinkTime() { return m_ShrinkTime; }
    void SetShrinkTime(const float& value) { m_ShrinkTime = value; }

    const ushort& GetGrowGeneration() const { return m_GrowGeneration; }
    ushort& GetGrowGeneration() { return m_GrowGeneration; }
    void SetGrowGeneration(const ushort& value) { m_GrowGeneration = value; }

    const ushort& GetShrinkGeneration() const { return m_ShrinkGeneration; }
    ushort& GetShrinkGeneration() { return m_ShrinkGeneration; }
    void SetShrinkGeneration(const ushort& value) { m_ShrinkGeneration = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
