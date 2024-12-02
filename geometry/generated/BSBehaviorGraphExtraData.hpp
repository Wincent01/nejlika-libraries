#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "string.hpp"
#include "NiExtraData.hpp"
namespace nejlika::geometry {


/**
 * 
 *     Links a nif with a Havok Behavior .hkx animation file
 * 		
 */
class BSBehaviorGraphExtraData : public NiExtraData
{
protected:
    /**
     * Name of the hkx file.
     */
    string m_BehaviourGraphFile;
    /**
     * Unknown, has to do with blending appended bones onto an actor.
     */
    byte m_ControlsBaseSkeleton;

public:
    const string& GetBehaviourGraphFile() const { return m_BehaviourGraphFile; }
    string& GetBehaviourGraphFile() { return m_BehaviourGraphFile; }
    void SetBehaviourGraphFile(const string& value) { m_BehaviourGraphFile = value; }

    const byte& GetControlsBaseSkeleton() const { return m_ControlsBaseSkeleton; }
    byte& GetControlsBaseSkeleton() { return m_ControlsBaseSkeleton; }
    void SetControlsBaseSkeleton(const byte& value) { m_ControlsBaseSkeleton = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
