#ifndef SHIFTREGISTERTESTER_HPP
#define SHIFTREGISTERTESTER_HPP

#include "devicetester.hpp"
#include "avrinputoutput.hpp"
#include "avrpin.hpp"

template< typename Button_,
            typename Led_,
            typename ParallelOutput1_,
            typename ParallelOutput2_,
            typename ParallelOutput3_,
            typename ParallelOutput4_,
            typename ParallelOutput5_,
            typename ParallelOutput6_,
            typename ParallelOutput7_,
            typename Gnd_,
            typename SerialOutput_,
            typename InvertedShiftRegisterClear_,
            typename ShiftRegisterClock_,
            typename ShowRegisterClock_,
            typename InvertedOutputEnable_,
            typename SerialInput_,
            typename ParallelOutput0_,
            typename Vcc_>
struct ShiftRegisterTester : public DeviceTester<Button_,
                                                Led_,
                                                ParallelOutput1_,
                                                ParallelOutput2_,
                                                ParallelOutput3_,
                                                ParallelOutput4_,
                                                ParallelOutput5_,
                                                ParallelOutput6_,
                                                ParallelOutput7_,
                                                Gnd_,
                                                SerialOutput_,
                                                InvertedShiftRegisterClear_,
                                                ShiftRegisterClock_,
                                                ShowRegisterClock_,
                                                InvertedOutputEnable_,
                                                SerialInput_,
                                                ParallelOutput0_,
                                                Vcc_>
{
protected:
    typedef DeviceTester<Button_,
                        Led_,
                        ParallelOutput1_,
                        ParallelOutput2_,
                        ParallelOutput3_,
                        ParallelOutput4_,
                        ParallelOutput5_,
                        ParallelOutput6_,
                        ParallelOutput7_,
                        Gnd_,
                        SerialOutput_,
                        InvertedShiftRegisterClear_,
                        ShiftRegisterClock_,
                        ShowRegisterClock_,
                        InvertedOutputEnable_,
                        SerialInput_,
                        ParallelOutput0_,
                        Vcc_> DeviceTester_;
public:
    // make the pins publically available
    typedef ParallelOutput1_ ParallelOutput1Pin;
    typedef ParallelOutput2_ ParallelOutput2Pin;
    typedef ParallelOutput3_ ParallelOutput3Pin;
    typedef ParallelOutput4_ ParallelOutput4Pin;
    typedef ParallelOutput5_ ParallelOutput5Pin;
    typedef ParallelOutput6_ ParallelOutput6Pin;
    typedef ParallelOutput7_ ParallelOutput7Pin;
    typedef Gnd_ GndPin;
    typedef SerialOutput_ SerialOutputPin;
    typedef InvertedShiftRegisterClear_ InvertedShiftRegisterClearPin;
    typedef ShiftRegisterClock_ ShiftRegisterClockPin;
    typedef ShowRegisterClock_ ShowRegisterClockPin;
    typedef InvertedOutputEnable_ InvertedOutputEnablePin;
    typedef SerialInput_ SerialInputPin;
    typedef ParallelOutput0_ ParallelOutput0Pin;
    typedef Vcc_ VccPin;

    // this will reconfigure the ports - so set the sheftRegister driver after having called this.
    static void initialize()
    {
        DeviceTester_::initialize(AvrInputOutput::INPUT,
                                  AvrInputOutput::INPUT,
                                  AvrInputOutput::INPUT,
                                  AvrInputOutput::INPUT,
                                  AvrInputOutput::INPUT,
                                  AvrInputOutput::INPUT,
                                  AvrInputOutput::INPUT,
                                  AvrInputOutput::OUTPUT_LOW,   // Gnd
                                  AvrInputOutput::INPUT,        // SerialOutput
                                  AvrInputOutput::OUTPUT_HIGH,  // InvertedShiftRegisterClear
                                  AvrInputOutput::OUTPUT_HIGH,  // ShiftRegisterClock
                                  AvrInputOutput::OUTPUT_HIGH,  // ShowRegisterClock
                                  AvrInputOutput::OUTPUT_HIGH,  // InvertedOutputEnable_
                                  AvrInputOutput::OUTPUT_LOW,   // SerialInput
                                  AvrInputOutput::INPUT,
                                  AvrInputOutput::OUTPUT_HIGH   // Vcc
                                  );
    }

    static bool checkOutputEnabled()
    {
        return DeviceTester_::template checkDevicePinPort<InvertedOutputEnable_>(AvrInputOutput::LOW);
    }

    static bool checkInvertedShiftRegisterClearing()
    {
        return DeviceTester_::template checkDevicePinPort<InvertedShiftRegisterClear_>(AvrInputOutput::LOW);
    }

    static bool checkOutputEnable(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPort<InvertedOutputEnable_>(pinState);
    }

    static bool checkInvertedShiftRegisterClear(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPort<InvertedShiftRegisterClear_>(pinState);
    }

    static bool checkShiftRegisterClock(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPort<ShiftRegisterClock_>(pinState);
    }

    static bool checkShowRegisterClock(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPort<ShowRegisterClock_>(pinState);
    }

    static bool checkSerialOutput(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPort<SerialOutput_>(pinState);
    }

    static bool checkSerialInput(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPort<SerialInput_>(pinState);
    }

    static bool checkParallelOutput(uint8_t const expectedBitMask)
    {
        return 0x00 == compareParallelOutputTo(expectedBitMask);
    }

    // Returns an 8-bit bit mask where a 1 denotes mismatch and 0 denotes matching of expectation
    // and measured.
    static uint8_t compareParallelOutputTo(uint8_t const expectedBitMask)
    {
        uint8_t const curBitMask = readParallelOutput();
        uint8_t const unexpectedBitMask = curBitMask ^ expectedBitMask;
        return unexpectedBitMask;
    }

    static uint8_t readParallelOutput()
    {
        // disable interrupts?
        uint8_t currentBitMask = 0x00;
        currentBitMask |= static_cast<uint8_t>(ParallelOutput0_::readPin()) << 0;
        currentBitMask |= static_cast<uint8_t>(ParallelOutput1_::readPin()) << 1;
        currentBitMask |= static_cast<uint8_t>(ParallelOutput2_::readPin()) << 2;
        currentBitMask |= static_cast<uint8_t>(ParallelOutput3_::readPin()) << 3;
        currentBitMask |= static_cast<uint8_t>(ParallelOutput4_::readPin()) << 4;
        currentBitMask |= static_cast<uint8_t>(ParallelOutput5_::readPin()) << 5;
        currentBitMask |= static_cast<uint8_t>(ParallelOutput6_::readPin()) << 6;
        currentBitMask |= static_cast<uint8_t>(ParallelOutput7_::readPin()) << 7;
        // enable interrupts?
        return currentBitMask;
    }

};

#endif // SHIFTREGISTERTESTER_HPP
