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
          typename ParallelOutput0_,
          typename Vcc_,
          typename ShiftRegisterDriver_>
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
                                                 typename ShiftRegisterDriver_::InvertedShiftRegisterClear,
                                                 typename ShiftRegisterDriver_::ShiftRegisterClock,
                                                 typename ShiftRegisterDriver_::ShowRegisterClock,
                                                 typename ShiftRegisterDriver_::InvertedOutputEnable,
                                                 typename ShiftRegisterDriver_::SerialInput,
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
                        typename ShiftRegisterDriver_::InvertedShiftRegisterClear,
                        typename ShiftRegisterDriver_::ShiftRegisterClock,
                        typename ShiftRegisterDriver_::ShowRegisterClock,
                        typename ShiftRegisterDriver_::InvertedOutputEnable,
                        typename ShiftRegisterDriver_::SerialInput,
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
    typedef ShiftRegisterDriver_ ShiftRegisterDriver;
    typedef typename ShiftRegisterDriver_::InvertedShiftRegisterClear InvertedShiftRegisterClearPin;
    typedef typename ShiftRegisterDriver_::ShiftRegisterClock ShiftRegisterClockPin;
    typedef typename ShiftRegisterDriver_::ShowRegisterClock ShowRegisterClockPin;
    typedef typename ShiftRegisterDriver_::InvertedOutputEnable InvertedOutputEnablePin;
    typedef typename ShiftRegisterDriver_::SerialInput SerialInputPin;
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
        return DeviceTester_::template checkDevicePinPort<InvertedOutputEnablePin>(AvrInputOutput::LOW);
    }

    static bool checkInvertedShiftRegisterClearing()
    {
        return DeviceTester_::template checkDevicePinPort<InvertedShiftRegisterClearPin>(AvrInputOutput::LOW);
    }

    static bool checkOutputEnable(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPort<InvertedOutputEnablePin>(pinState);
    }

    static bool checkInvertedShiftRegisterClear(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPort<InvertedShiftRegisterClearPin>(pinState);
    }

    static bool checkShiftRegisterClock(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPort<ShiftRegisterClockPin>(pinState);
    }

    static bool checkShowRegisterClock(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPort<ShowRegisterClockPin>(pinState);
    }

    static bool checkSerialOutput(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPort<SerialOutputPin>(pinState);
    }

    static bool checkSerialInput(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPort<SerialInputPin>(pinState);
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

    static bool test()
    {
        // initialize
        ShiftRegisterTester::initialize();
        ShiftRegisterDriver_::initialize();
        uint8_t data[1] = {0xff};

        ShiftRegisterDriver_::enableOutput();

        data[0] = 0xff;
        ShiftRegisterDriver_::shiftInBits(data);
        ShiftRegisterDriver_::showShiftRegister();
        _delay_ms(1000);

        ShiftRegisterTester::enableLeds();
        _delay_ms(1000);

        if ( ShiftRegisterTester::checkOutputEnabled() )
        {
            data[0] = 0x55;
            ShiftRegisterDriver_::shiftInBits(data);
            ShiftRegisterDriver_::showShiftRegister();
        }


        while (true)
        {
            _delay_ms(500);
            ShiftRegisterDriver_::shiftInBits(data);
            ShiftRegisterDriver_::showShiftRegister();

            if (!ShiftRegisterTester::checkParallelOutput(data[0]))
            {
                data[0] = ShiftRegisterTester::compareParallelOutputTo(data[0]);
                while (true)
                {
                    ShiftRegisterDriver_::shiftInBits(data);
                    ShiftRegisterDriver_::showShiftRegister();
                    _delay_ms(500);
                    data[0] = ~data[0];
                }
            }

            data[0]--;
        }

        return false;
    }

    static void turnOffDevice()
    {
        ShiftRegisterDriver_::turnOff();
        Vcc_::clearPort();
        DeviceTester_::turnOff();
    }

    static void turnOnDevice()
    {
        ShiftRegisterDriver_::turnOn();
        Vcc_::setPort();
        DeviceTester_::turnOn();
    }

};


#endif // SHIFTREGISTERTESTER_HPP
