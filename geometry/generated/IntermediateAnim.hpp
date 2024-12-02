#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "SizedString.hpp"
namespace nejlika::geometry {


class IntermediateAnim : public Construct
{
protected:
    int m_UnknownInt;
    SizedString m_Event;

public:
    const int& GetUnknownInt() const { return m_UnknownInt; }
    int& GetUnknownInt() { return m_UnknownInt; }
    void SetUnknownInt(const int& value) { m_UnknownInt = value; }

    const SizedString& GetEvent() const { return m_Event; }
    SizedString& GetEvent() { return m_Event; }
    void SetEvent(const SizedString& value) { m_Event = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
