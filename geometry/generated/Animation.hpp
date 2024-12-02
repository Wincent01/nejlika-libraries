#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "SizedString.hpp"
#include "SizedString.hpp"
#include "Transition.hpp"
namespace nejlika::geometry {


class Animation : public Construct
{
protected:
    int m_EventCode;
    SizedString m_Name;
    SizedString m_KFFileName;
    /**
     * An index?
     */
    int m_Index;
    int m_NumTransitions;
    /**
     * Max = Num Animations -1? No transition from animation to itself.
     */
    std::vector<Transition> m_Transitions;

public:
    const int& GetEventCode() const { return m_EventCode; }
    int& GetEventCode() { return m_EventCode; }
    void SetEventCode(const int& value) { m_EventCode = value; }

    const SizedString& GetName() const { return m_Name; }
    SizedString& GetName() { return m_Name; }
    void SetName(const SizedString& value) { m_Name = value; }

    const SizedString& GetKFFileName() const { return m_KFFileName; }
    SizedString& GetKFFileName() { return m_KFFileName; }
    void SetKFFileName(const SizedString& value) { m_KFFileName = value; }

    const int& GetIndex() const { return m_Index; }
    int& GetIndex() { return m_Index; }
    void SetIndex(const int& value) { m_Index = value; }

    const int& GetNumTransitions() const { return m_NumTransitions; }
    int& GetNumTransitions() { return m_NumTransitions; }
    void SetNumTransitions(const int& value) { m_NumTransitions = value; }

    const std::vector<Transition>& GetTransitions() const { return m_Transitions; }
    std::vector<Transition>& GetTransitions() { return m_Transitions; }
    void SetTransitions(const std::vector<Transition>& value) { m_Transitions = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
