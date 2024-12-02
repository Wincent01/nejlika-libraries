#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "BSTreadTransform.hpp"
#include "NiFloatData.hpp"
#include "NiInterpolator.hpp"
namespace nejlika::geometry {


/**
 * 
 *         Bethesda-specific node.
 *         
 */
class BSTreadTransfInterpolator : public NiInterpolator
{
protected:
    /**
     * Unknown.
     */
    int m_NumTreadTransforms;
    /**
     * Unknown.
     */
    std::vector<BSTreadTransform> m_TreadTransforms;
    /**
     * Unknown float data.
     */
    Pointer<class NiFloatData*> m_Data;

public:
    const int& GetNumTreadTransforms() const { return m_NumTreadTransforms; }
    int& GetNumTreadTransforms() { return m_NumTreadTransforms; }
    void SetNumTreadTransforms(const int& value) { m_NumTreadTransforms = value; }

    const std::vector<BSTreadTransform>& GetTreadTransforms() const { return m_TreadTransforms; }
    std::vector<BSTreadTransform>& GetTreadTransforms() { return m_TreadTransforms; }
    void SetTreadTransforms(const std::vector<BSTreadTransform>& value) { m_TreadTransforms = value; }

    const Pointer<class NiFloatData*>& GetData() const { return m_Data; }
    Pointer<class NiFloatData*>& GetData() { return m_Data; }
    void SetData(const Pointer<class NiFloatData*>& value) { m_Data = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
