#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

namespace nejlika::geometry {


class ExtraMeshDataEpicMickey2 : public Construct
{
protected:
    int m_Start;
    int m_End;
    std::vector<short> m_UnknownShorts;

public:
    const int& GetStart() const { return m_Start; }
    int& GetStart() { return m_Start; }
    void SetStart(const int& value) { m_Start = value; }

    const int& GetEnd() const { return m_End; }
    int& GetEnd() { return m_End; }
    void SetEnd(const int& value) { m_End = value; }

    const std::vector<short>& GetUnknownShorts() const { return m_UnknownShorts; }
    std::vector<short>& GetUnknownShorts() { return m_UnknownShorts; }
    void SetUnknownShorts(const std::vector<short>& value) { m_UnknownShorts = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
