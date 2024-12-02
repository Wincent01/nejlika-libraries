#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "string.hpp"
#include "BSTreadTransformData.hpp"
#include "BSTreadTransformData.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-specific node.
 *         
 */
class BSTreadTransform : public Construct
{
protected:
    /**
     * Name of affected node?
     */
    string m_Name;
    /**
     * Transform data.
     */
    BSTreadTransformData m_Transform1;
    /**
     * Transform data.
     */
    BSTreadTransformData m_Transform2;

public:
    const string& GetName() const { return m_Name; }
    string& GetName() { return m_Name; }
    void SetName(const string& value) { m_Name = value; }

    const BSTreadTransformData& GetTransform1() const { return m_Transform1; }
    BSTreadTransformData& GetTransform1() { return m_Transform1; }
    void SetTransform1(const BSTreadTransformData& value) { m_Transform1 = value; }

    const BSTreadTransformData& GetTransform2() const { return m_Transform2; }
    BSTreadTransformData& GetTransform2() { return m_Transform2; }
    void SetTransform2(const BSTreadTransformData& value) { m_Transform2 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
