#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "SyncPoint.hpp"
#include "SyncPoint.hpp"
#include "NiObject.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Base class for mesh modifiers.
 *         
 */
class NiMeshModifier : public NiObject
{
protected:
    /**
     * The number of submit points used by this mesh modifier.
     */
    uint m_NumSubmitPoints;
    /**
     * The submit points used by this mesh modifier
     */
    std::vector<SyncPoint> m_SubmitPoints;
    /**
     * The number of complete points used by this mesh modifier.
     */
    uint m_NumCompletePoints;
    /**
     * The complete points used by this mesh modifier
     */
    std::vector<SyncPoint> m_CompletePoints;

public:
    const uint& GetNumSubmitPoints() const { return m_NumSubmitPoints; }
    uint& GetNumSubmitPoints() { return m_NumSubmitPoints; }
    void SetNumSubmitPoints(const uint& value) { m_NumSubmitPoints = value; }

    const std::vector<SyncPoint>& GetSubmitPoints() const { return m_SubmitPoints; }
    std::vector<SyncPoint>& GetSubmitPoints() { return m_SubmitPoints; }
    void SetSubmitPoints(const std::vector<SyncPoint>& value) { m_SubmitPoints = value; }

    const uint& GetNumCompletePoints() const { return m_NumCompletePoints; }
    uint& GetNumCompletePoints() { return m_NumCompletePoints; }
    void SetNumCompletePoints(const uint& value) { m_NumCompletePoints = value; }

    const std::vector<SyncPoint>& GetCompletePoints() const { return m_CompletePoints; }
    std::vector<SyncPoint>& GetCompletePoints() { return m_CompletePoints; }
    void SetCompletePoints(const std::vector<SyncPoint>& value) { m_CompletePoints = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
