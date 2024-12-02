#pragma once

#include <cstdint>
#include <string>

#include "Common.hpp"

#include "NiObject.hpp"
#include "NiObject.hpp"
#include "NiObject.hpp"
#include "NiAVObject.hpp"
namespace nejlika::geometry {


class NiPSParticleSystem : public NiAVObject
{
protected:
    /**
     * 0?
     */
    int m_Unknown3;
    std::vector<int> m_Unknown38;
    /**
     * -1?
     */
    int m_Unknown4;
    /**
     * 0?
     */
    int m_Unknown5;
    std::vector<int> m_Unknown39;
    /**
     * 256?
     */
    int m_Unknown6;
    /**
     * 0?
     */
    int m_Unknown7;
    /**
     * 0?
     */
    int m_Unknown8;
    /**
     * 0?
     */
    int m_Unknown9;
    /**
     * 0?
     */
    float m_Unknown10;
    /**
     * 0?
     */
    int m_Unknown11;
    /**
     * Counter?
     */
    int m_Unknown12;
    /**
     * Simulator?
     */
    Pointer<class NiObject*> m_Simulator;
    /**
     * Generator?
     */
    Pointer<class NiObject*> m_Generator;
    /**
     * Simulator?
     */
    int m_Unknown15;
    /**
     * Updater?
     */
    int m_Unknown16;
    /**
     * 1?
     */
    int m_Unknown17;
    /**
     * Emitter?
     */
    Pointer<class NiObject*> m_Emitter;
    /**
     * 0?
     */
    int m_Unknown19;
    /**
     * Spawner?
     */
    int m_Unknown20;
    /**
     * Unknown
     */
    int m_Unknown21;
    /**
     * Unknown
     */
    std::vector<byte> m_Unknown22;
    int m_Unknown27;
    int m_Unknown28;
    int m_Unknown29;
    int m_Unknown30;
    int m_Unknown31;
    int m_Unknown32;
    int m_Unknown33;
    int m_Unknown34;
    byte m_Unknown35;
    /**
     * -1?
     */
    int m_Unknown36;
    short m_Unknown37;

public:
    const int& GetUnknown3() const { return m_Unknown3; }
    int& GetUnknown3() { return m_Unknown3; }
    void SetUnknown3(const int& value) { m_Unknown3 = value; }

    const std::vector<int>& GetUnknown38() const { return m_Unknown38; }
    std::vector<int>& GetUnknown38() { return m_Unknown38; }
    void SetUnknown38(const std::vector<int>& value) { m_Unknown38 = value; }

    const int& GetUnknown4() const { return m_Unknown4; }
    int& GetUnknown4() { return m_Unknown4; }
    void SetUnknown4(const int& value) { m_Unknown4 = value; }

    const int& GetUnknown5() const { return m_Unknown5; }
    int& GetUnknown5() { return m_Unknown5; }
    void SetUnknown5(const int& value) { m_Unknown5 = value; }

    const std::vector<int>& GetUnknown39() const { return m_Unknown39; }
    std::vector<int>& GetUnknown39() { return m_Unknown39; }
    void SetUnknown39(const std::vector<int>& value) { m_Unknown39 = value; }

    const int& GetUnknown6() const { return m_Unknown6; }
    int& GetUnknown6() { return m_Unknown6; }
    void SetUnknown6(const int& value) { m_Unknown6 = value; }

    const int& GetUnknown7() const { return m_Unknown7; }
    int& GetUnknown7() { return m_Unknown7; }
    void SetUnknown7(const int& value) { m_Unknown7 = value; }

    const int& GetUnknown8() const { return m_Unknown8; }
    int& GetUnknown8() { return m_Unknown8; }
    void SetUnknown8(const int& value) { m_Unknown8 = value; }

    const int& GetUnknown9() const { return m_Unknown9; }
    int& GetUnknown9() { return m_Unknown9; }
    void SetUnknown9(const int& value) { m_Unknown9 = value; }

    const float& GetUnknown10() const { return m_Unknown10; }
    float& GetUnknown10() { return m_Unknown10; }
    void SetUnknown10(const float& value) { m_Unknown10 = value; }

    const int& GetUnknown11() const { return m_Unknown11; }
    int& GetUnknown11() { return m_Unknown11; }
    void SetUnknown11(const int& value) { m_Unknown11 = value; }

    const int& GetUnknown12() const { return m_Unknown12; }
    int& GetUnknown12() { return m_Unknown12; }
    void SetUnknown12(const int& value) { m_Unknown12 = value; }

    const Pointer<class NiObject*>& GetSimulator() const { return m_Simulator; }
    Pointer<class NiObject*>& GetSimulator() { return m_Simulator; }
    void SetSimulator(const Pointer<class NiObject*>& value) { m_Simulator = value; }

    const Pointer<class NiObject*>& GetGenerator() const { return m_Generator; }
    Pointer<class NiObject*>& GetGenerator() { return m_Generator; }
    void SetGenerator(const Pointer<class NiObject*>& value) { m_Generator = value; }

    const int& GetUnknown15() const { return m_Unknown15; }
    int& GetUnknown15() { return m_Unknown15; }
    void SetUnknown15(const int& value) { m_Unknown15 = value; }

    const int& GetUnknown16() const { return m_Unknown16; }
    int& GetUnknown16() { return m_Unknown16; }
    void SetUnknown16(const int& value) { m_Unknown16 = value; }

    const int& GetUnknown17() const { return m_Unknown17; }
    int& GetUnknown17() { return m_Unknown17; }
    void SetUnknown17(const int& value) { m_Unknown17 = value; }

    const Pointer<class NiObject*>& GetEmitter() const { return m_Emitter; }
    Pointer<class NiObject*>& GetEmitter() { return m_Emitter; }
    void SetEmitter(const Pointer<class NiObject*>& value) { m_Emitter = value; }

    const int& GetUnknown19() const { return m_Unknown19; }
    int& GetUnknown19() { return m_Unknown19; }
    void SetUnknown19(const int& value) { m_Unknown19 = value; }

    const int& GetUnknown20() const { return m_Unknown20; }
    int& GetUnknown20() { return m_Unknown20; }
    void SetUnknown20(const int& value) { m_Unknown20 = value; }

    const int& GetUnknown21() const { return m_Unknown21; }
    int& GetUnknown21() { return m_Unknown21; }
    void SetUnknown21(const int& value) { m_Unknown21 = value; }

    const std::vector<byte>& GetUnknown22() const { return m_Unknown22; }
    std::vector<byte>& GetUnknown22() { return m_Unknown22; }
    void SetUnknown22(const std::vector<byte>& value) { m_Unknown22 = value; }

    const int& GetUnknown27() const { return m_Unknown27; }
    int& GetUnknown27() { return m_Unknown27; }
    void SetUnknown27(const int& value) { m_Unknown27 = value; }

    const int& GetUnknown28() const { return m_Unknown28; }
    int& GetUnknown28() { return m_Unknown28; }
    void SetUnknown28(const int& value) { m_Unknown28 = value; }

    const int& GetUnknown29() const { return m_Unknown29; }
    int& GetUnknown29() { return m_Unknown29; }
    void SetUnknown29(const int& value) { m_Unknown29 = value; }

    const int& GetUnknown30() const { return m_Unknown30; }
    int& GetUnknown30() { return m_Unknown30; }
    void SetUnknown30(const int& value) { m_Unknown30 = value; }

    const int& GetUnknown31() const { return m_Unknown31; }
    int& GetUnknown31() { return m_Unknown31; }
    void SetUnknown31(const int& value) { m_Unknown31 = value; }

    const int& GetUnknown32() const { return m_Unknown32; }
    int& GetUnknown32() { return m_Unknown32; }
    void SetUnknown32(const int& value) { m_Unknown32 = value; }

    const int& GetUnknown33() const { return m_Unknown33; }
    int& GetUnknown33() { return m_Unknown33; }
    void SetUnknown33(const int& value) { m_Unknown33 = value; }

    const int& GetUnknown34() const { return m_Unknown34; }
    int& GetUnknown34() { return m_Unknown34; }
    void SetUnknown34(const int& value) { m_Unknown34 = value; }

    const byte& GetUnknown35() const { return m_Unknown35; }
    byte& GetUnknown35() { return m_Unknown35; }
    void SetUnknown35(const byte& value) { m_Unknown35 = value; }

    const int& GetUnknown36() const { return m_Unknown36; }
    int& GetUnknown36() { return m_Unknown36; }
    void SetUnknown36(const int& value) { m_Unknown36 = value; }

    const short& GetUnknown37() const { return m_Unknown37; }
    short& GetUnknown37() { return m_Unknown37; }
    void SetUnknown37(const short& value) { m_Unknown37 = value; }


    void Read(nejlika::Reader& reader, uint32_t version, uint32_t user, uint32_t arg);
    void Write(nejlika::Writer& writer, uint32_t version, uint32_t user, uint32_t arg) const;

};

}
