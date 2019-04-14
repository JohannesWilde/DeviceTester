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
        DeviceTester_::initialize(AvrInputOutput::INPUT_PULLUP, // use internal pullups as to have a determined state even if the shiftregister output is disabled.
                                  AvrInputOutput::INPUT_PULLUP,
                                  AvrInputOutput::INPUT_PULLUP,
                                  AvrInputOutput::INPUT_PULLUP,
                                  AvrInputOutput::INPUT_PULLUP,
                                  AvrInputOutput::INPUT_PULLUP,
                                  AvrInputOutput::INPUT_PULLUP,
                                  AvrInputOutput::OUTPUT_LOW,   // Gnd
                                  AvrInputOutput::INPUT,        // SerialOutput
                                  AvrInputOutput::OUTPUT_HIGH,  // InvertedShiftRegisterClear
                                  AvrInputOutput::OUTPUT_LOW,   // ShiftRegisterClock
                                  AvrInputOutput::OUTPUT_LOW,   // ShowRegisterClock
                                  AvrInputOutput::OUTPUT_HIGH,  // InvertedOutputEnable_
                                  AvrInputOutput::OUTPUT_LOW,   // SerialInput
                                  AvrInputOutput::INPUT_PULLUP,
                                  AvrInputOutput::OUTPUT_HIGH   // Vcc
                                  );
    }

    static bool checkOutputEnabled()
    {
        return checkOutputEnable(AvrInputOutput::LOW);
    }

    static bool checkInvertedShiftRegisterClearing()
    {
        return checkInvertedShiftRegisterClear(AvrInputOutput::LOW);
    }

    static bool checkOutputEnable(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPin<InvertedOutputEnablePin>(pinState);
    }

    static bool checkInvertedShiftRegisterClear(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPin<InvertedShiftRegisterClearPin>(pinState);
    }

    static bool checkShiftRegisterClock(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPin<ShiftRegisterClockPin>(pinState);
    }

    static bool checkShowRegisterClock(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPin<ShowRegisterClockPin>(pinState);
    }

    static bool checkSerialOutput(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPin<SerialOutputPin>(pinState);
    }

    static bool checkSerialInput(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPin<SerialInputPin>(pinState);
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

    struct TestResult : DeviceTester_::TestResult
    {
        TestResult () :
            DeviceTester_::TestResult(),
            disableOutput(false),
            enableOutput(false),
            serialOutput(false),
            showShiftRegister(false),
            clearShiftRegister(false),
            turnOff(false),
            turnOn(false),
            parallelOutput0(false),
            parallelOutput1(false),
            parallelOutput2(false),
            parallelOutput3(false),
            parallelOutput4(false),
            parallelOutput5(false),
            parallelOutput6(false),
            parallelOutput7(false)
        {
            // intentionally left empty
        }

        bool disableOutput : 1;
        bool enableOutput : 1;
        bool serialOutput : 1;
        bool showShiftRegister : 1;
        bool clearShiftRegister : 1;
        bool turnOff : 1;
        bool turnOn : 1;
        bool parallelOutput0 : 1;
        bool parallelOutput1 : 1;
        bool parallelOutput2 : 1;
        bool parallelOutput3 : 1;
        bool parallelOutput4 : 1;
        bool parallelOutput5 : 1;
        bool parallelOutput6 : 1;
        bool parallelOutput7 : 1;
    };

    static TestResult test()
    {
        // test result
        TestResult testResult;

        // initialize
        initialize();
        ShiftRegisterDriver_::initialize();

        testResult.disableOutput = testDisableOutput();

        testResult.enableOutput = testEnableOutput();

        testResult.serialOutput = testSerialOutput();

        testResult.showShiftRegister = testShowShiftRegister();

        testResult.clearShiftRegister = testShiftRegisterClear();

        uint8_t const failedPins = testParallelOutput();
        testResult.parallelOutput0 = ((failedPins & (0x01 << 0)) == 0) ? true : false;
        testResult.parallelOutput1 = ((failedPins & (0x01 << 1)) == 0) ? true : false;
        testResult.parallelOutput2 = ((failedPins & (0x01 << 2)) == 0) ? true : false;
        testResult.parallelOutput3 = ((failedPins & (0x01 << 3)) == 0) ? true : false;
        testResult.parallelOutput4 = ((failedPins & (0x01 << 4)) == 0) ? true : false;
        testResult.parallelOutput5 = ((failedPins & (0x01 << 5)) == 0) ? true : false;
        testResult.parallelOutput6 = ((failedPins & (0x01 << 6)) == 0) ? true : false;
        testResult.parallelOutput7 = ((failedPins & (0x01 << 7)) == 0) ? true : false;

        testResult.turnOff = testTurnOff();

        testResult.turnOn = testTurnOn();

        // set test success
        if (testResult.disableOutput &&
                testResult.enableOutput &&
                testResult.serialOutput &&
                testResult.showShiftRegister &&
                testResult.clearShiftRegister &&
                testResult.turnOff &&
                testResult.turnOn &&
                testResult.parallelOutput0 &&
                testResult.parallelOutput1 &&
                testResult.parallelOutput2 &&
                testResult.parallelOutput3 &&
                testResult.parallelOutput4 &&
                testResult.parallelOutput5 &&
                testResult.parallelOutput6 &&
                testResult.parallelOutput7)
        {
            testResult.success = true;
        }

        // finally turn the device off
        turnOffDevice();
        return testResult;
    }

    static void turnOffDevice()
    {
        ParallelOutput0_::clearPort();
        ParallelOutput1_::clearPort();
        ParallelOutput2_::clearPort();
        ParallelOutput3_::clearPort();
        ParallelOutput4_::clearPort();
        ParallelOutput5_::clearPort();
        ParallelOutput6_::clearPort();
        ParallelOutput7_::clearPort();
        ShiftRegisterDriver_::turnOff();
        Vcc_::clearPort();
        DeviceTester_::turnOffDevice();
    }

    static void turnOnDevice()
    {
        DeviceTester_::turnOnDevice();
        Vcc_::setPort();
        ShiftRegisterDriver_::turnOn();
        ParallelOutput0_::setPort();
        ParallelOutput1_::setPort();
        ParallelOutput2_::setPort();
        ParallelOutput3_::setPort();
        ParallelOutput4_::setPort();
        ParallelOutput5_::setPort();
        ParallelOutput6_::setPort();
        ParallelOutput7_::setPort();
    }

    // all test routines expect the shiftRegisterDriver to be initialized,
    // i.e. output disabled, shiftRegisterClear disabled, ShowRegisterClock LOW,
    // ShiftRegisterClock LOW, SerialIn LOW and the register to be 0x00.

    static bool testTurnOn()
    {
        bool testSuccess = false;
        ShiftRegisterDriver_::turnOff();

        ShiftRegisterDriver_::turnOn();
        bool readBack1 = checkOutputEnable(AvrInputOutput::HIGH);
        readBack1 = readBack1 && checkSerialInput(AvrInputOutput::LOW);
        readBack1 = readBack1 && checkShowRegisterClock(AvrInputOutput::LOW);
        readBack1 = readBack1 && checkShiftRegisterClock(AvrInputOutput::LOW);
        readBack1 = readBack1 && checkInvertedShiftRegisterClear(AvrInputOutput::HIGH);
        ShiftRegisterDriver_::enableOutput();
        uint8_t const readBack0 = readParallelOutput();

        if (0x00 == readBack0 && readBack1)
        {
            testSuccess = true;
        }

        ShiftRegisterDriver_::clearShiftRegister();
        ShiftRegisterDriver_::showShiftRegister();
        ShiftRegisterDriver_::disableOutput();
        return testSuccess;
    }

    static bool testTurnOff()
    {
        bool testSuccess = false;
        ShiftRegisterDriver_::enableOutput();

        // first show something to clear
        uint8_t const data = 0xff;
        ShiftRegisterDriver_::shiftInBits(&data);
        ShiftRegisterDriver_::showShiftRegister();
        uint8_t const readBack0 = readParallelOutput();

        ShiftRegisterDriver_::turnOff();
        uint8_t const readBack1 = readParallelOutput();
        bool readBack2 = checkSerialInput(AvrInputOutput::LOW);
        readBack2 = readBack2 && checkOutputEnable(AvrInputOutput::LOW);
        readBack2 = readBack2 && checkShowRegisterClock(AvrInputOutput::LOW);
        readBack2 = readBack2 && checkShiftRegisterClock(AvrInputOutput::LOW);
        readBack2 = readBack2 && checkInvertedShiftRegisterClear(AvrInputOutput::LOW);

        if (0xff == readBack0 && 0x00 == readBack1 && readBack2)
        {
            testSuccess = true;
        }

        ShiftRegisterDriver_::clearShiftRegister();
        ShiftRegisterDriver_::showShiftRegister();
        ShiftRegisterDriver_::turnOn();
        return testSuccess;
    }

    static uint8_t testParallelOutput()
    {
        ShiftRegisterDriver_::enableOutput();

        uint8_t data = 0x00 - 1; // expect underflow here! This will be reverted in the do-while-lopp below.
        uint8_t failedPins = 0x00;
        do
        {
            data++;
            ShiftRegisterDriver_::shiftInBits(&data);
            ShiftRegisterDriver_::showShiftRegister();
            uint8_t const readBack0 = readParallelOutput();
            uint8_t const unexpectedPins = readBack0 ^ data;
            failedPins |= unexpectedPins; // "sum up" failed pin outputs
        }
        while (0xff != data);

        ShiftRegisterDriver_::clearShiftRegister();
        ShiftRegisterDriver_::showShiftRegister();
        ShiftRegisterDriver_::disableOutput();
        return failedPins;
    }

    static bool testShiftRegisterClear()
    {
        bool testSuccess = false;
        ShiftRegisterDriver_::enableOutput();

        // first show something to clear
        uint8_t const data = 0xff;
        ShiftRegisterDriver_::shiftInBits(&data);
        ShiftRegisterDriver_::showShiftRegister();
        uint8_t const readBack0 = readParallelOutput();
        bool const readBack1 = checkSerialOutput(AvrInputOutput::HIGH);

        ShiftRegisterDriver_::clearShiftRegister();
        // serial output should show the clear of the shift register
        uint8_t const readBack2 = readParallelOutput();
        // check that show register unaffected from shift register clear
        bool const readBack3 = checkSerialOutput(AvrInputOutput::LOW);

        // check shift register clear
        ShiftRegisterDriver_::showShiftRegister();
        uint8_t const readBack4 = readParallelOutput();
        if ( readBack0 != 0x00 && readBack1 && readBack0 == readBack2 && readBack3 && 0x00 == readBack4)
        {
            testSuccess = true;
        }

        ShiftRegisterDriver_::clearShiftRegister();
        ShiftRegisterDriver_::showShiftRegister();
        ShiftRegisterDriver_::disableOutput();
        return testSuccess;
    }

    static bool testShowShiftRegister()
    {
        bool testSuccess = false;
        ShiftRegisterDriver_::enableOutput();

        uint8_t data = 0xff;
        ShiftRegisterDriver_::shiftInBits(&data);
        ShiftRegisterDriver_::showShiftRegister();
        uint8_t const readBack0 = readParallelOutput();

        data = 0xaa;
        ShiftRegisterDriver_::shiftInBits(&data);
        uint8_t const readBack1 = readParallelOutput();

        ShiftRegisterDriver_::showShiftRegister();
        uint8_t const readBack2 = readParallelOutput();

        if ( readBack0 == readBack1 && readBack1 != readBack2 )
        {
            testSuccess = true;
        }

        ShiftRegisterDriver_::clearShiftRegister();
        ShiftRegisterDriver_::showShiftRegister();
        ShiftRegisterDriver_::disableOutput();
        return testSuccess;
    }

    static bool testDisableOutput()
    {
        bool testSuccess = false;

        ShiftRegisterDriver_::disableOutput();
        uint8_t data = 0x00 - 1;
        bool outputOk = true;
        do
        {
            data++;
            ShiftRegisterDriver_::shiftInBits(&data);
            ShiftRegisterDriver_::showShiftRegister();
            uint8_t const readBack0 = readParallelOutput();
            if (0xff != readBack0) // the internal pullups of the tester lead to HIGH for unconnected shiftregister pins.
            {
                outputOk = false;
            }
        }
        while (0xff != data && outputOk);
        if (outputOk)
        {
            testSuccess = true;
        }

        ShiftRegisterDriver_::clearShiftRegister();
        ShiftRegisterDriver_::showShiftRegister();
        return testSuccess;
    }

    static bool testEnableOutput()
    {
        bool testSuccess = false;
        ShiftRegisterDriver_::disableOutput();
        uint8_t const readBack0 = readParallelOutput();

        uint8_t const data = 0xaa;
        ShiftRegisterDriver_::shiftInBits(&data);
        ShiftRegisterDriver_::showShiftRegister();
        ShiftRegisterDriver_::enableOutput();
        uint8_t const readBack1 = readParallelOutput();
        // the internal pull-ups measuring the parallel outputs lead to 0xff for disabled outputs
        if ( 0xff == readBack0 && 0xaa == readBack1)
        {
            testSuccess = true;
        }

        ShiftRegisterDriver_::disableOutput();
        ShiftRegisterDriver_::clearShiftRegister();
        ShiftRegisterDriver_::showShiftRegister();
        return testSuccess;
    }

    static bool testSerialOutput()
    {
        bool testSuccess = false;

        uint8_t data = 0x00 - 1;
        bool outputOk = true;
        do
        {
            data++;
            // MSB shifted in first
            ShiftRegisterDriver_::shiftInBits(&data);
            // if MSB in data was 1, expect HIGH on SerialOutput
            AvrInputOutput::PinState const expectedState = ((0x80 & data) != 0) ? AvrInputOutput::HIGH : AvrInputOutput::LOW;
            bool const readBack0 = checkSerialOutput(expectedState);
            if (!readBack0)
            {
                outputOk = false;
            }
        }
        while (0xff != data && outputOk);
        if (outputOk)
        {
            testSuccess = true;
        }

        ShiftRegisterDriver_::clearShiftRegister();
        ShiftRegisterDriver_::showShiftRegister();
        return testSuccess;
    }

    static void showTestResult(TestResult const testResult)
    {
        turnOnDevice();
        DeviceTester_::enableLeds();
        ShiftRegisterDriver_::enableOutput();
        uint8_t const dataParallelOutput = static_cast<uint8_t>(
               ((testResult.parallelOutput0 ? 1 : 0) << 0) |
               ((testResult.parallelOutput1 ? 1 : 0) << 1) |
               ((testResult.parallelOutput2 ? 1 : 0) << 2) |
               ((testResult.parallelOutput3 ? 1 : 0) << 3) |
               ((testResult.parallelOutput4 ? 1 : 0) << 4) |
               ((testResult.parallelOutput5 ? 1 : 0) << 5) |
               ((testResult.parallelOutput6 ? 1 : 0) << 6) |
               ((testResult.parallelOutput7 ? 1 : 0) << 7));
        if (0xff != dataParallelOutput)
        {
            uint8_t zero = 0x00;
            while (true)
            {
                ShiftRegisterDriver_::shiftInBits(&dataParallelOutput);
                ShiftRegisterDriver_::showShiftRegister();
                ShiftRegisterDriver_::clearShiftRegister(); // keep SerialOutput_ from blinking
                _delay_ms(500);
                ShiftRegisterDriver_::shiftInBits(&zero);
                ShiftRegisterDriver_::showShiftRegister();
                ShiftRegisterDriver_::clearShiftRegister(); // keep SerialOutput_ from blinking
                _delay_ms(500);
            }
        }
        else
        {
            uint8_t const dataOther = static_cast<uint8_t>(
                                    ((testResult.disableOutput ? 1 : 0) << 0) |
                                    ((testResult.enableOutput ? 1 : 0) << 1) |
                                    ((testResult.serialOutput ? 1 : 0) << 2) |
                                    ((testResult.showShiftRegister ? 1 : 0) << 3) |
                                    ((testResult.clearShiftRegister ? 1 : 0) << 4) |
                                    ((testResult.turnOff ? 1 : 0) << 5) |
                                    ((testResult.turnOn ? 1 : 0) << 6) |
                                    ((testResult.success ? 1 : 0) << 7));
            ShiftRegisterDriver_::shiftInBits(&dataOther);
            ShiftRegisterDriver_::showShiftRegister();
        }
        DeviceTester_::waitForButtonPressAndRelease();
        DeviceTester_::disableLeds();
        ShiftRegisterDriver_::disableOutput();

        turnOffDevice();
    }

};


#endif // SHIFTREGISTERTESTER_HPP
